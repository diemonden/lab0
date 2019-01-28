#include "Sphere.h"
#include <iostream>

TriangleSoup sphereMesh;
STLParser sphere;

const std::string & Sphere::getName() const {
	return *(new std::string("Sphere"));
}

int Sphere::execute(const std::map<std::string, std::string>& args) {
	for (auto it = args.begin(); it != args.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
	
	double R = stod(args.find("R")->second);

	double x = atof(args.find("origin")->second.c_str());
	double y = atof(strchr(args.find("origin")->second.c_str(), ' '));
	double z = atof(strchr(args.find("origin")->second.c_str()+1, ' '));

	std::string filepath = args.find("filepath")->second;
	
	//https://stackoverflow.com/questions/17705621/algorithm-for-a-geodesic-sphere
	//http://www.hugi.scene.org/online/coding/hugi%2027%20-%20coding%20corner%20polaris%20sphere%20tessellation%20101.htm
	//http://www.opengl.org.ru/docs/pg/0208.html
	sphere.write(sphereMesh, "C:\\Users\\mc dondo\\3D Objects\\sphere.stl");// вставить переменную
	
	system("pause");
	return 0;
}

