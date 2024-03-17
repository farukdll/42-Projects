var right_user = JSON.parse(localStorage.getItem("left-player-token")).user;
var left_user = JSON.parse(localStorage.getItem("right-player-token")).user;

(function () {
	console.log("right_user: ", right_user);
	console.log("left_user: ", left_user);

	document.getElementById("right-player-token").src = right_user.avatarURI;
	document.getElementById("left-player-token").src = left_user.avatarURI;
})()

