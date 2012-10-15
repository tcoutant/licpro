create table magazine(
numag integer primary key, 
nommag varchar(20),
prix integer(2));
create table client (
idclient integer primary key auto_increment, 
nom varchar(15),
ville varchar(20));
create table abonnement ( 
numag integer prymary key,
numclient integer primary key,
echeance date);
create table stock (
numag integer primary key,
numero integer primary key,
nombre integer primary key);
create table commande(
numclient integer primary key,
numag integer primary key,
numero integer  primary key);