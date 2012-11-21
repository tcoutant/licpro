Create table membre(
numero integer primary key auto_increment,
nom varchar (20),
prenom varchar(20),
superieur integer);
create table projet(
nom varchar(10) primary key,
priorite numeric(2),
dirigeant integer,
echeance date);
create table affectation(
employe integer,
projet varchar(10),
constraint akey primary key(employe,projet));
describe membre;
describe projet;
describe affectation;
select*from membre;
select*from projet;
select*from affectation;
drop table affectation;
insert into membre (nom,prenom, superieur) 
values ('Karamazof','Serge',NULL),('Deray','Odile',1),('Gilet','Gilles',2),('Simon','Jeremi',1),('Lamar','Andre',2);
insert into projet (nom,priorite,dirigeant,echeance)
values ('PRJ1',5,2,'2006-10-14'),('PRJ2',7,5,'2007-04-07');
insert into affectation (employe,projet)
values (1,'PRJ1'),(3,'PRJ1'),(4,'PRJ1'),(5,'PRJ1'),(5,'PRJ2');

--3.1
alter table membre
add salaire numeric(10,2);
--3.2
update membre set salaire = 10000-1000*numero;
--3.3
alter table projet modify priorite numeric(4);
--3.4
update projet set priorite = priorite*100;
--3.5
select*from membre order by salaire limit 1; -- pour trouver celui qui a le salire le mlus faible
update membre set salaire = salaire+100 order by salaire limit 1; -- pour rajouter 100 à celui qui est le moins bien payé

-- 4.1 nom et premnom du directeur de la societe OK!
select nom,prenom 
from membre 
where superieur is NULL;

-- 4.2 les numeros des membres des projets dont la date d'échéance est après le 1er janvier 2007 OK!
select affectation.employe 
from projet,affectation 
where projet.nom=affectation.projet and projet.echeance>'2007-01-01';

select employe 
from affectation join projet on (affectation.projet=projet.nom) 
where projet.echeance>='2007-01-01';

-- 4.3 les prenoms des employes qui travaillent sur le projet PRJ2 OK!
select membre.prenom 
from membre,affectation 
where membre.numero=affectation.employe and affectation.projet='PRJ2';

select prenom 
from affectation join membre on (affectation.employe=membre.numero) 
where projet='PRJ2';

-- 4.4 le numero direct du superieur de l'employe de numero 3 OK!
select membre.superieur 
from membre 
where membre.numero=3;

select superieur 
from membre where 
numero=3;

-- 4.5 le nom du superieur direct de l'employe numero 3* OK!
select membre.nom from membre where membre.numero=(select membre.superieur from membre where membre.numero=3);

select m1.nom from membre m1, membre m2 where m2.numero=3 and m1.numero=m2.superieur;

select m1.nom from membre m1 join membre m2 on m1.numero=m2.superieur where m2.numero=3;

-- 4.6 le nom et prenom du superieur de l'employe de nom Jeremi et de prenom Simon OK!
select membre.nom,prenom from membre where membre.numero=(select membre.superieur from membre where membre.nom='Simon' and prenom='Jeremi');

select m1.nom,m1.prenom from membre m1, membre m2 where m2.nom='Simon' and m2.prenom='Jeremi'
and m1.numero=m2.superieur;


-- 4.7 les noms et prenoms des employes qui ne travaillent pas sur le projet PRJ2 OK!
-- pas bonne solution : select membre.nom,prenom from membre,affectation where affectation.employe=membre.numero and affectation.projet!='PRJ2';
select nom,prenom from membre where numero not in (select employe from affectation where projet='PRJ2');

select nom,prenom from membre left join affectation on (membre.numero=affectation.employe and affectation.projet='PRJ2')where employe is NULL;

-- 4.8 les noms des employes qui ont pour superieur direct Serge Karamazof OK!
select membre.nom from membre where membre.superieur=(select membre.numero from membre where membre.nom='Karamazof');
select m1.nom from membre m1, membre m2 where (m1.superieur=m2.numero)  and(m2.nom='Karamazof') and (m2.prenom='Serge');
select m1.nom from membre m1 join membre m2 on (m1.superieur=m2.numero) where m2.nom='Karamazof' and m2.prenom='Serge';

-- 4.9 les employes tries par ordre alphabetique avec pour chaque employe le nom de son superieur 
select m1.nom,m1.prenom,m2.nom from membre m1 left join membre m2 on m1.superieur= m2.numero order by m1.nom, m1.prenom asc;

-- 4.10  les employes qui ont pour superieur un employe qui a pour superieur Serge Karamazov NON!
-- ne fonctione pas :select membre.nom from membre where membre.superieur=(select membre.numero from membre where membre.superieur=(select membre.numero from membre where membre.nom='Karamazof')); 
select m1.nom from membre m1, membre m2, membre m3 where (m1.superieur=m2.numero) and (m2.superieur=m3.numero) and (m3.nom='Karamazof') and (m3.prenom='Serge');
-- à corriger select m1.nom from membre memb join membre sup join membre supsup on (memb.superieur=sup.numero) and (sup.superieur=supsup.numero) where (supsup.nom='karamazof' and (supsup.prenom='Serge');

-- 5.1 supprimer le projet dont la date d'echeance est la plus eloignéé.
delete from projet where echeance=min(projet.echeance);

-- 5.2 detruire les tables
drop tables;

-- 3.1 les noms des employes qui ont un numéro pair.
select nom
from membre
where (numero%2)=0;

-- 3.2 afficher un tableau a 2 colonnes, avec nom de l'employé en 1ere col et "bien payé" poue les employés payés plus de 7000 et "mal payé"
select nom, if(salaire>7000,'Bien Payé','Mal Payé') as NiveauSalaire
from membre;

-- 3.3 salaire moyen
select avg(salaire)
from membre;

-- 3.4 afficher pour chaque numero d'employé le nb de projet pour leqiel cet employé travaille
select employe, count(projet)
from affectation
group by employe;

-- 3.5 afficher pour chaque projet le salaire de la personne affectée au projet la mieux payée
select projet, max(salaire)
from affectation join membre
on (employe=numero)
group by projet;

-- 3.6 aficher pour chaque nom d'employé le nombre de projets dans lequel cet employé travaille
select nom, count(projet)
from affectation join membre
on (employe=numero)
group by employe;

-- 3.7 afficher pour chaque employé le nombre d'employés qui dépendent de lui (deray 2, Karamazov 2)
select m1.nom, count(m2.superieur)
from membre m1 join membre m2
on (m1.numero=m2.superieur)
group by m1.nom;

-- 3.8 afficher pour chaque employé le nombre d'employés qui dépendent de lui,
--  y compris pour les employés qui ne sont superieur de personne
select m1.nom, count(m2.superieur)
from membre m1 left join membre m2
on (m1.numero=m2.superieur)
group by m1.nom;