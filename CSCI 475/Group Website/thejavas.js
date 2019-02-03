window.onload = initAll;

function initAll(){
document.getElementById("bluet").onclick = initBlue;
document.getElementById("redt").onclick = initRed;
document.getElementById("blackt").onclick = initBlack;
document.getElementById("greent").onclick = initGreen;
}

function bgstuff(){
	var theme = getCookie("niugdatheme");
	
	if(theme == "blue"){
		initBlue();
	}
	else if(theme=="black"){
		initBlack();
	}
	else if(theme=="green"){
		initGreen();
	}
	else{
		initRed();
	}
}



function initBlue(){
setCookie("niugdatheme", "blue", 30);
document.getElementById("pants").style.backgroundColor = '#5c5cf0';
document.getElementById("pants").style.backgroundImage = 'url(images/homebg_blue.png)';
document.getElementById("pants").style.backgroundRepeat = 'repeat-x'
document.getElementById("navlink").style.color = '#0f0f5b';
}

function initRed(){
setCookie("niugdatheme", "red", 30);
document.getElementById("pants").style.backgroundColor = '#D44040';
document.getElementById("pants").style.backgroundImage = 'url(images/homebg_red.png)';
document.getElementById("pants").style.backgroundRepeat = 'repeat-x'
document.getElementById("navlink").style.color = '#4c0000';
}

function initBlack(){
setCookie("niugdatheme", "black", 30);
document.getElementById("pants").style.backgroundColor = '#6c6c6c';
document.getElementById("pants").style.backgroundImage = 'url(images/homebg_black.png)';
document.getElementById("pants").style.backgroundRepeat = 'repeat-x'
document.getElementById("navlink").style.color = '#171717';
}

function initGreen(){
setCookie("niugdatheme", "green", 30);
document.getElementById("pants").style.backgroundColor = '#14a81b';
document.getElementById("pants").style.backgroundImage = 'url(images/homebg_green.png)';
document.getElementById("pants").style.backgroundRepeat = 'repeat-x'
document.getElementById("navlink").style.color = '#012701';
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