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
	index(matiere),
	constraint exkey primary key (cursus, matiere),
	constraint cursu foreign key(cursus) references Cursus(nom)
	);
create table Note(
	etudiant numeric(10),
	matiere varchar(15),
	note numeric(2) check (note >= 0 and note <= 20),
	constraint nkey primary key (etudiant, matiere),
	constraint etud foreign key(etudiant) references Etudiant(ine),
	constraint mat foreign key(matiere) references Examen(matiere)
);

	