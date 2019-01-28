#pragma once

#include <vector>
#include <string>

struct Vec { 
	double x, y, z; 
};

struct Facet
{
	Vec pos[3];
	Vec normal;
};

using TriangleSoup = std::vector<Facet>;

class STLParser
{
public:
	TriangleSoup read(const std::string& filename);
	void write(const TriangleSoup& triangleSoup, const std::string filename);
private:
	// TODO
};
