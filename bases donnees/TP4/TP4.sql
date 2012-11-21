create table Etudiant(
	ine numeric(10) primary key,
	nom varchar(15),
	prenom varchar(15),
	cursus varchar(15),
	constraint curs foreign key(cursus) references Cursus(nom)
);
create table Cursus(
	nom varchar(15) primary key,
	responsable varchar(15)
);
create table Examen(
	cursus varchar(15),
	matiere varchar(15),
	constraint exkey primary key (cursus,matiere),
	constraint cursu foreign key(cursus) references Cursus(nom)	
);
create table Note(
	etudiant numeric(10),
	matiere varchar(15),
	note numeric(2) check (note >= 0 and note <= 20),
	constraint onkey primary key(etudiant,matiere),
	constraint etud foreign key(etudiant) references Etudiant(ine),
	constraint mat foreign key(matiere) references Examens
);
drop table Note;
drop table Examen;
drop table Cursus;
drop table Etudiant;


create table Cursus(
	nom varchar(15) primary key,
	responsable varchar(15)
	) ENGINE=InnoDB;
create table Etudiant(
	ine numeric(10) primary key,
	nom varchar(15),
	prenom varchar(15),
	cursus varchar(15),
	index(cursus),
	constraint curs foreign key(cursus) references Cursus(nom)
	)ENGINE=InnoDB;
create table Examen(
	cursus varchar(15),
	matiere varchar(15),
	index(cursus),
	index(matiere),
	constraint exkey primary key (cursus, matiere),
	constraint curs2 foreign key(cursus) references Cursus(nom)
	)ENGINE=InnoDB;
create table Note(
	etudiant numeric(10),
	matiere varchar(15),
	note numeric(2) check (note >= 0 and note <= 20),
	constraint nkey primary key (etudiant, matiere),
	index(etudiant),
	constraint etud foreign key(etudiant) references Etudiant(ine),
	constraint mat foreign key(matiere) references Examen(matiere)
)ENGINE=InnoDB;


show tables;
describe Cursus;
describe Etudiant;
describe Examen;
describe Note;
select*from Cursus;
select*from Etudiant;
select*from Examen;
select*from Notes;
insert into Cursus values ('Licence pro','F.Lardeux');
insert into Examen values ('Licence pro','BD');
insert into Examen values ('Licence pro', 'Systeme');
insert into Examen values ('Licence pro', 'Objets');

insert into Cursus values ('Master', 'F. Saubion');
insert into Examen values ('Master', 'BD');
insert into Examen values ('Master', 'Logique');

insert into Etudiant values (23, 'Accroc', 'Arthur', 'Licence pro');
insert into Note values (23, 'BD', 14);
insert into Note values (23, 'Systeme', 10);
insert into Note values (23, 'Objets', 12);
insert into Etudiant values (32, 'Rambo', 'John', 'Master');
insert into Note values (32, 'BD', 10);
insert into Note values (32, 'Logique', 3);
insert into Etudiant values (28, 'Ingalls', 'Laura', 'Licence pro');
insert into Note values (28, 'BD', 3);
insert into Note values (28, 'Systeme', 14);
insert into Note values (28, 'Objets', 12);
-- 3.1
select matiere
from Etudiant natural join Examen
where nom='Rambo' and prenom='John';

-- 3.2
select count(*) from Etudiant where cursus='Licence pro';

-- 3.3
select count(distinct matiere) 
from Examen;

-- 3.4
select nom,prenom 
from Etudiant
order by nom asc,prenom desc;	-- asc croissant desc decroissant

-- 3.5
select nom, note
from Etudiant, Note
where Note.Etudiant=Etudiant.ine and Note.matiere='BD'
order by Note.note desc;

-- 3.6
select avg(note) as moyenne from Etudiant join Note on(Etudiant.ine=Note.etudiant)
where matiere='BD' and cursus='Licence pro';

-- 3.7
select nom from Etudiant join Note on (Etudiant.ine=Note.etudiant)
where note < 10;

-- 3.8
select nom from Etudiant 
where not exists (select null from Note where Note.etudiant = Etudiant.ine and note < 10);

-- 3.8
select nom from Etudiant 
where ine not in (select etudiant from Note
where note < 10);

-- 3.9 pas bonne s'il y a plusieurs notes maxi égale
select max(note) as 'meilleure note',matiere,nom from Note join Etudiant on Note.etudiant=Etudiant.ine;

-- ici cela fonctionne
select Note.note, Etudiant.nom,Note.matiere
from Note, Etudiant
where note>= all (select note from Note) and Note.etudiant = Etudiant.ine;

-- 3.10
select nom,prenom 
from Note, Etudiant 
where Etudiant.cursus='Licence pro' and Note.etudiant=Etudiant.ine and matiere='BD' and Note.note >= (select avg(note) as moyenne from Etudiant join Note on(Etudiant.ine=Note.etudiant)
where matiere='BD' and cursus='Licence pro');

-- 3.11

select nom, prenom
from Note, Etudiant
where (Etudiant.ine= Note.etudiant)
and (matiere='BD')
and (note>= 10)
and exists
(select null from Note where (Etudiant.ine=Note.etudiant)
and Note.note < 10);

select nom,prenom
from Note, Etudiant
where (Etudiant.ine=Note.etudiant)
and matiere='BD';

-- 3.12 a 
select matiere,cursus
from Examen
where not exists (select null from Note, Etudiant where Note.etudiant=Etudiant.ine and note<10
and Etudiant.cursus=Examen.cursus and Note.matiere=Examen.matiere);

-- 3.13 
select Note.matiere,Etudiant.cursus
from Note,Etudiant
where Note.etudiant= Etudiant.ine and note>=10
group by Note.matiere, Etudiant.cursus
having count(*) >=2;

-- 4.1 demarrer une transaction,supprimer les etudiants qui on moins de 10 en logique,
--  verifier puis annuler cette transaction, verifier que l'etudiant est present
begin transaction;
--!!!!delete Etudiant where Etudiant.ine matiere='Logique' and note < 10;