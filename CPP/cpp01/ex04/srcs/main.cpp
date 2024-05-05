#include "WordReplacer.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		std::cout << "Need more argument" << std::endl;
		return (1);
	}
	WordReplacer wr(argv[1], argv[2], argv[3]);
	if (!wr.convertFile())
	{
		std::cout << "file open error" << std::endl;
		return (1);
	}
	return (0);
}