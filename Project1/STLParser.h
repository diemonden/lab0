#pragma once

#include <vector>
#include <string>

struct Vec {
	double x, y, z; 
	Vec() {};
	Vec(double x, double y, double z) : x(x), y(y), z(z) {};
	Vec operator = (const Vec &v1);
	friend Vec operator + (const Vec &v1, const Vec &v2);
	friend Vec operator * (const Vec &v1, const double N);
	friend Vec operator /= (Vec &v1, const double N);
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
