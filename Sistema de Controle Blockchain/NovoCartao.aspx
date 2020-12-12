<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="NovoCartao.aspx.cs" Inherits="SistemaBlockchain.NovoCartao" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Novo Cartão</title>

    <link rel="stylesheet" href="css/StyleNovoCartao.css" />

</head>
<body>
    <form class="form1" id="form1" runat="server">
        <div class="card">
            <asp:Label ID="lblTitulo" runat="server" Text="Novo Cartão" CssClass="title"></asp:Label>
        
            <div class="img">
                
                <asp:Button ID="btnSair" runat="server" Text="Sair" cssClass="asText" OnClick="btnSair_Click"/> <br />
                <asp:Button ID="btnMenu" runat="server" Text="Menu" cssClass="asText" OnClick="btnMenu_Click"/>
                
            </div>

            <div class="ddl">
            <asp:DropDownList ID="ddlUsuario" runat="server" CssClass="combo1" AutoPostBack="True" OnSelectedIndexChanged="ddlTipo_SelectedIndexChanged" Font-Bold="True" Font-Size="Medium">
            </asp:DropDownList>

                <br />
                <br />
            <asp:DropDownList ID="ddlTipo" runat="server" CssClass="combo1" AutoPostBack="True" OnSelectedIndexChanged="ddlTipo_SelectedIndexChanged" Font-Bold="True" Font-Size="Medium">
                <asp:ListItem Value="1">Crédito</asp:ListItem>
                <asp:ListItem Value="2">Débito</asp:ListItem>
            </asp:DropDownList>

            </div>

            <div class="txtBox">

                <asp:Label ID="Label1" runat="server" Text="N° do Cartão:" Font-Bold="True"></asp:Label>
                <asp:TextBox ID="txtNumCartao" runat="server" CssClass="txtNum" MaxLength="16" AutoPostBack="True"></asp:TextBox>

                <br />

                <asp:Label ID="lblLimite" runat="server" Text="Limite:" Font-Bold="True" CssClass="lbl2"></asp:Label>
                <asp:TextBox ID="txtLimite" runat="server" CssClass="txtLimite" TextMode="Number" AutoPostBack="True"></asp:TextBox>

                <br />

                <asp:Label ID="Label3" runat="server" Text="Número da conta:" Font-Bold="True" CssClass="lbl2"></asp:Label>
                <asp:TextBox ID="txtConta" runat="server" CssClass="txtLimite" AutoPostBack="True" MaxLength="5"></asp:TextBox>

            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

            </div>

            <div class="buton">

                <asp:Button ID="btnConfirmar" runat="server" CssClass="btnNovo" OnClick="btnConfirmar_Click" Text="Confirmar" />

            </div>

            <div class="label">

                <asp:Label ID="lblValidacao" runat="server" Text="Insira os dados"></asp:Label>

                <br />
                <br />
                <asp:Label ID="lblId" runat="server" Visible="False"></asp:Label>

                <asp:Label ID="lblTipo" runat="server" Visible="False"></asp:Label>

            </div>

        </div>

        

    </form>
</body>
</html>
