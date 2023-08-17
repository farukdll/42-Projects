#include <Commands.hpp>

bool	inChannel(vector<Person *> users, string name)
{
	int	i = 0;

	for (; i < users.size(); i++)
	{
		if (users[i]->getNickName() == name)
			return (true);
	}
	return (false);
}

int cmd::kick(const vector<string> &input, Person & from)
{
	if (input.size() != 3)
	{
		Response::withCode(ERR_NEEDMOREPARAMS).to(from).content(KICK_USE).send();
		return (-1);
	}
	if (!find_channel(input[1], from))
	{
		Response::withCode(ERR_NOSUCHCHANNEL).to(from).content(input[1] + NO_CHANNEL).send();
		return (-1);
	}
	if (!isEqual(start.getChannel(input[1])[0]->getNickName(), from.getNickName(), 1))
	{
		Response::withCode(ERR_NOTONCHANNEL).to(from).content(input[0] + NO_OPER).send();
		return (-1);
	}
	if (!inChannel(start.getChannel(input[1]), input[2]))
	{
		Response::withCode(ERR_USERNOTINCHANNEL).to(from).content(input[2] + " " + input[1] + USER_NOT_IN).send();
		return (-1);
	}
	Person							*to = start.getUserNick(input[2]);
	vector<Person *>				channel = start.getChannel(input[1]);
	int								i = 0;

	Response().create().content(KICK_TO).from(from).to(*to).send();
	for (; i < channel.size(); i++)
	{
		if (channel[i]->getNickName() == to->getNickName())
		{
			from.delOperator(input[1]);
			channel.erase(channel.begin()+i);
			if (channel.size() == 0)
				start.getChannels().erase(input[1]);
		}
		/**
		 * Channel delete: One of the channels is deleted, and the channel can be completely eradicated; the user is also deleted from the channel.
		 * User delete: The person is deleted straight away.
		*/
	}
	return (0);
}
