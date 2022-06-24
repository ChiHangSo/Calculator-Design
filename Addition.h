#pragma once
#include "IBaseCommand.h"
#include "CalculatorProcessor.h"


class Addition : public IBaseCommand
{
private:
	CalculatorProcessor* _calc = nullptr;
	int _num1 = 0;
	int _num2 = 0;
public:
	Addition(CalculatorProcessor* calc, int num1, int num2)
	{
		_calc = calc;
		_num1 = num1;
		_num2 = num2;
	}
	void execute()
	{
		_calc->SetAnswer(_calc->GetAdd(_num1, _num2));
	}

};