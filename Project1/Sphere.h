#pragma once
#include "Parser.h"
#include "STLParser.h"
#include "Command.h"
#include <string>

class Sphere : public Command
{
public:
	const std::string& getName() const override;
	int execute(const std::map<std::string, std::string>& args) override;
private:
	// TODO
};
