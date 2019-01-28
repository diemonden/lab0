#include "Sphere.h"
#include <iostream>

TriangleSoup sphereMesh(12);

const std::string & Sphere::getName() const {
	return *(new std::string("Sphere"));
}

int Sphere::execute(const std::map<std::string, std::string>& args) {
	for (auto it = args.begin(); it != args.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
	/*
	double L = stod(args.find("R")->second);

	double x = atof(args.find("origin")->second.c_str());
	double y = atof(strchr(args.find("origin")->second.c_str(), ' '));
	double z = atof(strchr(args.find("origin")->second.c_str(), ' ') + 4);

	std::string filepath = args.find("filepath")->second;
	


	obj.write(sphereMesh, "C:\\Users\\mc dondo\\3D Objects\\sphere.stl");// вставить переменную
	*/
	system("pause");
	return 0;
}

