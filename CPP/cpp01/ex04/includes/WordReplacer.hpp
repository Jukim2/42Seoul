#ifndef WORDREPLACER_HPP
#define WORDREPLACER_HPP

#include <iostream>

class WordReplacer
{
    private :
        std::string fileName;
        std::string convertee;
        std::string convertor;
    public :
        WordReplacer(std::string fileName, std::string convertee, std::string convertor);
        ~WordReplacer();
        std::string convertLine(const std::string& line) const;
        int convertFile();
};

#endif
