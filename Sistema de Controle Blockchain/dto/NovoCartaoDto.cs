using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SistemaBlockchain.dto
{
    public class NovoCartaoDto
    {
        private int _idUser;
        private Decimal _numConta;
        private int _tipoCartao;
        private Decimal _numCartao;
        private Decimal _limite;
        private Decimal _saldo;
        private Decimal _gastos;

        public int IdUser { get { return this._idUser; } set { this._idUser = value; } }
        public Decimal NumConta { get { return this._numConta; } set { this._numConta = value; } }
        public int TipoCartao { get { return this._tipoCartao; } set { this._tipoCartao = value; } }
        public Decimal NumCartao { get { return this._numCartao; } set { this._numCartao = value; } }
        public Decimal Limite { get { return this._limite; } set { this._limite = value; } }
        public Decimal Saldo { get { return this._saldo; } set { this._saldo = value; } }
        public Decimal Gastos { get { return this._gastos; } set { this._gastos = value; } }

    }
}