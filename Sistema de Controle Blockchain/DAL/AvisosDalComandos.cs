using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace SistemaBlockchain.DAL
{
    public class AvisosDalComandos
    {
        public bool tem = false;
        public String msg = "";
        SqlCommand _comando = new SqlCommand();
        Conexao _conexao = new Conexao();
        SqlDataAdapter _adaptador = new SqlDataAdapter();
        DataTable _tabela = new DataTable();


        public DataTable CarregarGridAvisosSistema(int id)
        {
            tem = false;

            _comando.CommandText = " select id, data, descricao " +
                                   " from TB_AVISOS_USUARIOS " +
                                   " where ID_USUARIO = @id; ";

            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;

            try
            {
                _comando.Connection = _conexao.conectar();
                _tabela = new DataTable();
                _adaptador = new SqlDataAdapter(_comando);
                _adaptador.Fill(_tabela);
                _conexao.desconectar();

                tem = true;

                return _tabela;

            }
            catch (SqlException)
            {
                return null;
            }
        }

        public void GerarAviso(String descricao, int id)
        {
            tem = false;

            _comando.CommandText = " insert into TB_AVISOS_USUARIOS values " +
                                   " (@descricao, @id, CURRENT_TIMESTAMP); ";

            _comando.Parameters.Add("@descricao", SqlDbType.VarChar).Value = descricao;
            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                tem = true;
            }
            catch (SqlException)
            {
                throw new Exception();
            }
        }

        public void ExcluirAviso(int id)
        {
            tem = false;

            _comando.CommandText = " delete from TB_AVISOS_USUARIOS " +
                                   " where ID = @id; ";

            _comando.Parameters.Add("@id", SqlDbType.Int).Value = id;

            try
            {
                _comando.Connection = _conexao.conectar();
                _comando.ExecuteNonQuery();
                _conexao.desconectar();

                this.msg = "Excluído com sucesso!";
                tem = true;
            }
            catch (SqlException)
            {
                this.msg = "Erro com o banco de dados!";
            }
        }
    }
}