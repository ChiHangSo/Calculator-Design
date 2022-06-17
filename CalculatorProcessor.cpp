#include "CalculatorProcessor.h"
#include <iostream>

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	if (_processor == nullptr)
	{
		_processor = new CalculatorProcessor();
	}
	return _processor;
}

void CalculatorProcessor::SetBaseNumber(int number)
{
	baseNumber = number;
}



std::string CalculatorProcessor::GetBinary()
{
	std::string results = " ";
	int number = baseNumber;
	for (int i = 0; i < 32; i++)
	{
		if (number % 2 == 0)
			results = "0" + results;
		else
			results = "1" + results;

		number = number / 2;
	}
	return results;

}

std::string CalculatorProcessor::GetDecimal()
{
	return std::to_string(baseNumber);
}

std::string CalculatorProcessor::GetHexadecimal()
{
	std::string results = " ";
	int number = baseNumber;

	while (number > 0)
	{
		int mod = number % 16;
		if (mod < 10)
		{
			results = std::to_string(mod) + results;
		}
		else if (mod == 10)
		{
			results = "A" + results;
		}
		else if (mod == 11)
			results = "B" + results;
		else if (mod == 12)
			results = "C" + results;
		else if (mod == 13)
			results = "D" + results;
		else if (mod == 14)
			results = "E" + results;
		else if (mod == 15)
			results = "F" + results;

		number = number / 16;

	}
	results = "0x" + results;

	return results;
}