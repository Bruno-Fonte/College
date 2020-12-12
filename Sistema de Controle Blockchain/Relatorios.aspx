<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Relatorios.aspx.cs" Inherits="SistemaBlockchain.Relatorios" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Relatórios</title>

    <link rel="stylesheet" href="css/StyleRelatorios.css" />

</head>
<body>
    <form class="form1" id="form1" runat="server">
        <div class="card">

            <asp:Label ID="lblTitulo" runat="server" Text="Relatórios" CssClass="title"></asp:Label>

            <div class="img">
                
                <asp:Button ID="btnSair" runat="server" Text="Sair" cssClass="asText" OnClick="btnSair_Click"/> <br />
                <asp:Button ID="btnMenu" runat="server" Text="Menu" cssClass="asText" OnClick="btnMenu_Click"/>
                
            </div>

            <div class="combotop">

                <asp:Label ID="lblContas" runat="server" Font-Bold="True" Text="Minhas Contas "></asp:Label>
                <br />

            <asp:DropDownList ID="ddlContas" runat="server" CssClass="combo1" AutoPostBack="True" ForeColor="Black" DataTextField="NUM_CONTA" DataValueField="NUM_CONTA" OnSelectedIndexChanged="ddlContas_SelectedIndexChanged" Font-Bold="True" Font-Size="Medium">
                <asp:ListItem>Contas</asp:ListItem>
            </asp:DropDownList>

            </div>

            <div class="grids">

                <asp:GridView ID="dgRelatorios" runat="server" CssClass="grid" AutoGenerateColumns="false" Width="100%">
                    <Columns>
                        <asp:BoundField DataField="DATA" HeaderText="Data" />
                        <asp:BoundField DataField="HISTORICO" HeaderText="Descrição" />
                        <asp:BoundField DataField="NUM_CONTA_ORIGEM" HeaderText="Conta origem" />
                        <asp:BoundField DataField="VALOR_MOVIMENTACAO" HeaderText="Valor" />
                        <asp:BoundField DataField="NUM_CONTA_DESTINO" HeaderText="Conta destino" />
                        <asp:BoundField DataField="NOME_MOVIMENTACAO" HeaderText="Tipo" />
                        <asp:BoundField DataField="NOME_CARTAO" HeaderText="Forma" />
                    </Columns>
                </asp:GridView>

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
