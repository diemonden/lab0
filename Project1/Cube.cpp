#include "Cube.h"
#include <iostream>
const std::string & Cube::getName() const {
	return *(new std::string("Cube"));
}

int Cube::execute(const std::map<std::string, std::string>& args) {
	for (auto it = args.begin(); it != args.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}	
	double L = stod(args.find("L")->second);
	if (L <= 0) { 		
		std::cout << "error #1: Length <= 0" << std::endl;
		system("pause");
		return 1; }

	Vec origin = { atof(args.find("origin")->second.c_str()) ,
				   atof(strchr(args.find("origin")->second.c_str(), ' ')) ,
				   atof(strchr(args.find("origin")->second.c_str() + 1, ' '))
	};

	std::string filepath = args.find("filepath")->second;

	if (_access(filepath.substr(0, filepath.find_last_of('\\')).c_str(),2) == -1) {
		std::cout << "error #2: filepath is incorrect" << std::endl; 
		system("pause");
		return 2; }
	TriangleSoup cubeMesh;
	STLParser cube;
	cubeMesh =
	{
		{ {{0,1,1},		{0,1,0},	{0,0,1}},		{0,0,0} },
		{ {{0,0,1},		{0,1,0},	{0,0,0}},		{0,0,0} },
		{ {{1,1,1},		{0,1,1},	{1,0,1}},		{0,0,0} },
		{ {{1,0,1},		{0,1,1},	{0,0,1}},		{0,0,0} },
		{ {{1,1,0},		{1,1,1},	{1,0,0}},		{0,0,0} },
		{ {{1,0,0},		{1,1,1},	{1,0,1}},		{0,0,0} },
		{ {{0,1,0},		{1,1,0},	{0,0,0}},		{0,0,0} },
		{ {{0,0,0},		{1,1,0},	{1,0,0}},		{0,0,0} },
		{ {{1,1,1},		{1,1,0},	{0,1,1}},		{0,0,0} },
		{ {{0,1,1},		{1,1,0},	{0,1,0}},		{0,0,0} },
		{ {{1,0,0},		{1,0,1},	{0,0,0}},		{0,0,0} },
		{ {{0,0,0},		{1,0,1},	{0,0,1}},		{0,0,0} }
	};
	scale(cubeMesh, origin, L);		
	//"C:\\Users\\mc dondo\\3D Objects\\sphere.stl"
	cube.write(cubeMesh, filepath);// вставить переменную
	std::cout << "A tessellated cube is created with the side length " << L 
		<< " at the point (" <<origin.x << "," << origin.y << "," << origin.z 
		<< "), and is written to an ASCII STL file with the full path: "<<filepath<<std::endl;
	system("pause");
	return 0;
}


