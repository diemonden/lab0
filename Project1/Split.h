#pragma once

#include <string>
#include "Parser.h"
#include "STLParser.h"
#include "Command.h"
#include <map>

class Split : public Command
{
public:
	const std::string& getName() const override;
	int execute(const std::map<std::string, std::string>& args) override;
private:
	// TODO
};

