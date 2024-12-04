#pragma once

#include <memory>
#include "Command.h"

class Engine {
private:
    std::unordered_map<std::string, std::shared_ptr<Command>> commands;

public:
    void register_command(const std::string& name, std::shared_ptr<Command> command);

    std::string execute(const std::string& name, const ArgMap& args);
};