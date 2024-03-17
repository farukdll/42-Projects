var user_count = 0;
var users = {
	"left": undefined,
	"right": undefined
}

async function match_making(str) {

	let username = document.getElementById(`${str}-input`).value;
	let playcode = document.getElementById(`${str}-playcode`).value;
	let url = "http://localhost/api/matches/player/verify"
	fetch(url, {
		method: "POST",
		headers: {
			"Content-type": "application/json",
		},
		body: JSON.stringify({
			username,
			playcode
		}),
	})
		.then((response) => {
			if (response.ok)
				return response.json()
		})
		.then(responseData => {
			let data = { username, token: responseData.token };
			users[str] = responseData.user
			if (users.left != undefined && users.right != undefined && users.right.username == users.left.username) {
				alert("You need to enter different account")
				return;
			}
			document.getElementById(`${str}-photo`).src = responseData.user.avatarURI;
			document.getElementById(`${str}-ready-button`).innerText = String(responseData.user.username).toUpperCase();
			localStorage.setItem(`${str}-player-token`, JSON.stringify(data));
			document.getElementById(`${str}-expected`).disabled = true;
			user_count++
		})
		.catch(_ => alert("You have to enter your correct information"));
	// matches/player/verify

}

(function(){
	let formHome = document.getElementById("form-home")
	if (formHome != undefined)
	formHome.addEventListener('submit', (e) =>{e.preventDefault();match_making('left')} )

	let formAway = document.getElementById("form-away")
	if (formAway != undefined)
	formAway.addEventListener('submit', (e) =>{e.preventDefault();match_making('right')} )

})()

setInterval(() => {
	if (user_count == 2) {
		document.getElementById("match-snipped").style = "none";
		document.getElementById("match-tennis").style = "block";
		document.getElementById("right-expected").disabled = false;
		document.getElementById("left-expected").disabled = false;
		user_count = 0;
		setTimeout(() => {
			window.location.href = "/pvp" + window.location.search;
		}, 3000);
	}
	else {
		document.getElementById("match-snipped").style = "block";
		document.getElementById("match-tennis").style = "none";
	}
}, 10000)

/*
function ready_profile(side, where_photo)
{
	let formHome = document.getElementsByClassName(side)[0]
	formHome.addEventListener('submit', (e) => {
		e.preventDefault()
	})
	let input_username = formHome.getElementsByClassName(`${side}` + "-username")[0]
	let photo = document.getElementById(where_photo);
	let data = JSON.parse(localStorage.getItem(0));
	let username = data.user.username
	let userphoto = data.user.avatarURI;

	input_username.setAttribute("value", username);
	input_username.setAttribute("readonly", true);
	photo.src =  userphoto;
}*/

async function take_matchurl() {
	let urlSearch = new URLSearchParams(window.location.search);
	let matchcode = urlSearch.get("match");

	let readyMatch = await fetch(`http://localhost/api/matches/code/${matchcode}`, {
		method: "GET",
		headers: {
			"Content-type": "application/json",
		},
	})
		.then(response => response.json())
		.catch(error => console.log(error));

	ready_profile("form-home", "left-photo");
	ready_profile("form-away", "right-photo");
}


