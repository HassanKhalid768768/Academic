<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="WebApplication3.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <br><br> Name: &nbsp <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox> 

        <br><br> Password: &nbsp <asp:TextBox ID="txtPassword" TextMode="password" runat="server"></asp:TextBox>

        <br><br> Text: &nbsp <asp:TextBox ID="txtTextValue" Text="Hello World!" runat="server"></asp:TextBox>

        <br><br> Comment: &nbsp <asp:TextBox ID="txtComment" TextMode="multiline" runat="server"></asp:TextBox>

        <br><br> Is Student: &nbsp <asp:CheckBox ID="chkIsStudent" runat="server" />

        <br><br> Gender: &nbsp &nbsp  Male:  &nbsp <asp:RadioButton ID="rdMale" GroupName="Gender" runat="server" />
        &nbsp &nbsp Female:  &nbsp <asp:RadioButton ID="rdFemale" GroupName="Gender" runat="server" />

        <br><br> Department: &nbsp <asp:DropDownList ID="ddlDepartment" runat="server">
            <asp:ListItem Text="Select" Value="0"></asp:ListItem>
            <asp:ListItem Text="Computer Science"
            Value="CS"></asp:ListItem>
            <asp:ListItem Text="Electrical Engineering"
            Value="EE"></asp:ListItem>
            <asp:ListItem Text="Business Administrator"
            Value="BBA"></asp:ListItem>
            <asp:ListItem Text="Civil Engineering"
            Value="CV"></asp:ListItem>
            </asp:DropDownList>

        <br><br> <asp:Button ID="btnSave" Text="Save Form" runat="server" />


    </div>
    </form>
</body>
</html>


  
       
       
      