#pragma once

#include <string> 
#include <map> 
#include "Parser.h"
#include "STLParser.h"
#include <io.h>
class Command
{
public:
	virtual ~Command() {};
	virtual const std::string& getName() const = 0;
	virtual int execute(const std::map<std::string, std::string>& args) = 0;
	void scale(TriangleSoup &Mesh, const Vec &CENTER, const double ScaleParameter);
};

