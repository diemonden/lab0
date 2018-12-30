#include "Sphere.h"
#include <iostream>

const std::string & Sphere::getName() const {
	return *(new std::string("Sphere"));
}

int Sphere::execute(const std::map<std::string, std::string>& args) {
	for (auto it = args.begin(); it != args.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
	system("pause");
	return 0;
}

