#pragma once
#include "Engine.h"



void Engine::register_command(const std::string& name, std::shared_ptr<Command> command) {
       commands[name] = command;
    }

 std::string Engine::execute(const std::string& name, const ArgMap& args) {
        if (commands.find(name) != commands.end()) {
            return commands[name]->execute(args);
        }
        return "Command not found";
    }
