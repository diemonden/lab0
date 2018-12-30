#pragma once

#include "Command.h"


class Application
{
public:
	void registerCommand(std::unique_ptr<Command> command);
	int execute(int argc, char *argv[]);
	Application();
private:
	std::map<const std::string, Command*> map;
};
