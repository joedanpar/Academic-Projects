<html>
<head>
<title>Make A Payment</title>
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
        Please Enter Your Payment Information</font></h1>
      
        <?php

$member_id = $_POST[member_id];
$password = $_POST[password];
$payment_type = $_POST[payment_type];
$card_number = $_POST[card_number];
$card_expiration_month = $_POST[card_expiration_month];
$card_expiration_year = $_POST[card_expiration_year];
$payment_amount = $_POST[payment_amount];
$current_date = date('m-Y');
$current_month = date('m');
$current_year = date('Y');


mysql_real_escape_string($member_id);
mysql_real_escape_string($password);
mysql_real_escape_string($payment_type);
mysql_real_escape_string($card_number);
mysql_real_escape_string($card_expiration_month);
mysql_real_escape_string($card_expiration_year);
mysql_real_escape_string($payment_amount);


//Create connection to server
$link = mysql_connect("localhost","USERNAME","PASSWORD")
      or die ("Unable to connect to database");

//Select Database
mysql_select_db ("DATABASE", $link)
      or die ("Unable to select database");
      

  if ($member_id == null)
    die("You must enter a member ID");

$query_exists = mysql_query("SELECT MEMBER_ID FROM MEMBER WHERE MEMBER_ID = '$member_id'")
  or die("Unable to find member ID");

  while($row = mysql_fetch_assoc($query_exists))
    $member_exists = $row["MEMBER_ID"];

  if($member_exists == null || $member_exists == "")
    die("Member ID does not exist");

  if ($password == null)
    die("You must enter a password");

$password_retrieve = mysql_query("SELECT PASSWORD FROM PASSWORD WHERE MEMBER_ID = '$member_id'")
  or die("Unable to retrieve password from database");
  
  while($row = mysql_fetch_assoc($password_retrieve))
    $actual_password = $row["PASSWORD"];

  if ($password != $actual_password)
    die("Incorrect Password");

  if ($payment_type == null)
    die("You must select a payment type");

  if ($card_number == null)
    die("You must enter a Card Number");

  if ($card_expiration_month == null || $card_expiration_year == null)
    die("Please enter an expiration date for your card");

  if ($card_expiration_year < $current_year)
    die("The card you have entereed has expired");

  if ($card_expiration_year == $current_year)
    {
    if($card_expiration_month <= $current_month)
      die("The card you have entered has expired");
    }

  if ($payment_amount == null || $payment_amount <= 0)
    die("You must enter a value between 1 and the amount owed");

  if ($payment_type == "visa" && strlen($card_number) < 16)
    die("Please enter a 16 digit Visa card number.");

  if ($payment_type == "mastercard" && strlen($card_number) < 16)
    die("Please enter a 16 digit Mastercard number.");

  if ($payment_type == "amex" && strlen($card_number) != 15)
    die("Please enter a 15 digit American Express card number");

  if ($payment_amount < 0)
    die("You can not pay with a negative amount.");


$found_member_id = mysql_query("SELECT MEMBER_ID FROM MEMBER WHERE MEMBER_ID = '$member_id';")
  or die("Unable to find member ID entered");
	
//set variable to the member_id 
while ($row = mysql_fetch_assoc ($found_member_id))
  $data1 = $row["MEMBER_ID"];

	mysql_query("REPLACE INTO CARDINFO(MEMBER_ID, CARD_NUMBER, CARD_TYPE, EXPIRATION)
	VALUES ('$data1', '$card_number', '$payment_type', '$card_expiration')");
	
	
	$current_balance = mysql_query("SELECT BALANCE FROM MEMBER WHERE MEMBER_ID = '$data1';")
	  or die("Unable to find balance for member ID");
	  
	while ($row = mysql_fetch_assoc ($current_balance))
	  $member_balance = $row["BALANCE"];

        $old_balance = $member_balance;

	$member_balance = $member_balance - $payment_amount;

        if ($old_balance == null || $old_balance == 0)
	  die("You do not currently have a balance.");

	if ($member_balance < 0)
	  die("Payment is greater than amount owed! Please make a payment of $$old_balance or less.");
	  
	mysql_query("UPDATE MEMBER SET BALANCE = '$member_balance' WHERE MEMBER_ID = '$data1';")
	  or die("Unable to re-insert balance");

echo '<br>';
echo "<center>Success! Your remaining balance is: $$member_balance</center>";

mysql_close($link);

?>

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
