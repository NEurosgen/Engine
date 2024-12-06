
#include "Subject.h"



    std::string Subject::replace_words(const ArgMap& args) {
        std::string from = args.at("from");
        std::string to = args.at("to");
        size_t pos = 0;
        while ((pos = document.find(from, pos)) != std::string::npos) {
            document.replace(pos, from.length(), to);
            pos += to.length();
        }
        return document;
    }

   
    std::string Subject::find_phrase(const ArgMap& args) {
        std::string phrase = args.at("phrase");
        size_t pos = document.find(phrase);
        return (pos != std::string::npos) ? "Found" : "Not Found";
    }


    std::string Subject::capitalize_words(const ArgMap&) {
        bool capitalize = true;
        for (char& ch : document) {
            if (std::isspace(ch)) {
                capitalize = true;
            }
            else if (capitalize && std::isalpha(ch)) {
                ch = std::toupper(ch);
                capitalize = false;
            }
        }
        return document;
    }

   
    std::string Subject::capitalize_sentences(const ArgMap&) {
        bool capitalize = true;
        for (char& ch : document) {
            if (capitalize && std::isalpha(ch)) {
                ch = std::toupper(ch);
                capitalize = false;
            }
            if (ch == '.' || ch == '!' || ch == '?') {
                capitalize = true;
            }
        }
        return document;
    }


std::string Subject::number_sentences(const ArgMap&) {
    std::ostringstream oss;
    size_t sentence_number = 1;
    bool new_sentence = true;
        for (char ch : document) {
            if (new_sentence && std::isalpha(ch)) {
                oss << sentence_number++ << ". ";
                new_sentence = false;
            }
            oss << ch;
            if (ch == '.' || ch == '!' || ch == '?') {
                oss << "\n";
                new_sentence = true;
            }
        }
        document = oss.str();
        return document;
    }

