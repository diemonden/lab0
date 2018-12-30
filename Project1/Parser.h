#pragma once
#include <string>
#include <map>
#include <vector>

namespace Parser {
	std::map<std::string, std::string>& getMap(int argc, char *argv[]);
	std::string ReplaceString(std::string &subject, std::string search, std::string replace);

	//void deleteComma(std::string &s);
	//bool IsComma(char c);
}


