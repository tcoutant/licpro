drop table IF EXISTS Segment;
drop table IF EXISTS Type;
drop table IF EXISTS Salle;
drop table IF EXISTS Logiciel;
drop table IF EXISTS Poste;
drop table IF EXISTS Installer;


CREATE TABLE Segment
	(indIP      varchar(11),
	 nomSegment varchar(20) NOT NULL,
	 etage TINYINT(1),
	 CONSTRAINT pk_Segment PRIMARY KEY (indIP)) ENGINE = InnoDB;

CREATE TABLE Salle
	(nSalle     varchar(7),
	 nomSalle   varchar(20) NOT NULL,
	 nbPoste    TINYINT(2),
	 indIP      varchar(11),
	 CONSTRAINT pk_salle PRIMARY KEY (nSalle),
	 CONSTRAINT fk_Salle_indIP_Segment FOREIGN KEY(indIP) REFERENCES Segment(indIP)) ENGINE = InnoDB;

CREATE TABLE Types
	(typeLP   varchar(9), 
    nomType varchar(20),
	 CONSTRAINT pk_types PRIMARY KEY(typeLP)) ENGINE = InnoDB;

CREATE TABLE Poste
	(nPoste     varchar(7),
	 nomPoste   varchar(20) NOT NULL,
	 indIP      varchar(11),
	 ad         varchar(3),
	 typePoste  varchar(9),
	 nSalle     varchar(7),
	 CONSTRAINT pk_Poste PRIMARY KEY (nPoste),
 CONSTRAINT ck_ad    CHECK (ad BETWEEN '000' AND '255'),
	 INDEX (indIP),
 CONSTRAINT fk_P_i_S FOREIGN KEY(indIP) REFERENCES Segment(indIP),
 INDEX (nSalle),
 CONSTRAINT fk_P_n_S FOREIGN KEY(nSalle) REFERENCES Salle(nSalle),
 INDEX (typePoste),
 CONSTRAINT fk_P_t_T FOREIGN KEY(typePoste) REFERENCES Types(typeLP)
	) ENGINE = InnoDB;

CREATE TABLE Logiciel
	(nLog       varchar(5),
	 nomLog     varchar(20) NOT NULL,
	 dateAch    DATETIME,
	 version    varchar(7),
	 typeLog    varchar(9),
	 prix       DECIMAL(6,2),
	 CONSTRAINT pk_Logiciel PRIMARY KEY (nLog),
	 CONSTRAINT ck_prix     CHECK (prix >= 0),
	 CONSTRAINT fk_Logiciel_typeLog_Types FOREIGN KEY(typeLog) REFERENCES Types(typeLP)) ENGINE = InnoDB;

CREATE TABLE Installer
	(nPoste     varchar(7),
	 nLog       varchar(5),
	 numIns     INTEGER(5) AUTO_INCREMENT,
	 dateIns    TIMESTAMP DEFAULT NOW(),
	 delai      SMALLINT,
	 CONSTRAINT pk_Installer PRIMARY KEY(numIns),
 INDEX (nPoste),
	 CONSTRAINT fk_Inst_nPoste_Poste FOREIGN KEY(nPoste) REFERENCES Poste(nPoste),
INDEX (nLog),
	 CONSTRAINT fk_Installer_nLog_Logiciel FOREIGN KEY(nLog) REFERENCES Logiciel(nLog))
ENGINE = InnoDB;


DELETE FROM Types;
DELETE FROM Installer;
DELETE FROM Poste;
DELETE FROM Salle;
DELETE FROM Segment;
DELETE FROM Logiciel;



INSERT INTO Types VALUES ('TX',  'Terminal X-Window');
INSERT INTO Types VALUES ('UNIX','SystÃ¨me Unix');
INSERT INTO Types VALUES ('PCNT','PC Windows  NT');
INSERT INTO Types VALUES ('PCWS','PC Windows');
INSERT INTO Types VALUES ('NC',  'Network Computer');

INSERT INTO Segment VALUES ('130.120.80','Brin RDC',NULL);
INSERT INTO Segment VALUES ('130.120.81','Brin 1er  Ã©tage',NULL);
INSERT INTO Segment VALUES ('130.120.82','Brin 2Ã¨me Ã©tage',NULL);

INSERT INTO Salle VALUES ('s01','Salle 1',3,'130.120.80');
INSERT INTO Salle VALUES ('s02','Salle 2',2,'130.120.80');
INSERT INTO Salle VALUES ('s03','Salle 3',2,'130.120.80');
INSERT INTO Salle VALUES ('s11','Salle 11',2,'130.120.81');
INSERT INTO Salle VALUES ('s12','Salle 12',1,'130.120.81');
INSERT INTO Salle VALUES ('s21','Salle 21',2,'130.120.82');
INSERT INTO Salle VALUES ('s22','Salle 22',0,'130.120.82');
INSERT INTO Salle VALUES ('s23','Salle 23',0,'130.120.82');

INSERT INTO Poste VALUES ('p1','Poste 1','130.120.80','01','TX','s01');
INSERT INTO Poste VALUES ('p2','Poste 2','130.120.80','02','UNIX','s01');
INSERT INTO Poste VALUES ('p3','Poste 3','130.120.80','03','TX','s01');
INSERT INTO Poste VALUES ('p4','Poste 4','130.120.80','04','PCWS','s02');
INSERT INTO Poste VALUES ('p5','Poste 5','130.120.80','05','PCWS','s02');
INSERT INTO Poste VALUES ('p6','Poste 6','130.120.80','06','UNIX','s03');
INSERT INTO Poste VALUES ('p7','Poste 7','130.120.80','07','TX','s03');
INSERT INTO Poste VALUES ('p8','Poste 8','130.120.81','01','UNIX','s11');
INSERT INTO Poste VALUES ('p9','Poste 9','130.120.81','02','TX','s11');
INSERT INTO Poste VALUES ('p10','Poste 10','130.120.81','03','UNIX','s12');
INSERT INTO Poste VALUES ('p11','Poste 11','130.120.82','01','PCNT','s21');
INSERT INTO Poste VALUES ('p12','Poste 12','130.120.82','02','PCWS','s21');

INSERT INTO Logiciel VALUES ('log1','Oracle 6',   '1995-05-13','6.2','UNIX',3000);
INSERT INTO Logiciel VALUES ('log2','Oracle 8',   '1999-09-15','8i','UNIX',5600);
INSERT INTO Logiciel VALUES ('log3','SQL Server', '1998-04-12','7','PCNT',3000);
INSERT INTO Logiciel VALUES ('log4','Front Page', '1997-06-03','5','PCWS',500);
INSERT INTO Logiciel VALUES ('log5','WinDev',     '1997-05-12','5','PCWS',750);
INSERT INTO Logiciel VALUES ('log6','SQL*Net',     NULL, '2.0','UNIX',500);
INSERT INTO Logiciel VALUES ('log7','I. I. S.',   '2002-04-12','2','PCNT',900);
INSERT INTO Logiciel VALUES ('log8','DreamWeaver','2003-09-21','2.0','PCNT',1400);


INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p2', 'log1', '2003-05-15',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p2', 'log2', '2003-09-17',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p4', 'log5',  NULL,NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p6', 'log6', '2003-05-20',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p6', 'log1', '2003-05-20',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p8', 'log1', '2003-07-15',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p8', 'log2', '2003-05-19',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p8', 'log6', '2003-05-20',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p11','log3', '2003-04-20',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p12','log4', '2003-04-20',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p11','log7', '2003-04-20',NULL);
INSERT INTO Installer (nPoste,nLog,dateIns,delai) VALUES ('p7', 'log4', '2002-04-01',NULL);


SELECT * FROM Segment;
SELECT * FROM Salle;
SELECT * FROM Poste;
SELECT * FROM Logiciel;
SELECT * FROM Installer;
SELECT * FROM Types;

-- 2.1 nom des logiciels unix
select nomLog from Logiciel where typeLog="UNIX";

-- 2.2 nom, adresse IP, nimero de salle des postes du segment 130.120.80
--tries par numero de salle decroissant
select nomPoste,concat(indIP,".",ad) as IP,nSalle from Poste
 where indIP='130.120.80' ORDER BY nSalle desc;
 
 -- 2.3 numeros des postes qui hebergent le logiciel log1
 select nPoste from Installer
 where nLog='log1';
 -- 2.4 pour chaque poste,le nombre de logiciel installés
 select nPoste, COUNT(nLog) AS nbLogiciels FROM
 Installer GROUP BY nPoste;
 
 -- 2.5 pour chaque logiciel le ombre d'installations sur des postes differents
select nLog, COUNT(DISTINCT nPoste) AS nbInstallations
FROM Installer GROUP BY nLog;

-- 2.6 plus recente date d'achat d'un logiciel
select MAX(dateAch) from Logiciel;

-- 2.7 numeros des postes hebergeant 2 logiciels
select nPoste from Installer GROUP BY nPoste
HAVING COUNT(*)=2;

-- 2.8 Type des postes non recenses dans le parc informatique
SELECT  nomType from Types where typeLP NOT IN (select distinct typePoste from Poste);
-- le distinct est ici pour enlever les doublons

--2.9 types des postes de travail n'etant pas des types de logiciels
select  distinct nomType 
from Types join Poste on Types.typeLP=Poste.typePoste
where Poste.typePoste not in (select typeLog from Logiciel);

-- 2.10 adresse IP completes des postes qui hebergent le logiciel 'oracle8'
select concat(Poste.indIP,".",Poste.ad) as adresseIP from Poste natural join
Installer natural join Logiciel where Logiciel.nomLog='Oracle 8';



-- 2.11 noms des salles oul'on peut trouver au moins un poste hebergeant le logiciel oracle8
select nomSalle from Salle where nSalle in (select distinct nSalle from Poste natural join
Installer natural join Logiciel where Logiciel.nomLog='Oracle 8');

-- 2.12 noms des postes ayant les memes logiciels que le poste 'p6'
select p.nomPoste from Poste p where not exists(
 select null from Installer where nPoste='p6' and nLog not in (
  select nLog from Installer where nPoste = p.nPoste
  )
 ) and p.nPoste <>'p6';
 
 -- 2.13 nom des postes ayant exactement les mêmes logiciels que le poste 'p7'
 select p.nomPoste from Poste p where not exists(
  select null from Installer where nPoste='p7' and nLog not in (
    select nLog from Installer where nPoste = p.nPoste
  )
 ) 
 AND not exists(
  select null from Installer where nPoste=p.Nposte and nLog not in (
    select nLog from Installer where nPoste = 'p7'
  )
 ) 
 and p.nPoste <>'p7';
 
 -- 3.1 creer la vue SallePrix a faire!!
 create view SallePrix (nSalle,nomPoste,NbPoste, prixLocation) as
 select nSalle,nomPoste,count(nbPoste),count(nbPoste)*100
 from Salle;
 
 -- 3.2  a faire!!
 create view SallePoste as 
 select nomSalle,nomPoste,CONCAT(indIP,'.',ad) as IP,nomType
 from Salle natural join Poste join Type on (Poste.TypePoste=Types.typeLP)
 group by ;
 
 -- creer une procedure qui augmente le prix des logiciels d'un pourcentage donné
 -- Tora ne reconnait pas delimiter, il faut donc faire cette commande dans le terminal
 delimiter |
 create procedure augmentation (in pourcentage numeric)
 BEGIN
 update Logiciel set prix=prix * (1 + pourcentage/100);
 end|
 delimiter ;
 call augmentation(10);
 
-- ecrire ue procedure stockée qui CalculeTemps qui permet de connaitre, 
 -- pour chaque logiciel installe le temp écoulé entre
 -- la date d'achat et date d'installation A faire!!
 delimiter |
 create procedure CalculeTemps()
 begin