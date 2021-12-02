#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Slider
{
public:
	Slider() { first = 0; second = 0; third = 0; }
	inline void SetFirst(uint32_t set) { first = set; }
	inline void SetSecond(uint32_t set) { second = set; }
	inline void SetThird(uint32_t set) { third = set; }

	inline uint32_t GetSum() const { return first + second + third; }
	inline void SlideWindow(uint32_t nextAmount) { first = second; second = third; third = nextAmount; }
private:
	uint32_t first;
	uint32_t second;
	uint32_t third;
};

int main()
{
	Slider slider;
	uint32_t inputInt = 0;
	std::string lineInput = "";
	std::pair<uint32_t, uint32_t> resultsCount;
	std::ifstream puzzleInputFile;

	puzzleInputFile.open("puzzle.input");
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
	return 0;
}
