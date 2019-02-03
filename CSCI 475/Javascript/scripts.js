window.onload = initAll;

function initAll(){
document.getElementById("hover").onmouseover = initHover;
document.getElementById("candy").onclick = initFreeCandy;
document.getElementById("beginclick").onmousedown = initHoldme;
document.getElementById("average").onclick = initAverage;
document.getElementById("holdme").onmouseout = initLeave;
document.getElementById("letgo").onmouseup = initLetgo;
}

function initFreeCandy(){
	popup1 = window.open("popup.html","Just Kidding!","menubar=no,width=700,height=450,toolbar=no,resizable=no,titlebar=no,status=no,scrollbars=no,location=no");
	return false;
}

function initLeave(){
	alert('Wait! Don\'t leave me! D:');
	return false;
}

function initHover(){
	alert('Hello world!');
	return false;
}

function initHoldme(){
	document.bgColor = "#FFAAAA";
	return true;
}

function initLetgo(){
	document.bgColor = "#444488";
	return true;
}

function initAverage(){
	var	numa = document.getElementById('num1');
	var	numb = document.getElementById('num2');
	var	numc = document.getElementById('num3');
	var	numd = document.getElementById('num4');
		
//document.getElementById("average").submit();
	if (isNum(numa.value, 3, 'The first field does not contain a valid number. Please enter a valid number') &&
	isNum(numb.value, 3, 'The second field does not contain a valid number. Please enter a valid number') &&
	isNum(numc.value, 3, 'The third field does not contain a valid number. Please enter a valid number') &&
	isNum(numd.value, 3, 'The fourth field does not contain a valid number. Please enter a valid number')){
		var a = new Number(numa.value);
		var b = new Number(numb.value);
		var c = new Number(numc.value);
		var d = new Number(numd.value);
		var total = a + b + c + d;
		var average = total / 4;
		if (rangeCheck(total, 'The total of all four numbers is not between 1 and 100.  Please input better numbers')){
			setCookie('myCookie', average, 30);
			window.open("popup2.html", "The average is...", "menubar=no,width=700,height=450,toolbar=no,resizable=no,titlebar=no,status=no,scrollbars=no,location=no");
			return true;
		}
	return false;
	}
}

function isNum(strFieldValue, size, strAlert){
	for ( var i=0; i < size; i++){
		if(strFieldValue.charAt(i)!="" ){	    
			if( strFieldValue.charAt(i) < "0" || strFieldValue.charAt(i) > "9"){
				if(strAlert != "")alert(strAlert)
					return false;
				}
			}
		}
	return true;
}

function rangeCheck(num, strAlert){
	if(num > 100 || num < 1){
		alert(strAlert);
		return false;
	}
	return true;
}

function setCookie(c_name, value, expiredays){
	var exdate = new Date();
	exdate.setDate(exdate.getDate() + expiredays);
	document.cookie=c_name + "=" + escape(value) + ((expiredays == null) ? "" : ";expires=" + exdate.toUTCString());
}

function getCookie(c_name){
	if (document.cookie.length > 0)
	{
		c_start = document.cookie.indexOf(c_name + "=");
		if (c_start != -1)
		{
			c_start=c_start + c_name.length + 1;
			c_end=document.cookie.indexOf(";", c_start);
			if (c_end == -1) c_end = document.cookie.length;
				return unescape(document.cookie.substring(c_start,c_end));
		}
	}
	return "";
}