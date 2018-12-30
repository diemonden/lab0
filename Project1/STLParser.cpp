#include "STLParser.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void STLParser::write(const TriangleSoup& triangleSoup, const std::string filename){
	std::ofstream fout(filename);
		fout << "solid" << std::endl;
		for (auto n : triangleSoup) {
			fout << "facet normal "<< n.normal.x<<" "<< n.normal.y << " "<<n.normal.z<<std::endl;
			fout << "outer loop" << std::endl;
			fout << "vertex " << n.pos[0].x << " " << n.pos[0].y << " " << n.pos[0].z << std::endl;
			fout << "vertex " << n.pos[1].x << " " << n.pos[1].y << " " << n.pos[1].z << std::endl;
			fout << "vertex " << n.pos[2].x << " " << n.pos[2].y << " " << n.pos[2].z << std::endl;
			fout << "endloop" << std::endl;
			fout << "endfacet" << std::endl;
		}				
		fout << "endsolid" << std::endl;
	fout.close();
};