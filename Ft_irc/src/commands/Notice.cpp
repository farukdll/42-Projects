#include <Commands.hpp>

int cmd::notice(const vector<string> &input, Person & from)
{
	if (input.size() != 3)
	{
		Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(NOTICE_USE).send();
		return (-1);
	}
	string	msg = just_text();

	sendGroup(from, input[1], msg);
	return (0);
}
 