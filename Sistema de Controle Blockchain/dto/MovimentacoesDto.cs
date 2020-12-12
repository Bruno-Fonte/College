using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace SistemaBlockchain.dto
{
    public class MovimentacoesDto
    {
        private String _descricao;
        private Decimal _valor;
        private int _tipoMovimentacao;
        private Decimal _numContaOrigem;
        private Decimal _numContaDestino;
        public string Descricao { get => _descricao; set => _descricao = value; }
        public decimal Valor { get => _valor; set => _valor = value; }
        public int TipoMovimentacao { get => _tipoMovimentacao; set => _tipoMovimentacao = value; }
        public decimal NumContaOrigem { get => _numContaOrigem; set => _numContaOrigem = value; }
        public decimal NumContaDestino { get => _numContaDestino; set => _numContaDestino = value; }
    }
}