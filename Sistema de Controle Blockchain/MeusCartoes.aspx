<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MeusCartoes.aspx.cs" Inherits="SistemaBlockchain.MeusCartoes" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Meus Cartões</title>

    <link rel="stylesheet" href="css/StyleMeusCartoes.css" />

</head>
<body>
    <form class="form1" id="form1" runat="server">
        <div class="card">

            <asp:Label ID="lblTitulo" runat="server" Text="Meus Cartões" CssClass="title"></asp:Label>

            <div class="img">
                
                <asp:Button ID="btnSair" runat="server" Text="Sair" cssClass="asText" OnClick="btnSair_Click"/> <br />
                <asp:Button ID="btnMenu" runat="server" Text="Menu" cssClass="asText" OnClick="btnMenu_Click"/>
                
            </div>

            <div class="gridView">

                <br />
                <asp:Label ID="lblCredito" runat="server" Font-Bold="True" Text="Crédito"></asp:Label>

                <asp:GridView ID="dgCartoesCredito" runat="server" CssClass="grid" AutoGenerateColumns="false">
                    <Columns>
                        <asp:BoundField DataField="NUM_CARTAO" HeaderText="Número do Cartão" />
                        <asp:BoundField DataField="NUM_CONTA" HeaderText="Número da Conta" />
                        <asp:BoundField DataField="LIMITE_CARTAO" HeaderText="Limite do Cartão" />
                        <asp:BoundField DataField="GASTOS_CARTAO" HeaderText="Gastos do Cartão" />
                    </Columns> 
                </asp:GridView>

                <br />
                <asp:Label ID="lblDebito" runat="server" Font-Bold="True" Text="Débito"></asp:Label>

                <br />

                <asp:GridView ID="dgCartoesDebito" runat="server" CssClass="grid" AutoGenerateColumns="false">
                    <Columns>
                        <asp:BoundField DataField="NUM_CARTAO" HeaderText="Número do Cartão" />
                        <asp:BoundField DataField="NUM_CONTA" HeaderText="Número da Conta" />
                        <asp:BoundField DataField="SALDO_CARTAO" HeaderText="Saldo do Cartão" />
                    </Columns> 
                </asp:GridView>

            </div>

            <div class="label">

                <br />

                <asp:Label ID="lblId" runat="server" Visible="False"></asp:Label>

                <asp:Label ID="lblTipo" runat="server" Visible="False"></asp:Label>

            </div>

        </div>
    </form>
</body>
</html>
