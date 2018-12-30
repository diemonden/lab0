#include "Cube.h"
#include <iostream>
#include <string>

TriangleSoup cubeMesh(12);
STLParser obj;

const std::string & Cube::getName() const {
	return *(new std::string("Cube"));
}

int Cube::execute(const std::map<std::string, std::string>& args) {
	for (auto it = args.begin(); it != args.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}	
	double L = stod(args.find("L")->second);
	
	double x = atof(args.find("origin")->second.c_str());
	double y = atof(strchr(args.find("origin")->second.c_str(),' '));	
	double z = atof(strchr(args.find("origin")->second.c_str(), ' ')+4);

	std::string filepath = args.find("filepath")->second;
	cubeMesh =
	{ 
		//     x                y               z              n
		{ {{x,y+L,z+L},		{x,y+L,z},		{x,y,z+L}},		{0,0,0} },
		{ {{x,y,z+L},		{x,y+L,z},		{x,y,z}},		{0,0,0} },
		{ {{x+L,y+L,z+L},	{x,y+L,z+L},	{x+L,y,z+L}},	{0,0,0} },
		{ {{x+L,y,z+L},		{x,y+L,z+L},	{x,y,z+L}},		{0,0,0} },
		{ {{x+L,y+L,z},		{x+L,y+L,z+L},	{x+L,y,z}},		{0,0,0} },
		{ {{x+L,y,z},		{x+L,y+L,z+L},	{x+L,y,z+L}},	{0,0,0} },
		{ {{x,y+L,z},		{x+L,y+L,z},	{x,y,z}},		{0,0,0} },
		{ {{x,y,z},			{x+L,y+L,z},	{x+L,y,z}},		{0,0,0} },
		{ {{x+L,y+L,z+L},	{x+L,y+L,z},	{x,y+L,z+L}},	{0,0,0} },
		{ {{x,y+L,z+L},		{x+L,y+L,z},	{x,y+L,z}},		{0,0,0} },
		{ {{x+L,y,z},		{x+L,y,z+L},	{x,y,z}},		{0,0,0} },
		{ {{x,y,z},			{x+L,y,z+L},	{x,y,z+L}},		{0,0,0} }
	};
	obj.write(cubeMesh, "C:\\Users\\mc dondo\\3D Objects\\cube.stl");// вставить переменную
	system("pause");
	return 0;
}
