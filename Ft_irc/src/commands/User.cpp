#include "../../inc/Commands.hpp"

int cmd::user(const vector<string> &input, User& user) // When there is a space, the result is different.
{
	if (user.getActive() < HALF || input.size() != 5)
		return (-1);
	cout << "I'm a half" << endl;
	user.setUserName(input[1]);
	user.setHostName(input[2]);
	user.setServName(input[3]);
	user.setRealName(input[4]);
	return (0);

}
