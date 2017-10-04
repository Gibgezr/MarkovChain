#include<iostream>
#include<string>
#include "MarkovChain.h"


int main(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cout << "USAGE: " << argv[0] << " <source text filename>" << std::endl;
		system("pause");
		exit(-1);
	}

	MarkovChain markov;
	if (!markov.ParseFile(argv[1]))
	{
		std::cout << "ERROR reading file " << argv[1] << std::endl;
		exit(-2);
	}

	int count = 0;
	while (true)
	{
		std::cout << "How many letters would you like to generate?" << std::endl;
		std::cout << "(enter 0 to exit) : ";
		std::cin >> count;

		if (count < 1) break;

		std::string example = markov.GenerateChain(count);

		std::cout << std::endl << example << std::endl << std::endl;
	}
	return 0;
}