#pragma once
#include "Engine.h"
#include <sstream>
class Subject {
private:
    std::string document;

public:
    Subject(const std::string& text) : document(text) {}

    std::string replace_words(const ArgMap& args);
    std::string find_phrase(const ArgMap& args);
    std::string capitalize_words(const ArgMap&);

 
    std::string capitalize_sentences(const ArgMap&);

   
    std::string number_sentences(const ArgMap&);
};

