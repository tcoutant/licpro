DROP TABLE Client;
DROP TABLE Sinistre;
DROP TABLE Vehicule;

--2
CREATE TABLE Client(
	numsecu numeric(13,0) PRIMARY KEY,
	nomcli varchar(25),
	prenomcli varchar(25)
);

CREATE TABLE Vehicule(
	numimmac varchar(8) PRIMARY KEY,
	modele varchar(25),
	anneemec numeric(4,0),
	numsecu numeric(13,0),
	FOREIGN KEY (numsecu) REFERENCES Client(numsecu)
);

CREATE TABLE Sinistre(
	numsin numeric(6) PRIMARY KEY,
	montantdegat numeric(7,2),
	responsabilite numeric(3,0),
	numsecu numeric(13,0),
	numimmac varchar(8),
	FOREIGN KEY(numsecu) REFERENCES Client(numsecu),
	FOREIGN KEY(numimmac) REFERENCES Vehicule(numimmac),
	CONSTRAINT ck_resp CHECK(responsabilite BETWEEN 0 AND 100)
);

ALTER TABLE Sinistre 
ADD CONSTRAINT ck_resp CHECK(responsabilite <= 100);

INSERT INTO Client VALUES
	(1710549123456,'Rudoux','Patrick'),
	(1670649234567,'Lenoir','Herve'),
	(2740749345678,'Drabert','Severine');

INSERT INTO Vehicule VALUES
	('1234TZ49','Twingo',2000,1710549123456),
	('2345RA49','R21',1980,1670649234567),
	('3456RZ49','Supercinq',1984,1710549123456);

INSERT INTO Sinistre VALUES
	(200201,1000,0,1670649234567,'2345RA49'),
	(200202,null,50,1710549123456,'1234TZ49');
	
UPDATE Vehicule
SET numimmac='4321TZ49'
WHERE numimmac='1234TZ49';

UPDATE Vehicule
SET anneemec=anneemec+1
WHERE anneemec>1983;

SELECT *
FROM Vehicule
WHERE numsecu = 1710549123456;

SELECT *
FROM Vehicule
WHERE numsecu = 2740749345678;

SELECT numsecu
FROM Client
WHERE nomcli = 'Rudoux';
--1ERE possibilite
SELECT V.numimmac,nomcli,prenomcli
FROM Vehicule V NATURAL JOIN Client;
-- 2eme possibilite pas tres interessante
SELECT V.numimmac,nomcli,prenomcli
FROM Vehicule V,Client C
WHERE V.numsecu = C.numsecu;
--"eme possibilite
SELECT V.numimmac,nomcli,prenomcli
FROM Vehicule V JOIN Client C ON V.numsecu = C.numsecu;

SELECT V.*
FROM Vehicule V NATURAL JOIN Client
WHERE nomcli = 'Rudoux';

SELECT V.* ---* pour tous les champs de la table V
FROM Vehicule V,Client C
WHERE V.numsecu = C.numsecu
AND  nomcli = 'Rudoux';

SELECT numsin
FROM Sinistre
WHERE montantdegat IS NULL;

SELECT numsin,nomcli,prenomcli
FROM Client NATURAL JOIN Sinistre
WHERE numsin BETWEEN 200110 AND 200201;

DELETE FROM Sinistre WHERE numsin = 200202;

DELETE FROM Client WHERE nomcli LIKE '%o%';

TRUNCATE Sinistre;

-- Compter le nombre de véhicules qu'à chaque assuré
SELECT C.numsecu, count(V.*)
FROM Client C NATURAL JOIN Vehicule 
GROUP BY numsecu;
