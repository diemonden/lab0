#include "Application.h"
#include "Parser.h"
#include <iostream>

void Application::registerCommand(std::unique_ptr<Command> command) {
	Command* commandr = command.release();
	map.insert(std::pair<const std::string&, Command*>(commandr->getName(), commandr));
}

int Application::execute(int argc, char * argv[]) {
	Command* command = map[argv[1]];
	std::cout << argv[1] << std::endl;
	auto args = Parser::getMap(argc, argv);
	return command->execute(args);
}

Application::Application() {}
