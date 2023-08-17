#include <Commands.hpp>

int cmd::user(const vector<string> &input, Person & user) // There is a different result when there is a gap.
{
	if (input.size() != 5)
	{
		Response::create().to(user).code(ERR_NEEDMOREPARAMS).content(USER_USE).send();
		return (-1);
	}
	else if (user.getActive() == HALF)
		user.setActive(U_HALF);
	user.setUserName(input[1]);
	user.setHostName(input[2]);
	user.setServName(input[3]);
	user.setRealName(input[4]);
	return (0);

}
