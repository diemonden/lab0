#include "Parser.h"
#include <iostream>
#include <algorithm>

std::map<std::string, std::string>& Parser::getMap(int argc, char * argv[]) {
	std::map<std::string, std::string>& map = *(new std::map<std::string, std::string>());
	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "=")) {
			std::string s1 = argv[i - 1];
			std::string s2 = argv[i + 1];
			ReplaceString(s1,","," ");
			ReplaceString(s2,","," ");
			ReplaceString(s2, ")","");
			ReplaceString(s2, "(","");
			map.insert(std::pair<std::string, std::string>(s1, s2));
		}
	}
	return map;
}
std::string Parser::ReplaceString(std::string &subject, std::string search, std::string replace){	
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}/*
void Parser::deleteComma(std::string & s) {
	for (int i = 0; i < s.length(); i++) {		
		s.erase(std::remove_if(s.begin(), s.end(), &Parser::IsComma), s.end());
	}
}*/
/*
bool Parser::IsComma(char c) {
	return (c == ',');
}
*/