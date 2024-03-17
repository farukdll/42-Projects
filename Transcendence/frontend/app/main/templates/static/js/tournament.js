//tournament.js

var users = undefined;
var map_allUser = new Map();
let map_stage = 0;
let urlSearchParam = new URLSearchParams(window.location.search)
const access_token = JSON.parse(localStorage.getItem(0)).access_token;

async function takeUsers(tournament_code) {
	if (users == undefined) {
		users = await fetch(`http://localhost/api/tournaments/${tournament_code}/players`,
			{
				headers: {
					"Content-type": "application/json",
					Authorization: `Bearer ${access_token}`,
				},
			})
			.then((response) => response.json())
			.catch((error) => console.log(error));
	}
}

async function startTournament(tournament_code) {
	let match = await fetch(`http://localhost/api/tournaments/${tournament_code}/next-match`,
		{
			method: "GET",
			headers: {
				"Content-type": "application/json",
				Authorization: `Bearer ${access_token}`,
			}
		})
		.then((response) => {
			if (response.status == 404) {
				window.location.href = "/score" + window.location.search;
			}
			return response.json()
		})
		.catch((error) => console.log(error));

	console.log("fetchMatch: ", match);
	let myHref = `/match?tournament=${tournament_code}&match=${match.match_code}`;
	console.log("myHref ", myHref);
	setTimeout(() => {
		window.location.href = myHref;
	}, 5000);
}


function haveAnyUnaccepted(){
	for (let user of users.content)
		if (!user.has_pair)
			return true;
	return false
}



async function loadTournament(){
	let tournament_code = urlSearchParam.get("tournament")
	
	if (users == undefined)
		await takeUsers(tournament_code)

	const stages = []

	function check_in_list(sub_list, list){
		for (let sl of list){
			if (sub_list[0] == sl[0] || sub_list[0] == sl[1] || sub_list[1] == sl[0] || sub_list[1] == sl[1])
				return false;
		}
		return true;
	}

	users.content.forEach( user => {
		let sub_list = [user.user.avatarURI, user.pair_user != null ? user.pair_user.avatarURI : null]
			if (check_in_list(sub_list, stages[user.stage] != undefined ? stages[user.stage] : [])){
				if (stages[user.stage] == undefined)
					stages[user.stage] = []
				stages[user.stage].push(sub_list)
			}
	})

	if (stages[2] != undefined){
		if (stages[1][0].indexOf(stages[2][0][0]) == -1)
			stages[2][0] = stages[2][0].reverse()
	}

	console.log(stages)

	const leftBoxIds = ['left-box-1', 'left-box-2','left-box-3'];
	const rightBoxIds = ['right-box-1', 'right-box-2','right-box-3'];

	let l1 = document.getElementById(leftBoxIds[0])
	let l2 = document.getElementById(leftBoxIds[1])
	let l3 = document.getElementById(leftBoxIds[2])
	let r1 = document.getElementById(rightBoxIds[0])
	let r2 = document.getElementById(rightBoxIds[1])
	let r3 = document.getElementById(rightBoxIds[2])
	let winner = document.getElementById("winner")
	let defaultImg = "/static/assets/42rush.png"

	if (stages.length >= 2) {
		l1.src = stages[1][0][0] !== null ? stages[1][0][0] : defaultImg;
		l2.src = stages[1][0][1] !== null ? stages[1][0][1] : defaultImg;
		r1.src = stages[1][1][0] !== null ? stages[1][1][0] : defaultImg;
		r2.src = stages[1][1][1] !== null ? stages[1][1][1] : defaultImg;
	}

	if (stages.length >= 3) {
		l3.src = stages[2][0][0] !== null ? stages[2][0][0] : defaultImg;
		r3.src = stages[2][0][1] !== null ? stages[2][0][1] : defaultImg;
	}

	if (stages.length >= 3) {
		l3.src = stages[2][0][0] !== null ? stages[2][0][0] : defaultImg;
		r3.src = stages[2][0][1] !== null ? stages[2][0][1] : defaultImg;
	}
	if (stages.length >= 4) {
		winner.src = stages[2][0][0] !== null ? stages[2][0][0] : defaultImg;
	}
	

	//setTimeout(() => startTournament(tournament_code))
}


var countDownDate = new Date().getTime() + 140000;

var timer = setInterval(function () {
	if (!urlSearchParam.has("match")) {
		var now = new Date().getTime();
		var distance = countDownDate - now;

		var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
		var seconds = Math.floor((distance % (1000 * 60)) / 1000);

		document.getElementById("tournament-timer").innerText = "Timer: " + minutes + "m " + seconds + "s";

		if (distance < 0) {
			document.getElementById("tournament-timer").innerText = "CANCELLED";
			clearInterval(timer)
			clearInterval(enter_tournament)

			window.location.href = "/"
		}
	}
	else {
		document.getElementById("tournament-timer").style.display = "none";
		clearInterval(enter_tournament);
		loadTournament();
	}
}, 1000);

var enter_tournament = setInterval(async () => {
	if (!urlSearchParam.has("match")) {
		let tournament_code = urlSearchParam.get("tournament");

		await takeUsers(tournament_code);
		let match_making = 0;
		console.log("how: -1-", user);
		for (let i = 0; i < users.length; i++) {
			if (users.content[i].stage == 1 && users.content[i].pair_user == null)
				continue;
			match_making++;
		}
		if (match_making > 3) {
			clearInterval(timer);
			document.getElementById("tournament-timer").style.display = "none";
			clearInterval(enter_tournament);
			loadTournament();
		}
	}
	else {
		document.getElementById("tournament-timer").style.display = "none";
		clearInterval(enter_tournament);
		loadTournament();
	}
}, 7000);


