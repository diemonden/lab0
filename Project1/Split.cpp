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
	std::string output2 = args.find("output1")->second;
	TriangleSoup mesh1, mesh2;
	//
	split.write(mesh1,output1);
	split.write(mesh2,output2);
	system("pause");
	return 0;
}


