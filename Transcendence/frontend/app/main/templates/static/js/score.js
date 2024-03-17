(async function ()
{
	let searchUrl = new URLSearchParams(window.location.search)
	let tournamentCode = searchUrl.get("tournament");

	let people = await fetch(`http://localhost/api/tournaments/${tournamentCode}/players`)
	.then((resposne) => resposne.json);

	for (let i = 1; i < 5; i++)
		document.getElementById(`score-${i}`).src = people.content[i].user.avatarURI;
})()