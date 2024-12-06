#pragma o<nce
#include <functional>
#include "Command.h"
template <typename T>
class Wrapper : public Command {
private:
    T* instance; 
    std::function<std::string(T*, const ArgMap&)> func;
public:
    Wrapper(T* obj, std::function<std::string(T*, const ArgMap&)> f)
        : instance(obj), func(f) {}

    std::string execute(const ArgMap& args) override {
        return func(instance, args);
    }
};