#include "Sphere.h"
#include <iostream>

const Vec nn = { 0,0,0 };

Vec norm(Vec v) {
	double d = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v /= d;
	return v;
}
void subdivide(const Vec &v1, const Vec &v2, const Vec &v3, TriangleSoup &sphere_points, const unsigned int depth) {
	if (depth == 0) {
		sphere_points.push_back({ {v1,v2,v3}, nn });
		return;
	}
	const Vec v12 = norm(v1+v2);
	const Vec v23 = norm(v2+v3);
	const Vec v31 = norm(v3+v1);
	
	subdivide(v1, v12, v31, sphere_points, depth - 1);
	subdivide(v2, v23, v12, sphere_points, depth - 1);
	subdivide(v3, v31, v23, sphere_points, depth - 1);
	subdivide(v12, v23, v31, sphere_points, depth - 1);
}
void initialize_sphere(TriangleSoup &sphere_points, const unsigned int depth) {
	const double X = 0.525731112119133606;
	const double Z = 0.850650808352039932;
	const Vec vdata[12] = {
		{-X, 0.0, Z}, { X, 0.0, Z }, { -X, 0.0, -Z }, { X, 0.0, -Z },
		{ 0.0, Z, X }, { 0.0, Z, -X }, { 0.0, -Z, X }, { 0.0, -Z, -X },
		{ Z, X, 0.0 }, { -Z, X, 0.0 }, { Z, -X, 0.0 }, { -Z, -X, 0.0 }
	};
	int tindices[20][3] = {
		{0, 4, 1}, { 0, 9, 4 }, { 9, 5, 4 }, { 4, 5, 8 }, { 4, 8, 1 },
		{ 8, 10, 1 }, { 8, 3, 10 }, { 5, 3, 8 }, { 5, 2, 3 }, { 2, 7, 3 },
		{ 7, 10, 3 }, { 7, 6, 10 }, { 7, 11, 6 }, { 11, 0, 6 }, { 0, 1, 6 },
		{ 6, 1, 10 }, { 9, 0, 11 }, { 9, 11, 2 }, { 9, 2, 5 }, { 7, 2, 11 }
	};
	for (int i = 0; i < 20; i++)
		subdivide(vdata[tindices[i][0]], vdata[tindices[i][1]], vdata[tindices[i][2]], sphere_points, depth);
}
const std::string & Sphere::getName() const {
	return *(new std::string("Sphere"));
}

int Sphere::execute(const std::map<std::string, std::string>& args) {
	for (auto it = args.begin(); it != args.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}

	double R = stod(args.find("R")->second);
	if (R <= 0) {
		std::cout << "error #1: Radius <= 0" << std::endl;
		system("pause");
		return 1;
	}
	Vec CENTER = { atof(args.find("origin")->second.c_str()) ,
				   atof(strchr(args.find("origin")->second.c_str(), ' ')) ,
				   atof(strchr(args.find("origin")->second.c_str() + 1, ' '))
	};

	std::string filepath = args.find("filepath")->second;
	if (_access(filepath.substr(0, filepath.find_last_of('\\')).c_str(), 2) == -1) {
		std::cout << "error #2: filepath is incorrect" << std::endl;
		system("pause");
		return 2;
	}
	TriangleSoup sphereMesh;
	STLParser sphere;

	initialize_sphere(sphereMesh, 4);
	scale(sphereMesh, CENTER, R);
		
	//https://stackoverflow.com/questions/17705621/algorithm-for-a-geodesic-sphere
	//http://www.hugi.scene.org/online/coding/hugi%2027%20-%20coding%20corner%20polaris%20sphere%20tessellation%20101.htm
	//http://www.opengl.org.ru/docs/pg/0208.html
	sphere.write(sphereMesh, filepath);// вставить переменную
	std::cout << "A tessellated sphere is created with the radius "<< R 
		<< " at the point (" << CENTER.x << "," << CENTER.y << "," << CENTER.z
		<< "), and is written to an ASCII STL file with the full path: " << filepath << std::endl;
	system("pause");
	return 0;
}


