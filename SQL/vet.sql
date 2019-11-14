DROP DATABASE IF EXISTS vet;
CREATE DATABASE IF NOT EXISTS vet;
USE vet; 

SELECT 'CREATING DATABASE STRUCTURE' as 'INFO';

DROP TABLE IF EXISTS vet;


CREATE TABLE table1 (
    id	    	INT         	NOT NULL,
    birth_date  DATE            NOT NULL,
    first_name  VARCHAR(20)     NOT NULL,
    last_name   VARCHAR(20)     NOT NULL,
    gender      ENUM ('M','F')  NOT NULL,    
    PRIMARY KEY (id)
);

INSERT INTO table1 (id, birth_date, first_name, last_name, gender)
	VALUES (1,'1992-09-20', 'nataly', 'prego', 'F'), (2, '1992-07-24', 'Matan', 'Cohen', 'M'), (3, '1988-05-06' ,'Jeff', 'Villano', 'M'), ('4', '1991-01-16', 'Linor', 'Zambel', 'F');


