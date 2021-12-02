#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
	std::string lineInput = "";
	uint32_t inputInt = 0;
	uint32_t previousInt = 0;
	std::pair<uint32_t, uint32_t> resultsCount;
	std::ifstream puzzleInputFile;

	puzzleInputFile.open("puzzle.input");
	if(puzzleInputFile.is_open())
	{
		std::getline(puzzleInputFile, lineInput);
		previousInt = std::stoi(lineInput);

		while(std::getline(puzzleInputFile, lineInput))
		{
			inputInt = std::stoi(lineInput);
			if(inputInt > previousInt)
				resultsCount.first++;
			else
				resultsCount.second++;
			
			previousInt = inputInt;
		}
	}
	else
	{
		std::cout << "Invalid input file." << "\n";
	}

	std::cout << "Result is : " << resultsCount.first << "\n";
	return 0;
}
