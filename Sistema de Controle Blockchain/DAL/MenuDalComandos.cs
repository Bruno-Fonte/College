using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace SistemaBlockchain.DAL
{
    public class MenuDalComandos
    {
        public bool tem = false;
        public String msg = "";
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();

        public String ObterNome(int id)
        {
            String nome;

            _comando.CommandText = " select NOME_RAZAO from TB_USUARIO " +
                                   " where ID_USUARIO = @id; ";

            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;

            _comando.Connection = _conexao.conectar();
            nome = _comando.ExecuteScalar().ToString();

            _conexao.desconectar();

            return nome;
        }
    }
}