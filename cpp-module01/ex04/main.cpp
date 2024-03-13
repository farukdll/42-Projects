#include<iostream>
#include<fstream>

int main(int argc, char *argv[]) {
    if (argc != 4)
    {
        std::cout << "Usage: ./find_and_replace [fileName] [search] [replace]" << std::endl;
        return (1);
    }    

    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string singleLine;
    
    size_t position = 0;
    int s1Length = s1.length();
    int s2Length = s2.length();
    
    if (fileName.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Arguments cannot be empty" << std::endl;
		return (1);
	}
    std::ifstream readFile(fileName);
    if (!readFile.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		return (2);
	}
    std::ofstream writeFile((fileName + ".replace"),std::ios::trunc);
    if (!writeFile.is_open())
	{
		std::cout << "File cannot be opened" << std::endl;
		return (3);
	}
    while (std::getline(readFile, singleLine))
    {
        while ((position = singleLine.find(s1, position)) != std::string::npos)
        {
            singleLine.erase(position, s1Length);
            singleLine.insert(position, s2);
            position = position + s2Length;
        }
        writeFile << singleLine << std::endl;
        position = 0;
    }
    return (0);
}
