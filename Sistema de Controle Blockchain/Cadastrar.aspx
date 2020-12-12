<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Cadastrar.aspx.cs" Inherits="SistemaBlockchain.Cadastrar" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Cadastrar-se</title>

    <link rel="stylesheet" href="css/styleCadastrar.css"/>

    

</head>
<body>
    <form class="cadastrar" id="form1" runat="server">
        <div class="card">
            <div class="card-top">
                <img class="imgcadastrar" src="img/cadastrar.png" alt="Alternate Text" />
                <h2 class="title">Painel de controle</h2>
                <p>Cadastrar Usuário</p>
            </div>

            <div class="card-group">

                <asp:Label ID="Label6" runat="server" Text="Tipo"></asp:Label>
                <br />
                <asp:DropDownList ID="ddlTipo" runat="server" AutoPostBack="True" cssClass="drop" OnSelectedIndexChanged="ddlTipo_SelectedIndexChanged">
                    <asp:ListItem Value="1">Pessoa Física</asp:ListItem>
                    <asp:ListItem Value="2">Pessoa Jurídica</asp:ListItem>
                </asp:DropDownList>
            </div>

            <div class="card-group">
                
                <asp:Label ID="lblNome" runat="server" Text="Nome/Razão Social"></asp:Label>
                <br />
                <asp:TextBox ID="txtNome" runat="server" CssClass="auto-style1" Height="31px" Width="333px" AutoPostBack="True"></asp:TextBox>
                
            </div>

            <div class="card-group">
                <asp:Label ID="lblCpf" runat="server" Text="CPF/CNPJ"></asp:Label>
                <asp:TextBox ID="txtCPF" runat="server" CssClass="auto-style1" Height="31px" Width="333px" AutoPostBack="True"></asp:TextBox>
                &nbsp;</div>

            <div class="card-group">
                &nbsp;<asp:Label ID="lblUser" runat="server" Text="E-mail"></asp:Label>
                <br />
                <asp:TextBox ID="txtUsuario" runat="server" CssClass="auto-style1" Height="31px" Width="333px" AutoPostBack="True" TextMode="Email"></asp:TextBox>
                &nbsp;</div>

            <div class="card-group">
                <asp:Label ID="lblSenha" runat="server" Text="Senha"></asp:Label>
                <br />
                <asp:TextBox ID="txtSenha" runat="server" CssClass="auto-style1" Height="31px" Width="333px" Type="Password" AutoPostBack="True"></asp:TextBox>
                &nbsp;</div>

            <div class="card-group">
                <asp:Label ID="lblConfSenha" runat="server" Text="Confirmar senha"></asp:Label>
          &nbsp;<asp:TextBox ID="txtConfSenha" runat="server" CssClass="auto-style1" Height="31px" Width="333px" Type="Password" AutoPostBack="True"></asp:TextBox>
                &nbsp;</div>

            <div class="card-group2">
                <asp:Button ID="btnCadastrar" runat="server" CssClass="btnCad" Text="Cadastrar" Width="332px" OnClick="btnCadastrar_Click" />
               
                <asp:Label ID="lblValidacao" runat="server"></asp:Label>
                
            </div>

            <div class="voltar">
                <a href="https://localhost:44371/Default.aspx" id="btnVoltar" role="button">Voltar</a>
                <br/>
                
            </div>

        </div>
    </form>
</body>
</html>
