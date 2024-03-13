#include <iostream>
#include <string>
#include <fstream>

bool argErr(int ac, char *av[])
{
	if (ac != 4) {
		std::cout << "argument count isn't 4\n";
		return false;
	}
	else if (!av[1][0]) {
		std::cout << "No such file\n";
		return false;
	}
	else if (!av[2][0]) {
		std::cout << "empty string, err replace\n";
		return false;
	}
	return true;
}

int main(int ac, char *av[])
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string	replaceFile;
	std::string line;
	int s1Len;
	int s2Len;

	if (!argErr(ac, av)) {
		return 1;
	}

	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	s1Len = s1.length();
	s2Len = s2.length();

	inputFile.open(filename.c_str());
	if (!inputFile.is_open()) {
		std::cout << "Failed to open the file.\n";
		return (1); 
	}
	
	replaceFile = av[1];
	replaceFile.append(".replace");
	outputFile.open(replaceFile.c_str());
	if (!outputFile.is_open()) {
		std::cout << "Failed to open the file.\n";
		return (1);
	}

	while (true) {
		std::getline(inputFile, line);
		size_t pos = 0;
		while (true) {
			pos = line.find(s1, pos);
			if (pos == std::string::npos) {
				break ;
			}
			line.erase(pos, s1Len);
			line.insert(pos, s2);
			pos += s2Len;
		}
		outputFile << line;
		if (inputFile.eof()) {
			break ;
		}
		outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();

	return 0;
}
