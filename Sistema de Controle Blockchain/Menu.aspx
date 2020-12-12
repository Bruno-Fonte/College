<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Menu.aspx.cs" Inherits="SistemaBlockchain.Menu" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Menu Principal</title>

    <link rel="stylesheet" href="css/styleMenu.css"/>

    

    <style type="text/css">
        .button {
            margin-left: 0px;
            width: 1323px;
        }
        .label {
            height: 28px;
            width: 712px;
        }
        .auto-style1 {
            width: 1237px;
        }
    </style>

    

</head>
<body>
    <form id="form1" runat="server">
        
            
        
        <div class="card">

            <div class="auto-style1">

                <asp:Label ID="lblNome" runat="server" CssClass="lblNome"></asp:Label>

                <br />

            </div>

            <div class="img">
                <a href="https://localhost:44371/Default.aspx" id="btnSair" role="button">Sair</a>
            </div>
            
            <div class="label">

                <asp:Label ID="lblId" runat="server" Visible="False"></asp:Label>

                <asp:Label ID="lblTipo" runat="server" Visible="False"></asp:Label>

            </div>

            <div class="button">
            <asp:Button  ID="btnRelatorios" runat="server" CssClass="btnMenu" target="_blank" rel="nofollow noopener" Height="77px" Text="Relatórios" Width="220px" OnClick="btnRelatorios_Click" />
            
            <asp:Button  ID="btnAvisos" runat="server" CssClass="btnMenu" Height="77px" Text="Avisos" Width="220px" OnClick="btnAvisos_Click" />
            
            <asp:Button  ID="btnMeusDados" runat="server" CssClass="btnMenu" Height="77px" Text="Meus Dados" Width="220px" OnClick="btnMeusDados_Click" />
            
                <br />
                <br />
            
            <asp:Button  ID="btnMovimentacoes" runat="server" CssClass="btnMenu" Height="77px" Text="Movimentações" Width="220px" OnClick="btnMovimentacoes_Click" />
            
            <asp:Button  ID="btnMeusCartoes" runat="server" CssClass="btnMenu" Height="77px" Text="Meus Cartões" Width="220px" OnClick="btnMeusCartoes_Click" />
            
            <asp:Button  ID="btnEditarCadastro" runat="server" CssClass="btnMenu" Height="77px" Text="Editar Cadastros" Width="220px" OnClick="btnEditarCadastro_Click" />
            </div>
        
        </div>
    </form>
</body>
</html>
