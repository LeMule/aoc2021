#include "Declarations.h"

#include "Slider.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

Solution2::Solution2(std::string inputFileStr)
{
	Slider slider;
	uint32_t inputInt = 0;
	std::string lineInput = "";
	std::pair<uint32_t, uint32_t> resultsCount;
	std::ifstream puzzleInputFile;

	puzzleInputFile.open(inputFileStr);
	if(puzzleInputFile.is_open())
	{
		std::getline(puzzleInputFile, lineInput);
		slider.SetFirst(std::stoi(lineInput));
		std::getline(puzzleInputFile, lineInput);
		slider.SetSecond(std::stoi(lineInput));
		std::getline(puzzleInputFile, lineInput);
		slider.SetThird(std::stoi(lineInput));

		uint32_t windowResult1 = slider.GetSum();
		uint32_t windowResult2 = 0;

		while(std::getline(puzzleInputFile, lineInput))
		{
			inputInt = std::stoi(lineInput);
			slider.SlideWindow(inputInt);
			windowResult2 = slider.GetSum();

			if(windowResult1 < windowResult2)
				resultsCount.first++;
			else
				resultsCount.second++;
			
			windowResult1 = windowResult2;
		}
	}
	else
	{
		std::cout << "Invalid input file." << "\n";
	}

	std::cout << "Result is : " << resultsCount.first << "\n";
}
