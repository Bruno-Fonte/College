create database dbeditoras;

use dbeditoras;

create table tbl_editoras(
	edi_id int not null primary key,
	edi_nome varchar (50) not null,
	edi_sigla varchar (25) not null,
	edi_observacoes varchar (500) null
);

create table tbl_livros(
	liv_id int not null primary key,
	liv_nome varchar (50) not null,
	liv_anopublicacao int not null,
	liv_isbn decimal(14) not null,
	liv_observacoes varchar (500) null,
	edi_id int not null,
	foreign key (edi_id) references tbl_editoras(edi_id)
);

create table tbl_autores(
	aut_id int not null primary key,
	aut_nome varchar (50) not null,
	aut_pseudonimo varchar (50) not null,
	aut_observacoes varchar (500) null
);

create table tbl_autoreslivros(
	liv_id int not null,
	aut_id int not null,
	foreign key (liv_id) references tbl_livros(liv_id),
	foreign key (aut_id) references tbl_autores(aut_id),
	primary key(liv_id, aut_id)
);

create table tbl_usuario(
	id_user int not null primary key,
	usuario varchar(15) not null,
	senha varchar(15) not null
);

select * from tbl_livros;

select count(liv_id) as num from tbl_livros where edi_id = 2;

update tbl_livros set liv_nome = 'Why are you that', liv_anopublicacao = 2005, liv_isbn = 42146698855220,
liv_observacoes = 'obs', edi_id = 5 where liv_id = 5;  

drop table tbl_usuario;

select * from tbl_usuario;

delete from tbl_usuario where usuario = 'Nikoo';

insert into tbl_usuario values
('Adm', '123456');

insert into tbl_editoras (edi_id, edi_nome, edi_sigla, edi_observacoes)
values (4, 'Fire', 'FR', 'obs');

insert into tbl_autores (aut_id, aut_nome, aut_pseudonimo, aut_observacoes)
values (1, 'Michael Scott', 'Michael Scarn', 'obs');

insert into tbl_livros (liv_id, liv_nome, liv_anopublicacao, liv_isbn, liv_observacoes, edi_id)
values (1, 'Somehow I Manage', 2009, 74932518504630, 'obs', 1);

insert into tbl_autoreslivros (liv_id, aut_id)
values (1, 1);

select * from tbl_editoras;

select * from tbl_autores;

select * from tbl_autoreslivros;

update tbl_editoras set edi_nome = 'Earth', edi_sigla = 'ET', edi_observacoes = 'obs'
where edi_id = 1;

delete from tbl_autoreslivros
where aut_id = 1;

select edi_id, edi_nome, edi_sigla, edi_observacoes from tbl_editoras where edi_nome like 'f%';

select liv_id, liv_nome, liv_anopublicacao, liv_isbn, liv_observacoes, edi_nome
from tbl_livros l inner join tbl_editoras e on l.edi_id = e.edi_id where liv_nome like 'f%';

select liv_id, liv_nome from tbl_livros;
