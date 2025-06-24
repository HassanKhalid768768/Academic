<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Image ID="Image2" ImageUrl="https://upload.wikimedia.org/wikipedia/commons/thumb/7/7c/Facebook_New_Logo_%282015%29.svg/1280px-Facebook_New_Logo_%282015%29.svg.png" runat="server" />

        <br><br><h1><big><strong>Create an account</strong></big></h1> 

        First Name: &nbsp <asp:TextBox ID="txtPassword" TextMode="password" runat="server"></asp:TextBox>

        &nbsp &nbsp Last Name: &nbsp <asp:TextBox ID="TextBox1" TextMode="password" runat="server"></asp:TextBox>

        <br><br> Username: &nbsp <asp:TextBox ID="TextBox2" TextMode="password" runat="server"></asp:TextBox>

        <br><br> Password: &nbsp <asp:TextBox ID="TextBox3" TextMode="password" runat="server"></asp:TextBox>
      
    <br>
      
    <br> Date Of Birth: <input type="datetime-local" id="Test_DatetimeLocal">
    
         <br> <br> Country: &nbsp <asp:DropDownList ID="ddlDepartment" runat="server">
            <asp:ListItem Text="Select" Value="0"></asp:ListItem>
            <asp:ListItem Text="Pakistan"
            Value="CS"></asp:ListItem>
            <asp:ListItem Text="India"
            Value="EE"></asp:ListItem>
            <asp:ListItem Text="America"
            Value="BBA"></asp:ListItem>
            <asp:ListItem Text="Russia"
            Value="CV"></asp:ListItem>
            </asp:DropDownList>

          <br><br> Gender: &nbsp <asp:RadioButton ID="rdMale" GroupName="Gender" runat="server" /> Male
        &nbsp &nbsp <asp:RadioButton ID="rdFemale" GroupName="Gender" runat="server" /> Female <br><br>

        <asp:CheckBox ID="chkIsStudent" runat="server" /> &nbsp &nbsp Enable Privacy

        <br><br> <asp:Button ID="btnSave" Text="Create Account" runat="server" />



                <br><br><h1><big><strong><center>To illustrate form based tags </center></strong></big></h1> 

        <br><br><center>This is a text box to enter any text  &nbsp &nbsp <asp:TextBox ID="txtName" runat="server"></asp:TextBox></center> 


    </div>
    </form>
</body>
</html>


  
       
       
      