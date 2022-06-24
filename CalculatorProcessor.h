#pragma once
#include <string>
#include <vector>
#include "cMain.h"
#include "wx/wx.h"

class CalculatorProcessor
{
private:
	static CalculatorProcessor* _processor;
	int baseNumber;
	int _answer;

public:
	CalculatorProcessor() {	}
	
	int GetAnswer()
	{
		return _answer;
	}

	void SetAnswer(int answer)
	{
		_answer = answer;
	}
	static CalculatorProcessor* GetInstance()
	{
		if (_processor == nullptr)
		{
			_processor = new CalculatorProcessor();
		}
		return _processor;
	};

	void SetBaseNumber(int number)
	{
		baseNumber = number;
	}

	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator=(const CalculatorProcessor& other) = delete;

	std::string GetDecimal()
	{
		return std::to_string(baseNumber);
	}

	std::string GetHexadecimal()
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

	std::string GetBinary()
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
	
	int GetAdd(int a, int b)
	{
		return a + b;
	}
	int GetSubs(int a, int b)
	{
		return a - b;
	}

	int GetMulti(int a, int b)
	{
		return a * b;
	}

	int GetDiv(int a, int b)
	{
		return a / b;
	}



};

