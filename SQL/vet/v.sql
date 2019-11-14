DROP DATABASE IF EXISTS vet;
CREATE DATABASE IF NOT EXISTS vet;
USE vet; 

SELECT 'CREATING DATABASE STRUCTURE' as 'INFO';

DROP TABLE IF EXISTS owners, pets;


CREATE TABLE owners (
    Id	    	INT         	NOT NULL,
    Name		VARCHAR(20)     NOT NULL,
    Phone		VARCHAR(9)		NOT NULL,   
    PRIMARY KEY (Id),
    UNIQUE KEY	(Id) 
);

INSERT INTO owners (Id, Name, Phone) VALUES (1,'nataly', '050-11111'), (2, 'Tom', '050-22222'), (3, 'Jeff' ,'050-33333');

CREATE TABLE pets (
    Id	    	INT         	NOT NULL,
    Name		VARCHAR(20)     NOT NULL,
    Age			FLOAT		 	NOT NULL,   
    Gender		CHAR			NOT NULL,
    PRIMARY KEY (Name),
   	CONSTRAINT FOREIGN KEY (Id) REFERENCES owners (Id)
);

INSERT INTO pets (Id, Name, Age, Gender) VALUES (3, 'Amigo', 12, 'M'), (2, 'Rex', 1.5, 'M'), (2, 'Luka', 5, 'F');
