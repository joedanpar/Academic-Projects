<html>
<head>
<title>Change Your Password</title>
<style type="text/css">
<!--
.style1 {color: #CA0000}
body {
	background-color: #999;
}
-->
</style>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"></head>

<body leftmargin="0" topmargin="0" marginwidth="0" marginheight="0">

<table width=700 border="1" cellpadding="0" cellspacing="0" style="border-collapse: collapse; border-width: 0" bordercolor="#111111" align="center" id="AutoNumber1" height="244">
  <tr>
    <td width="100%" style="border-style: none; border-width: medium" bgcolor="#E2E2E2" height="68" valign="top">
    <table border="1" cellpadding="0" cellspacing="0" style="border-collapse: collapse; border-width: 0" bordercolor="#111111" width="100%" id="AutoNumber5" height="72">
      <tr>
        <td>
         <img src="roshambobanner.jpg" name="Roshambo">
        </td>
      </tr>
    </table>
    </td>
  </tr>
  <tr>
    <td width="100%" style="border-style: none; border-width: medium" height="14">
    <table border="1" cellpadding="0" cellspacing="0" style="border-collapse: collapse; border-width: 0" bordercolor="#111111" width="100%" id="AutoNumber2">
    <tr>
      <td width="20%" bgcolor="#000000" bordercolor="#E2E2E2" style="border-left-style: none; border-left-width: medium; border-top-style: none;
border-top-width: medium; border-bottom-style: none; border-bottom-width: medium" align="center">
      <b><font face="Arial" size="2" color="#FFFFFF"><a href="about_us.html">About Us</a></font></b></td>
      <td width="20%" bgcolor="#000000" bordercolor="#E2E2E2" style="border-top-style: none; border-top-width: medium; border-bottom-style:
none; border-bottom-width: medium" align="center">
      <b><font face="Arial" size="2" color="#FFFFFF"><a href="course_info.html">Course Information</a></font></b></td>
    </tr>

    </table>
    </td>
  </tr>
  <tr>
    <td width="100%" style="border-style: none; border-width: medium" height="123" valign="top">
    <table border="1" cellpadding="0" cellspacing="0" style="border-collapse: collapse; border-width: 0" bordercolor="#111111" width="100%" id="AutoNumber6">
      <tr>
        <td width="20%" style="border-style: none; border-width: medium" bgcolor="#CA0000" valign="top">
          <div align="center">
          <center>
          <p>&nbsp;</p>
          <table border="1" cellpadding="0" cellspacing="0" style="border-collapse: collapse" bordercolor="#111111" width="83%" id="AutoNumber7" height="1">
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="index.html"><img src="home.jpg" name="Home"></a></font></td>
            </tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="new_member.html"><img src="register.jpg" name="Register"></a></font></td>
            </tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="search_classes.html"><img src="classsearch.jpg" name="Class Search"></a></font></td>
            </tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="class_registration.html"><img src="classregister.jpg" name="Class Registration"></a></font></td>
            </tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="payment_information.html"><img src="payment.jpg" name="Make a payment"></a></font></td>
            </tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="check_availability.html"><img src="availability.jpg" name="Course Availability"></a></font></td>
            </tr>
            <tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="check_balance.html"><img src="checkaccount.jpg" name="Check Account"></a></font></td>
            </tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="update_membership.html"><img src="updateinfo.jpg" name="Update Info"></a></font></td>
            </tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="renew_membership.html"><img src="renew.jpg" name="Renew Membership"></a></font></td>
            </tr>
            <tr>
              <td width="100%" valign="top" bgcolor="#FFFFFF" height="1" bordercolor="#CA0000">
              <p>
              <font face="Arial" size="2"><a href="change_password.html"><img src="password.jpg" name="Change Password"></a></font></td>
            </tr>
          </table>
          </center>
        </div>
        <p>&nbsp;</p>
        <p>&nbsp;</p>        
        </td>
        <td width="75%" rowspan="2" valign="top" bgcolor="#FFFFFF" style="border-style: none; border-width: medium"><h1 align="center" style="margin-left: 4; margin-top: 5; margin-bottom: 2; margin-right:5"><font face="Verdana, Arial, Helvetica, sans-serif"></font><font size="5" face="Verdana, Arial, Helvetica, sans-serif" color="#000000">            <br>
        Change Your Password</font></h1>
     
        <?php

$member_id = $_POST[member_id];
$password = $_POST[password];
$new_password = $_POST[new_password];
$verify = $_POST[verify];

//Create connection to server
$link = mysql_connect("localhost","USERNAME", "PASSWORD")
  or die ("Unable to connect to database");

//Select Database
mysql_select_db ("DATABASE", $link)
  or die ("Unable to select database");

//Execute query to insert user values

mysql_real_escape_string($member_id);
mysql_real_escape_string($password);
mysql_real_escape_string($new_password);
mysql_real_escape_string($verify);

$member_exists = mysql_query("SELECT MEMBER_ID FROM MEMBER WHERE MEMBER_ID = '$member_id'")
  or die("Unable to find member ID");

  while($row = mysql_fetch_assoc($member_exists))
    $real_id = $row["MEMBER_ID"];

// if ! member

$password_retrieve = mysql_query("SELECT PASSWORD FROM PASSWORD WHERE MEMBER_ID = '$real_id'")
  or die("Unable to retrieve old password for member");

  while($row = mysql_fetch_assoc($password_retrieve))
    $actual_password = $row["PASSWORD"];

  if($password != $actual_password)
    die("Incorrect Password");

  if($new_password != $verify)
    die("Passwords do not match");

if ($new_password == $verify)
  {
  mysql_query("UPDATE PASSWORD SET PASSWORD = '$new_password' WHERE MEMBER_ID = '$real_id'")
    or die("Unable to update password");
  }

echo "<center>Password has been successfully changed for member_id: $real_id!</center>";

?>

</p>

<p align="center"><a href="change_password.html">Go Back</a></p>

        <table width="100%" border="0" cellpadding="20" cellspacing="0" style="margin-bottom: 2; font-size: 24px;">
          <tr>
            <td align="center">
              </td>
          </tr>
        </table>
        </td>
      </tr>
    </table>
    </td>
  </tr>
  <tr>
    <td width="100%" style="border-style: none; border-width: medium" height="17">
    <table border="1" cellpadding="0" cellspacing="0" style="border-collapse: collapse; border-width: 0" bordercolor="#111111" width="100%" id="AutoNumber3" height="1">
      <tr>
        <td width="100%" height="1" style="border-style: none; border-width: medium" valign="top" bgcolor="#111111">&nbsp;</td>
      </tr>
      <tr>
        <td width="100%" height="18" style="border-style: none; border-width: medium" bgcolor="#CA0000">
          <p align="center"></td>
      </tr>
    </table>
    </td>
  </tr>
</table>
</body>

</html>
