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

-- Insertion
insert into magazine values ('BD Hebdo', 2);
insert into magazine values ('Oraclemag', 4);
insert into client values (5, 'Patrick Rudoux', 'Angers');
insert into client values (8, 'Roland Lebrun', 'Nantes');
insert into client values (10, 'Herve Lenoir', 'Angers');
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
