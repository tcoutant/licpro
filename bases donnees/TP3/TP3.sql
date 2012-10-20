create table magazine(
	nom varchar(20) primary key,
	prix numeric(4,2)
);
create table client(
	numero integer primary key,
	nom varchar(20),
	prenom varchar(20),
	ville varchar(20)
);
create table abonnement(
	numeroclient integer,
	nommagazine varchar(20),
	echeance integer,
	constraint akey primary key(numeroclient, nommagazine),
	constraint fk_client foreign key(numeroclient) references client(numero),
	constraint fk_magazine foreign key(nommagazine) references magazine(nom)
);
create table invendus(
	nommagazine varchar(20) references magazine(nom),
	numeromag integer,
	stock integer,
	constraint ikey primary key(nommagazine, numeromag)
);
create table commande(
	numeroclient integer references client(numero),
	nommagazine varchar(20) references magazine(nom),
	numeromag integer,
	constraint cokey primary key(numeroclient, nommagazine, numeromag)
);

describe client;

-- Insertion
insert into magazine values ('BD Hebdo', 2);
insert into magazine values ('Oraclemag', 4);
insert into client values (5, 'Patrick', 'Rudoux', 'Angers');
insert into client values (8, 'Roland', 'Lebrun', 'Nantes');
insert into client values (10, 'Herve', 'Lenoir', 'Angers');
insert into abonnement values (5, 'Oraclemag', 27);
insert into abonnement values (8, 'Oraclemag', 30);
insert into abonnement values (8, 'BD Hebdo', 78);
insert into commande values (5, 'BD Hebdo', 4);
insert into commande values (8, 'BD Hebdo', 60);
insert into commande values (10, 'BD Hebdo', 60);
insert into commande values (10, 'BD Hebdo', 61);
insert into invendus values ('BD Hebdo', 60, 10);
insert into invendus values ('BD Hebdo', 61, 3);
insert into invendus values ('Oraclemag', 22, 6);

--1/ dans combien de villes y a t'il des clients qui ont commandé
-- (au moins) un ancien numero de BD Hebdo?
SELECT ville , count(distinct ville) as "nb commandé"
FROM client JOIN commande on (client.numero = commande.numeroclient)
where commande.nommagazine='BD Hebdo';

--2/ trier les magazines par le nombre d'abonnés (de celui qui en
-- a le plus à celui qui en a le moins
SELECT nommagazine, count(*) as nbabo
FROM abonnement 
GROUP BY nommagazine Order by nbabo desc;

--3/ quelq sont les numeros des clients qui ont commandé (au moins)
-- un exemplaire d'un magazine auquel ils sont abonnés
SELECT numeroclient 
from abonnement join commande using(nommagazine, numeroclient);

--4/ quels sont les noms des clients qui habitent nantes et qui sont
-- abonnés à 2 magazines
SELECT nom, prenom 
FROM client JOIN abonnement on client.numero=abonnement.numeroclient
WHERE client.ville='Nantes'
GROUP BY client.numero
HAVING count(*)>=2;

--5/ quels sont les noms des clients qui sont abonnés à un magazine
-- sans jamais avoir commandé un exemplaire de ce magazine
SELECT nom, prenom 
FROM client JOIN abonnement on client.numero=abonnement.numeroclient
WHERE (numero, nommagazine) NOT IN (SELECT numeroclient, nommagazine 
				FROM commande);

--ou
SELECT nom
FROM client JOIN abonnement
		ON(client.numero=abonnement.numeroclient)
	LEFT JOIN commande
		ON((abonnement.numeroclient = commande.numeroclient) 
		and (abonnement.nommagazine = commande.nommagazine))
GROUP BY numero
HAVING count(commande.nommagazine)=0;

--ou
SELECT nom, prenom 
FROM client JOIN abonnement ON (client.numero = abonnement.numeroclient)
WHERE numero not in (
	SELECT numeroclient 
	from abonnement join commande 
	using(nommagazine, numeroclient));

--6/ Quelle est la somme d'argent reçue des ventes d'anciens numeros
SELECT SUM(prix) as recette 
FROM commande JOIN magazine on commande.nommagazine=magazine.nom;

--7 quels sont les noms des clients qui sont abonnés à (au moins)un meme 
-- magazine que Patrick Rudoux et qui habite la meme ville
select c2.nom, c2.prenom
from client c1, abonnement a1, client c2, abonnement a2
where c1.nom='Patrick' and c1.prenom='Rudoux' and a1.numeroclient=c1.numero
		and;     // à terminer

-- ou		
select c2.nom, c2.prenom
from (client c1 join abonnement a1 on a1.numeroclient=c1.numero) join
(client c2 join abonnement a2 on a2.numeroclient=c2.numero) on 
c2.ville=c1.ville
where c1.nom='Patrick' and c1.prenom='Rudoux';

--8 quel est le nom du client qui a effecté le plus grand nombre de
-- commandes d'anciens numeros
select nom, prenom, count(*) as c
from client join commande on client.numero=commande.numeroclient
group by numero
order by c desc
limit 1; //

-- ou
select nom,prenom, c from
  (select numeroclient, count(*) as c from commande 
  group by numeroclient having count(*)=(
	select max(s) from (
	  select count(*) as s 
	  from commande group by numeroclient) temp)
  ) t join client on numero=numeroclient;

