<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Movimentacoes.aspx.cs" Inherits="SistemaBlockchain.Movimentacoes" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>

    <link rel="stylesheet" href="css/StyleMovimentacoes.css" />

    <style type="text/css">
        .auto-style1 {}
    </style>

</head>
<body>
    <form class="form1" id="form1" runat="server">
        <div class="card">
            <asp:Label ID="lblTitulo" runat="server" Text="Movimentações" CssClass="title"></asp:Label>
        
            <div class="img">
                
                <asp:Button ID="btnSair" runat="server" Text="Sair" cssClass="asText" OnClick="btnSair_Click"/> <br />
                <asp:Button ID="btnMenu" runat="server" Text="Menu" cssClass="asText" OnClick="btnMenu_Click"/>
                
            </div>

            <div class="comboTipos">

                <asp:Label ID="lblTipoMov" runat="server" Font-Bold="True" Text="Tipo de movimentação:"></asp:Label>
                <br />

                <asp:DropDownList ID="ddlTipos" runat="server" AutoPostBack="True" Font-Bold="True" ForeColor="Black" CssClass="ddlTipos" Width="161px" Font-Size="Medium">
                    <asp:ListItem Value="1">Pagamento</asp:ListItem>
                    <asp:ListItem Value="2">Transferência</asp:ListItem>
                </asp:DropDownList>

            </div>
            
            <div class="panel">

                    <asp:Label ID="lblContaOrigem" runat="server" Text="Conta de origem:   " Font-Bold="True"></asp:Label>
                    <br />
                    <asp:DropDownList ID="ddlContaOrigem" runat="server" CssClass="ddlTipos" Font-Bold="True" ForeColor="Black" AutoPostBack="True" Height="17px" Width="170px" Font-Size="Medium">
                        <asp:ListItem>34235</asp:ListItem>
                    </asp:DropDownList>
                    <br />
                    <br />
                    <asp:Label ID="lblValor" runat="server" Text="Valor:   " Font-Bold="True"></asp:Label>
                    <br />
                    <asp:TextBox ID="txtValor" runat="server" CssClass="auto-style1" Width="161px" AutoPostBack="True"></asp:TextBox>
                    <br />
                    <br />
                    <asp:Label ID="lblContaDestino" runat="server" Text="Conta de destino:   " Font-Bold="True"></asp:Label>
                    <br />
                    <asp:TextBox ID="txtContaDestino" runat="server" CssClass="auto-style1" Width="161px" AutoPostBack="True"></asp:TextBox>
                    <br />
                    <asp:TextBox ID="txtDescricao" runat="server" CssClass="auto-style1" Width="300px" AutoPostBack="True" Visible="False"></asp:TextBox>
                    <br />
                    <br />
                    <asp:Button ID="btnEfetuar" runat="server" Font-Bold="True" Font-Size="Medium" OnClick="btnEfetuar_Click" Text="Efetuar Movimentação" cssClass="btn"/>
&nbsp;<br />
                    <asp:Label ID="lblValidacao" runat="server"></asp:Label>

            </div>

            <div>

                <br />
                <asp:Label ID="lblId" runat="server" Visible="False"></asp:Label>

                <asp:Label ID="lblTipo" runat="server" Visible="False"></asp:Label>

            </div>


        </div>
    </form>
</body>
</html>
