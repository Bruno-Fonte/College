<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="SistemaBlockchain.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Controle de Acesso</title>

    <link rel="stylesheet" href="css/styleDefault.css"/>

</head>
<body>
    <form class="form1" runat="server">
        <div class="card">
            <div class="card-top">
                <img class="imglogin" src="img/login.png" alt="Alternate Text" />
                <h2 class="title">Painel de Controle</h2>
                <p>Login no sistema de Blockchain</p>
            </div>

            <div class="card-group">
                <label>E-mail</label>
                <asp:TextBox ID="txtLogin" runat="server" AutoPostBack="True" Height="25px" Width="326px" TextMode="Email"></asp:TextBox>
            </div>

            <div class="card-group">
                <label>
                <br />
                Senha</label>
                <asp:TextBox ID="txtSenha" runat="server" AutoPostBack="True" Height="25px" Width="326px" Type="Password"></asp:TextBox>
            </div>

            <div class="card-group">
                <asp:Button ID="btnLogin" runat="server" OnClick="btnLogin_Click" Text="Login" Width="100%" CssClass="btn" Height="37px"/>
            </div>

            <div class="cadastrar-se">
                <a href="https://localhost:44371/Cadastrar.aspx" id="btnCadastrar" role="button">Cadastrar-se</a>
                <br/>
                <asp:Label ID="lblTeste" runat="server"></asp:Label>
                <br />
                <asp:Label ID="lblId" runat="server" Visible="False"></asp:Label>
            &nbsp;<asp:Label ID="lblTipo" runat="server" Visible="False"></asp:Label>
            </div>

            </div>
    </form>

            
</body>
</html>
