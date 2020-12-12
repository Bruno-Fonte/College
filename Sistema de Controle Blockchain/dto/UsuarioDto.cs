using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SistemaBlockchain.dto
{
    public class UsuarioDto
    {
        private String _nome;
        private String _cpf_cnpj;
        private String _login;
        private String _senha;

        public String Nome { get { return this._nome; } set { this._nome = value; } }
        public String CpfCnpj { get { return this._cpf_cnpj; } set { this._cpf_cnpj = value; } }
        public String Login { get { return this._login; } set { this._login = value; } }
        public String Senha { get { return this._senha; } set { this._senha = value; } }
    }
}