#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string pathcsv) : path(pathcsv) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	path = src.getPath();
}

std::string BitcoinExchange::getPath() const {
	return path;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	path = rhs.getPath();
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::printMap() {
	std::map<std::string, float>::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout << "Date: " << it->first << ", Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
		++it;
	}
}

std::map<std::string, float>::iterator BitcoinExchange::findNearestDate(int year, int month, int day) {
	std::map<std::string, float>::iterator it = data.begin();
	while (++it != data.end())
	{
		std::string dataDate = it->first;
		int dataYear = std::stoi(dataDate.substr(0, 4));
		int dataMonth = std::stoi(dataDate.substr(5, 7));
		int dataDay = std::stoi(dataDate.substr(8, 10));
		if (dataYear == year && dataMonth == month && dataDay == day)
		{
			++it;
			break;
		}
		if (dataYear < year)
			continue;
		if (dataMonth < month)
			continue;
		if (dataDay < day)
			continue;
		break;
	}
	--it;
	return (it);
}

float BitcoinExchange::checkDate(std::string date) {
	int		year, month, day;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cout << "Error: bad date format" << std::endl;
		return (-1);
	}
	year = std::stoi(date.substr(0, 4));
	month = std::stoi(date.substr(5, 7));
	day = std::stoi(date.substr(8, 10));

	if (year <= 2008 || (year == 2009 && month == 1 && day == 1))
	{
		std::cout << "Error: too early to own bitcoins" << std::endl;
		return (-1);
	}
	if (month > 12 || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
		day > 31 || (month == 2 && day > 29) || (month == 2 && year % 4 != 0 && day > 28))
	{
		std::cout << "Error: bad date" << std::endl;
		return (-1);
	}
	std::map<std::string, float>::iterator nearestDate = findNearestDate(year, month, day);
	return (nearestDate->second);
}

void BitcoinExchange::checkBalance() {
	std::ifstream	file(path);
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: failed to open the txt file");
	std::getline(file, line);
	if (line.compare("date | value") != 0)
		std::runtime_error("Error: invalid input format");
	while (std::getline(file, line))
	{
		int flag = 0;
		size_t i;
		for (i = 0; i < line.length(); i++)
		{
			if (line[i] == '|')
				break;
			if (i + 1 == line.length())
			{
				std::cout << "Error: bad input => " << line << std::endl;
				flag = 1;
			}
		}
		if (flag)
			continue;
		std::string date = line.substr(0, i - 1);
		float price = checkDate(date);
		if (price < 0)
			continue;
		try
		{
			float acc = stof(line.substr(i + 1));
			if (acc > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			if (acc < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			float value = price * acc;
			std::cout << date << " => " << stof(line.substr(i + 1)) << " = " << value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
}

void BitcoinExchange::func() {
	fillData();
	checkBalance();
}

void BitcoinExchange::fillData() {
	std::ifstream	file("./data.csv");
	std::string		line;
	float			value;

	if (!file.is_open())
		throw std::runtime_error("Error: failed to open data.csv");
	std::getline(file, line);
	while(std::getline(file, line))
	{
		size_t i;
		for (i = 0; i < line.length(); i++)
		{
			if (line[i] == ',')
				break;
			if (i + 1 == line.length())
				throw std::runtime_error("Error: bad data");
		}
		std::string date = line.substr(0, i);
		value = std::stof(line.substr(i + 1));
		data.insert(std::make_pair(date, value));
	}
	file.close();
}
