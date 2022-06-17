#pragma once
#include <string>

class CalculatorProcessor
{
private:
	static CalculatorProcessor* _processor;
	int baseNumber;
	CalculatorProcessor();


public:
	static CalculatorProcessor* GetInstance();
	void SetBaseNumber(int number);

	CalculatorProcessor(CalculatorProcessor& other) = delete;
	void operator=(const CalculatorProcessor& other) = delete;

	std::string GetDecimal();
	std::string GetHexadecimal();
	std::string GetBinary();

};