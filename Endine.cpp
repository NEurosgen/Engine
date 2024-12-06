// Endine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Subject.h"
#include "Engine.h"
#include "Wrapper.h"
int main() {

    Subject subj("this is a test. it is a simple test!");


    auto replaceWrapper = std::make_shared<Wrapper<Subject>>(
        &subj, &Subject::replace_words);
    auto findWrapper = std::make_shared<Wrapper<Subject>>(
        &subj, &Subject::find_phrase);
    auto capitalizeWordsWrapper = std::make_shared<Wrapper<Subject>>(
        &subj, &Subject::capitalize_words);
    auto capitalizeSentencesWrapper = std::make_shared<Wrapper<Subject>>(
        &subj, &Subject::capitalize_sentences);
    auto numberSentencesWrapper = std::make_shared<Wrapper<Subject>>(
        &subj, &Subject::number_sentences);

  
    Engine engine;
    engine.register_command("replace", replaceWrapper);
    engine.register_command("find", findWrapper);
    engine.register_command("capitalize_words", capitalizeWordsWrapper);
    engine.register_command("capitalize_sentences", capitalizeSentencesWrapper);
    engine.register_command("number_sentences", numberSentencesWrapper);


    std::cout << engine.execute("replace", { {"from", "test"}, {"to", "experiment"} }) << std::endl;
    std::cout << engine.execute("find", { {"phrase", "experiment"} }) << std::endl;
    std::cout << engine.execute("capitalize_words", {}) << std::endl;
    std::cout << engine.execute("capitalize_sentences", {}) << std::endl;
    std::cout << engine.execute("number_sentences", {}) << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
