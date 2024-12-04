#pragma once


#include <unordered_map>
using ArgMap = std::unordered_map<std::string, std::string>;
class Command {
public:
    virtual std::string execute(const ArgMap& args) = 0;
    virtual ~Command() = default;
};