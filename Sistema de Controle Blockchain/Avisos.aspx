<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Avisos.aspx.cs" Inherits="SistemaBlockchain.Avisos" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Avisos</title>

    <link rel="stylesheet" href="css/StyleAvisos.css" />

</head>
<body>
    <form class="form1" id="form1" runat="server">
        <div class="card">
            <asp:Label ID="lblTitulo" runat="server" Text="Avisos" CssClass="title"></asp:Label>

            <div class="img">
               <asp:Button ID="btnSair" runat="server" Text="Sair" cssClass="asText" OnClick="btnSair_Click"/> <br />
                <asp:Button ID="btnMenu" runat="server" Text="Menu" cssClass="asText" OnClick="btnMenu_Click"/>
            </div>

            <div class="grids">

                <br />

                <br />

                <asp:GridView ID="dgAvisosSistema" CssClass="grid1" runat="server" AutoGenerateColumns="false" Visible="true" OnRowDeleting="dgAvisosSistema_RowDeleting">
                   
                    <Columns>
                        <asp:TemplateField HeaderText="Código">
                            <ItemTemplate>
                                <asp:Label id="lblIdGrid" Text='<%# Eval("ID")%>' runat="server" />
                            </ItemTemplate>
                        </asp:TemplateField>
                        <asp:BoundField DataField="DATA" HeaderText="Data" />
                        <asp:BoundField DataField="DESCRICAO" HeaderText="Aviso" />

                        <asp:TemplateField>
                            <ItemTemplate>
                                <asp:ImageButton ImageUrl="~/img/deletar.png" runat="server" CommandName="Delete" ToolTip="Delete" width="20px" Height="20px" />
                            </ItemTemplate>
                            </asp:TemplateField>
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
