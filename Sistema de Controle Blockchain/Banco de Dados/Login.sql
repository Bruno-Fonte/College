CREATE DATABASE Blockchain;

use Blockchain;

CREATE TABLE TB_TIPO_USUARIO(
	TIPO_USUARIO INT PRIMARY KEY,
	NOME_TIPO VARCHAR(30) NOT NULL
);

CREATE TABLE TB_USUARIO(
	ID_USUARIO INT IDENTITY NOT NULL PRIMARY KEY,
	NOME_RAZAO VARCHAR(200) NOT NULL,
	CPF_CNPJ VARCHAR(14) NOT NULL UNIQUE,
	USUARIO_LOGIN VARCHAR(20) NOT NULL UNIQUE,
	SENHA_LOGIN VARCHAR(20) NOT NULL,
	TIPO_USUARIO INT NOT NULL -- 1 = Admin | 2 = Pessoa F�sica | 3 = Pessoa Jusr�dica
	FOREIGN KEY (TIPO_USUARIO) REFERENCES TB_TIPO_USUARIO(TIPO_USUARIO)
);

CREATE TABLE TB_CARTOES(
	ID INT NOT NULL IDENTITY PRIMARY KEY,
	ID_USUARIO INT NOT NULL,
	NUM_CONTA DECIMAL(5,0) UNIQUE NOT NULL,
	TIPO_CARTAO INT NOT NULL,
	NUM_CARTAO DECIMAL (16,0) UNIQUE NOT NULL,
	LIMITE_CARTAO DECIMAL (8,2),
	SALDO_CARTAO DECIMAL (8,2),
	GASTOS_CARTAO DECIMAL (8,2)
	FOREIGN KEY (ID_USUARIO) REFERENCES TB_USUARIO(ID_USUARIO),
	FOREIGN KEY (TIPO_CARTAO) REFERENCES TB_TIPO_CARTAO(TIPO_CARTAO)
);

CREATE TABLE TB_TIPO_CARTAO(
	TIPO_CARTAO INT PRIMARY KEY,
	NOME_CARTAO VARCHAR(30) NOT NULL
);

CREATE TABLE TB_AVISOS_USUARIOS(
    ID INT NOT NULL IDENTITY PRIMARY KEY,
    DESCRICAO VARCHAR(100) NOT NULL,
    ID_USUARIO INT NOT NULL,
    DATA SMALLDATETIME NOT NULL,
    foreign key (ID_USUARIO) references tb_usuario(id_usuario)
);

CREATE TABLE TB_MOVIMENTACOES(
	ID INT IDENTITY NOT NULL PRIMARY KEY,
	DATA SMALLDATETIME NOT NULL,
	HISTORICO VARCHAR(200) NOT NULL,
	VALOR_MOVIMENTACAO DECIMAL (6,2) NOT NULL,
	TIPO_MOVIMENTACAO INT NOT NULL, -- 1 : Pagamento | 2 : Transfer�ncia
	NUM_CONTA_ORIGEM DECIMAL(5,0) NOT NULL,
	NUM_CONTA_DESTINO DECIMAL(5,0) NOT NULL
	FOREIGN KEY (NUM_CONTA_ORIGEM) REFERENCES TB_CARTOES(NUM_CONTA),
	FOREIGN KEY (NUM_CONTA_DESTINO) REFERENCES TB_CARTOES(NUM_CONTA),
	FOREIGN KEY (TIPO_MOVIMENTACAO) REFERENCES TB_TIPO_MOVIMENTACOES(TIPO_MOVIMENTACAO)
);

CREATE TABLE TB_TIPO_MOVIMENTACOES(
	TIPO_MOVIMENTACAO INT PRIMARY KEY,
	NOME_MOVIMENTACAO VARCHAR(100) NOT NULL
);

--select tipo de usu�rio--
select u.TIPO_USUARIO from TB_USUARIO u inner join TB_CARTOES c 
on c.ID_USUARIO = u.ID_USUARIO where c.NUM_CONTA = 96637;

--Select avisos sistema--
select data, descricao
from TB_AVISOS_USUARIOS
where ID_USUARIO = 1;

--select dados do cart�o -- 
select c.tipo_cartao, num_cartao, limite_cartao, nome_cartao
from tb_cartoes c inner join TB_TIPO_CARTAO t on c.TIPO_CARTAO = t.TIPO_CARTAO where c.id_usuario  = 1;

--Select dos relat�rios--
select m.DATA, m.HISTORICO, m.VALOR_MOVIMENTACAO, m.NUM_CONTA_ORIGEM, m.NUM_CONTA_DESTINO, 
tm.NOME_MOVIMENTACAO, tc.NOME_CARTAO from TB_MOVIMENTACOES m inner join
TB_CARTOES c on (m.NUM_CONTA_DESTINO = c.NUM_CONTA) or (m.NUM_CONTA_ORIGEM = c.NUM_CONTA) inner join TB_TIPO_CARTAO tc on tc.TIPO_CARTAO = c.TIPO_CARTAO 
inner join TB_TIPO_MOVIMENTACOES tm on tm.TIPO_MOVIMENTACAO = m.TIPO_MOVIMENTACAO inner join TB_USUARIO u on c.ID_USUARIO = u.ID_USUARIO
where c.ID_USUARIO = 4 group by m.DATA, m.HISTORICO, m.NUM_CONTA_ORIGEM, m.VALOR_MOVIMENTACAO, 
m.NUM_CONTA_DESTINO, tm.NOME_MOVIMENTACAO, tc.NOME_CARTAO;

--Calculo do saldo--
select c.LIMITE_CARTAO - sum(m.VALOR_MOVIMENTACAO) as Saldo from 
TB_CARTOES c inner join TB_MOVIMENTACOES m on c.NUM_CONTA = m.NUM_CONTA_ORIGEM where 
c.NUM_CONTA = 10254 and c.ID_USUARIO = 1 group by c.LIMITE_CARTAO;

--Todos os selects das tabelas

select * from TB_AVISOS_USUARIOS;

select * from TB_CARTOES;

select * from TB_MOVIMENTACOES;

select * from TB_TIPO_CARTAO;

select * from TB_TIPO_MOVIMENTACOES;

select * from TB_TIPO_USUARIO;

select * from TB_USUARIO;

