#include "Split.h"
#include <iostream>

const std::string & Split::getName() const {
	return *(new std::string("Split"));
}

int Split::execute(const std::map<std::string, std::string>& args) {
	for (auto it = args.begin(); it != args.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
	system("pause");
	return 0;
}


