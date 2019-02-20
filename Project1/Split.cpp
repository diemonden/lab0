#include "Split.h"
#include <iostream>

const std::string & Split::getName() const {
	return *(new std::string("Split"));
}

int Split::execute(const std::map<std::string, std::string>& args) {
	for (auto it = args.begin(); it != args.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
	STLParser split;

	std::string input = args.find("input")->second;
	if (_access(input.substr(0, input.find_last_of('\\')).c_str(), 2) == -1) {
		std::cout << "error #2: input filepath is incorrect" << std::endl;
		system("pause");
		return 2;
	}
	TriangleSoup inputMesh = split.read("C:\\Users\\mc dondo\\3D Objects\\cube.stl");
	//TriangleSoup Mesh = split.read(input);

	Vec origin = { atof(args.find("origin")->second.c_str()) ,
				   atof(strchr(args.find("origin")->second.c_str(), ' ')) ,
				   atof(strchr(args.find("origin")->second.c_str() + 1, ' ')) 
	};
	Vec direction = {
				   atof(args.find("direction")->second.c_str()),
				   atof(strchr(args.find("direction")->second.c_str(), ' ')),
				   atof(strchr(args.find("direction")->second.c_str() + 1, ' '))
	};

	std::string output1 = args.find("output1")->second;
	if (_access(output1.substr(0, output1.find_last_of('\\')).c_str(), 2) == -1) {
		std::cout << "error #2: output1 filepath is incorrect" << std::endl;
		system("pause");
		return 2;
	}
	std::string output2 = args.find("output1")->second;
	if (_access(output2.substr(0, output2.find_last_of('\\')).c_str(), 2) == -1) {
		std::cout << "error #2: output2 filepath is incorrect" << std::endl;
		system("pause");
		return 2;
	}
	TriangleSoup mesh1, mesh2;
	//
	split.write(mesh1,output1);
	split.write(mesh2,output2);
	std::cout << "Two tessellated meshes are written to the "<< output1 <<" and "<<output2
		<<"STL ASCII files as the output of splitting the original mesh contained in the"<< input 
		<< "file by the plane defined by a normal vector from the "
		<< "(" <<origin.x << ", " << origin.y << ", " << origin.z << "), in the direction"
		<< "(" << direction.x << ", " << direction.y << ", " << direction.z << ")."<<std::endl;
	system("pause");
	return 0;
}