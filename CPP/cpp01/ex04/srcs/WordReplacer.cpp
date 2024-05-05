#include "WordReplacer.hpp"
#include <iostream>
#include <fstream>

WordReplacer::WordReplacer(std::string fileName, std::string convertee, std::string convertor) : fileName(fileName), convertee(convertee), convertor(convertor)
{

}

WordReplacer::~WordReplacer()
{

}

std::string WordReplacer::convertLine(const std::string& line) const
{
    std::size_t searchStartingPos = 0;
    std::size_t wordStartingPos = 0;
    std::size_t converteeLength = convertee.length();
    std::string newString;

    while ((wordStartingPos = line.find(convertee, searchStartingPos)) != std::string::npos)
    {
        newString += line.substr(searchStartingPos, wordStartingPos - searchStartingPos);
        newString += convertor;
        searchStartingPos = wordStartingPos + converteeLength;
    }
    newString += line.substr(searchStartingPos, std::string::npos);
    return (newString);
}

int    WordReplacer::convertFile()
{
    std::ifstream   inputFile (fileName.c_str());

	if (inputFile.is_open())
	{
        remove ((fileName + ".replace").c_str());
        
	    std::ofstream   outputFile ((fileName + ".replace").c_str());
		std::string     line;

		while (std::getline(inputFile, line))
        {
			outputFile << convertLine(line);
            if (!inputFile.eof())
                outputFile << std::endl;
        }
        inputFile.close();
        outputFile.close();
	}
	else
		return (0);
    return (1);
}


