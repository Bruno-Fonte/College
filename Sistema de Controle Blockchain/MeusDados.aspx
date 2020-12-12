<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MeusDados.aspx.cs" Inherits="SistemaBlockchain.MeusDados" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Meus Dados</title>
    
    <link rel="stylesheet" href="css/StyleMeusDados.css" />

</head>
<body>
    <form class="form1" id="form1" runat="server">

        <div class="card">
            <asp:Label ID="lblTitulo" runat="server" Text="Meus Dados" CssClass="title"></asp:Label>
        
            <div class="img">
                <asp:Button ID="btnSair" runat="server" Text="Sair" cssClass="asText" OnClick="btnSair_Click"/> <br />
                <asp:Button ID="btnMenu" runat="server" Text="Menu" cssClass="asText" OnClick="btnMenu_Click"/>
            </div>

            <div class="combo">

                 <br />

                 <asp:GridView ID="dgDados" runat="server" cssClass="grid" AutoGenerateColumns="False" OnRowCancelingEdit="dgDados_RowCancelingEdit" OnRowEditing="dgDados_RowEditing" OnRowUpdating="dgDados_RowUpdating">
                     <Columns>
                         <asp:TemplateField HeaderText="ID">
                            <ItemTemplate>
                                <asp:Label id="lblIdGrid" Text='<%# Eval("ID_USUARIO")%>' runat="server" />
                            </ItemTemplate>
                        </asp:TemplateField>

                         <asp:TemplateField HeaderText="Nome/Razão">
                            <ItemTemplate>
                                <asp:Label Text='<%# Eval("NOME_RAZAO")%>' runat="server" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:TextBox ID="txtNomeRazao" Text='<%# Eval("NOME_RAZAO")%>' runat="server" /> 
                            </EditItemTemplate>
                        </asp:TemplateField>

                         <asp:TemplateField HeaderText="CPF/CNPJ">
                            <ItemTemplate>
                                <asp:Label Text='<%# Eval("CPF_CNPJ")%>' runat="server" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:TextBox ID="txtCpfCnpj" Text='<%# Eval("CPF_CNPJ")%>' runat="server" /> 
                            </EditItemTemplate>
                        </asp:TemplateField>

                         <asp:TemplateField HeaderText="Usuário">
                            <ItemTemplate>
                                <asp:Label Text='<%# Eval("USUARIO_LOGIN")%>' runat="server" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:TextBox ID="txtUsuario" Text='<%# Eval("USUARIO_LOGIN")%>' runat="server" /> 
                            </EditItemTemplate>
                        </asp:TemplateField>

                         <asp:TemplateField>
                            <ItemTemplate>
                                <asp:ImageButton ImageUrl="~/img/edit.png" runat="server" CommandName="Edit" ToolTip="Edit" width="20px" Height="20px" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:ImageButton ImageUrl="~/img/save.png" runat="server" CommandName="Update" ToolTip="Update" width="20px" Height="20px" />
                                <asp:ImageButton ImageUrl="~/img/cancel.png" runat="server" CommandName="Cancel" ToolTip="Cancel" width="20px" Height="20px" />
                            </EditItemTemplate>
                        </asp:TemplateField>
                     </Columns>

                 </asp:GridView>

             </div>

            <div class="labelBanco">
                <asp:Label ID="lblId" runat="server" Visible="False"></asp:Label>
                <asp:Label ID="lblTipo" runat="server" Visible="False"></asp:Label>
            &nbsp;
                <asp:Label ID="lblValidacao" runat="server"></asp:Label>
            </div>

            <div class="mudarSenha">

                <asp:Button ID="btnMudarSenha" runat="server" OnClick="btnMudarSenha_Click" Text="Mudar Senha" Font-Bold="True" Font-Size="Medium" cssClass="btn"/>

            </div>
        </div>
    </form>
</body>
</html>
