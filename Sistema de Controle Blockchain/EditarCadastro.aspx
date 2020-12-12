<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="EditarCadastro.aspx.cs" Inherits="SistemaBlockchain.EditarCadastro" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Editar Cadastros</title>

    <link rel="stylesheet" href="css/StyleEditarCadastro.css" />

</head>
<body>
    <form class="form1" id="form1" runat="server">
        <div class="card">

            <asp:Label ID="lblTitulo" runat="server" Text="Editar Cadastros" CssClass="title"></asp:Label>

            <div class="img">
                
                <asp:Button ID="btnSair" runat="server" Text="Sair" cssClass="asText" OnClick="btnSair_Click"/> <br />
                <asp:Button ID="btnMenu" runat="server" Text="Menu" cssClass="asText" OnClick="btnMenu_Click"/>
                
            </div>

            <div class="grid">

                <br />

                <asp:GridView ID="dgCadastros" runat="server" AutoGenerateColumns="False" Width="100%" ShowFooter="true" OnRowCommand="dgCadastros_RowCommand" OnRowEditing="dgCadastros_RowEditing" OnRowCancelingEdit="dgCadastros_RowCancelingEdit" OnRowUpdating="dgCadastros_RowUpdating" OnRowDeleting="dgCadastros_RowDeleting">

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
                            <FooterTemplate>
                                <asp:TextBox ID="txtNomeRazaoFooter" runat="server" />
                            </FooterTemplate>
                        </asp:TemplateField>

                        <asp:TemplateField HeaderText="CPF/CNPJ">
                            <ItemTemplate>
                                <asp:Label Text='<%# Eval("CPF_CNPJ")%>' runat="server" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:TextBox ID="txtCpfCnpj" Text='<%# Eval("CPF_CNPJ")%>' runat="server" /> 
                            </EditItemTemplate>
                            <FooterTemplate>
                                <asp:TextBox ID="txtCpfCnpjFooter" runat="server" />
                            </FooterTemplate>
                        </asp:TemplateField>

                        <asp:TemplateField HeaderText="Usuário">
                            <ItemTemplate>
                                <asp:Label Text='<%# Eval("USUARIO_LOGIN")%>' runat="server" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:TextBox ID="txtUsuario" Text='<%# Eval("USUARIO_LOGIN")%>' runat="server" /> 
                            </EditItemTemplate>
                            <FooterTemplate>
                                <asp:TextBox ID="txtUsuarioFooter" runat="server" />
                            </FooterTemplate>
                        </asp:TemplateField>

                        <asp:TemplateField HeaderText="Senha">
                            <ItemTemplate>
                                <asp:Label Text='<%# Eval("SENHA_LOGIN")%>' runat="server" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:TextBox ID="txtSenha" Text='<%# Eval("SENHA_LOGIN")%>' runat="server" /> 
                            </EditItemTemplate>
                            <FooterTemplate>
                                <asp:TextBox ID="txtSenhaFooter" runat="server" />
                            </FooterTemplate>
                        </asp:TemplateField>

                        <asp:TemplateField HeaderText="Tipo de Usuário">
                            <ItemTemplate>
                                <asp:Label Text='<%# Eval("TIPO_USUARIO")%>' runat="server" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:TextBox ID="txtTipo" Text='<%# Eval("TIPO_USUARIO")%>' runat="server" /> 
                            </EditItemTemplate>
                            <FooterTemplate>
                                <asp:TextBox ID="txtTipoFooter" runat="server" />
                            </FooterTemplate>
                        </asp:TemplateField>

                        <asp:TemplateField>
                            <ItemTemplate>
                                <asp:ImageButton ImageUrl="~/img/edit.png" runat="server" CommandName="Edit" ToolTip="Edit" width="20px" Height="20px" />
                                <asp:ImageButton ImageUrl="~/img/deletar.png" runat="server" CommandName="Delete" ToolTip="Delete" width="20px" Height="20px" />
                            </ItemTemplate>
                            <EditItemTemplate>
                                <asp:ImageButton ImageUrl="~/img/save.png" runat="server" CommandName="Update" ToolTip="Update" width="20px" Height="20px" />
                                <asp:ImageButton ImageUrl="~/img/cancel.png" runat="server" CommandName="Cancel" ToolTip="Cancel" width="20px" Height="20px" />
                            </EditItemTemplate>
                            <FooterTemplate>
                                <asp:ImageButton ImageUrl="~/img/add.png" runat="server" CommandName="AddNew" ToolTip="AddNew" width="20px" Height="20px" />
                            </FooterTemplate>
                        </asp:TemplateField>
                    </Columns>
                </asp:GridView>

            </div>

            <div>

                <br />

                <asp:Label ID="lblId" runat="server" Visible="False"></asp:Label>
                <asp:Label ID="lblTipo" runat="server" Visible="False"></asp:Label>
&nbsp;
                <asp:Label ID="lblValidacao" runat="server"></asp:Label>

            </div>

        </div>


    </form>
</body>
</html>
