#pragma once
#include "Command.h"
#include <string>
#include "Parser.h"
#include "STLParser.h"

class Cube : public Command
{
public:
	const std::string& getName() const override;
	int execute(const std::map<std::string, std::string>& args) override;
private:
	// TODO
};