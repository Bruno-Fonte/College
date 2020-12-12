<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MudarSenha.aspx.cs" Inherits="SistemaBlockchain.MudarSenha" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Mudar Senha</title>

    <link rel="stylesheet" href="css/StyleMudarSenha.css" />

</head>
<body>
    <form class="form1" runat="server">
        <div class="card">
            <div class="lblTitle">
                <asp:Label ID="Label1" runat="server" Text="Mudar Senha" CssClass="title"></asp:Label>
            </div>

           <div class="img">
                
                <asp:Button ID="btnSair" runat="server" Text="Sair" cssClass="asText" OnClick="btnSair_Click"/> <br />
                <asp:Button ID="btnVoltar" runat="server" Text="Voltar" cssClass="asText" OnClick="btnVoltar_Click"/>
                
            </div>

            <div class="txtBox">

                <asp:Label ID="lblSenhaAtual" runat="server" Font-Bold="True" Text="Senha atual:     "></asp:Label>
                <br />
                <asp:TextBox ID="txtSenhaAtual" runat="server" Type="Password" AutoPostBack="True"></asp:TextBox>
                
                <br />
                <br />
                
                <asp:Label ID="lblNovaSenha" runat="server" Font-Bold="True" Text="Nova senha:     "></asp:Label>
                <br />
                <asp:TextBox ID="txtNovaSenha" runat="server" Type="Password" AutoPostBack="True"></asp:TextBox>
                
                <br />
                <br />
                
                <asp:Label ID="lblConfNovaSenha" runat="server" Font-Bold="True" Text="Confirmar nova senha:     "></asp:Label>
                <br />
                <asp:TextBox ID="txtConfNovaSenha" runat="server" Type="Password" AutoPostBack="True"></asp:TextBox>

            </div>

            <div class="btnAlterar">
                <asp:Button ID="btnAlterarSenha" runat="server" Font-Bold="True" Font-Size="Medium" Text="Alterar Senha" OnClick="btnAlterarSenha_Click" cssClass="btn"/>
            &nbsp;
                <asp:Label ID="lblValidacao" runat="server"></asp:Label>
                <br />
                <br />
                <asp:Label ID="lblId" runat="server" Text="[id]" Visible="False"></asp:Label>
                <asp:Label ID="lblTipo" runat="server" Text="[tipo]" Visible="False"></asp:Label>
            </div>
        </div>
    </form>
</body>
</html>
