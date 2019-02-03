<html>
<head>
<title>Register New Membership</title>
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
        Sign Up!</font></h1>

  <table width="100%" align="center">

        <?php

  $link = mysql_connect("localhost","USERNAME","PASSWORD");
    if (!$link)
      {
	  die('Could not connect: ' .mysql_error());
      }
      
    $first_name = $_POST[first_name];
    $last_name = $_POST[last_name];
    $password = $_POST[password];
    $verify = $_POST[verify];
    $street_address = $_POST[street_address];
    $city = $_POST[city];
    $state = $_POST[state];
    $zip = $_POST[zip];
    $phone_number = $_POST[phone_number];
    $email = $_POST[email_address];
    $member_level = $_POST[member_level];
    $current_date = date('Y-m-d');
    $timestamp = mktime(0,0,0,date("m"),date("d"),date("Y")+1);
    $expiration_date = date('Y-m-d', $timestamp);
    

    mysql_real_escape_string($first_name);
    mysql_real_escape_string($last_name);
    mysql_real_escape_string($password);
    mysql_real_escape_string($verify);
    mysql_real_escape_string($street_address);
    mysql_real_escape_string($city);
    mysql_real_escape_string($state);
    mysql_real_escape_string($zip);
    mysql_real_escape_string($phone_number);
    mysql_real_escape_string($email);
    mysql_real_escape_string($member_level);


  if($password != $verify)
    die("<center>Password fields do not match</center>");

  if(strlen($zip) < 5 && $member_id != null)
    die("<center>Zip Code needs to be 5 digits.</center>");

  if(strlen($phone_number) < 10 && $member_id != null)
    die("<center>Phone number must be 10 digits.</center>");


  $db_selected = mysql_select_db('DATABASE', $link);
    if(!$db_selected)
      {
	  die('Unable to "use" database' .mysql_error());
      }
      
  if($first_name != null && $last_name != null && $password != null && $verify != null && $street_address != null && $city != null && $state != null && $zip != null && $phone_number != null && $email != null && $member_level != null)
    {

  if ($member_level == "gold")
    $member_level_cost = 150;

  else if ($member_level == "silver")
    $member_level_cost = 125;

  else
    $member_level_cost = 100;


	//insert user-supplied values into member table
	mysql_query("INSERT INTO MEMBER (LAST_NAME, FIRST_NAME, STREET, CITY, STATE, ZIP, PHONE, EMAIL, BALANCE, MEMBERSHIP_TYPE, DATE_STARTED, 
MEMBERSHIP_EXP)
	VALUES ('$last_name', '$first_name', '$street_address', '$city', '$state', '$zip', '$phone_number', '$email', '$member_level_cost', '$member_level', 
'$current_date', '$expiration_date')");

        //query the database for the member_id
	$member_id = mysql_query("SELECT MAX(MEMBER_ID) AS MEMBER_ID FROM MEMBER WHERE LAST_NAME LIKE '$last_name' AND FIRST_NAME LIKE '$first_name'")
	  or die("Unable to retrieve member ID");

        //set variable to the member_id 
	while ($row1 = mysql_fetch_assoc($member_id))
         $data1 = $row1["MEMBER_ID"];

    mysql_query("INSERT INTO PASSWORD (MEMBER_ID, PASSWORD) VALUES('$data1','$password')")
      or die("Unable to insert password into table");

        echo '<tr><td>',"",'</td></tr>';
	echo '<p align="center">',"Success!",'</p>';
	echo '<tr><td>',"First Name: $first_name",'</td></tr>';
	echo '<tr><td>',"Last Name: $last_name",'</td></tr>';
	echo '<tr><td>',"Street Address: $street_address",'</td></tr>';
	echo '<tr><td>',"City: $city",'</td></tr>';
	echo '<tr><td>',"State: $state",'</td></tr>';
	echo '<tr><td>',"Zip: $zip",'</td></tr>';
	echo '<tr><td>',"Phone Number: $phone_number",'</td></tr>';
	echo '<tr><td>',"Email: $email",'</td></tr>';
	echo '<tr><td><b>',"Your member ID is: $data1",'</b></td></tr>';


mysql_close($link);

    }

  else
    {
    echo "<center>Please Complete all fields",'</br>';
    echo "Please press your back button</center>";
    echo '</table>';
    }
    
    

  ?>

</table>

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
