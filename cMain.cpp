#include "cMain.h"

#include "IBaseCommand.h"
#include "Addition.h"
#include "Substraction.h"
#include "Multiplication.h"
#include "Division.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(0, OnButtonClicked)
EVT_BUTTON(1, OnButtonClicked)
EVT_BUTTON(2, OnButtonClicked)
EVT_BUTTON(3, OnButtonClicked)
EVT_BUTTON(4, OnButtonClicked)
EVT_BUTTON(5, OnButtonClicked)
EVT_BUTTON(6, OnButtonClicked)
EVT_BUTTON(7, OnButtonClicked)
EVT_BUTTON(8, OnButtonClicked)
EVT_BUTTON(9, OnButtonClicked)
EVT_BUTTON(11, OnButtonClicked) //Restart button
EVT_BUTTON(12, OnButtonClicked)	//Mod button
EVT_BUTTON(13, OnButtonClicked)	//Divide button
EVT_BUTTON(14, OnButtonClicked) //Multiply button
EVT_BUTTON(15, OnButtonClicked)	//Substract button
EVT_BUTTON(16, OnButtonClicked)	//Plus button
EVT_BUTTON(17, OnButtonClicked) //Negative button
EVT_BUTTON(18, OnButtonClicked)	//Equal button

EVT_BUTTON(19, OnButtonClicked) //Decimal button
EVT_BUTTON(20, OnButtonClicked) //Binary button
EVT_BUTTON(21, OnButtonClicked)	//Hexadecimal buttony


wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(50, 50), wxSize(350, 425))
{
	ButtonFactory Factory;
	//list = new wxListBox(this, wxID_ANY, wxPoint(10, 310), wxSize(315, 45));
	btn1 = Factory.CreateButton(this, 1, '1', 10, 130, 45, 50);
	btn2 = Factory.CreateButton(this, 2, '2', 10, 170, 45, 50);
	btn3 = Factory.CreateButton(this, 3, '3', 10, 210, 45, 50);
	btn4 = Factory.CreateButton(this, 4, '4', 55, 130, 45, 50);
	btn5 = Factory.CreateButton(this, 5, '5', 55, 170, 45, 50);
	btn6 = Factory.CreateButton(this, 6, '6', 55, 210, 45, 50);
	btn7 = Factory.CreateButton(this, 7, '7', 100, 130, 45, 50);
	btn8 = Factory.CreateButton(this, 8, '8', 100, 170, 45, 50);
	btn9 = Factory.CreateButton(this, 9, '9', 100, 210, 45, 50);
	btn0 = Factory.CreateButton(this, 0, '0', 10, 250, 90, 50);
	btnComma = Factory.CreateButton(this, wxID_ANY, ',', 100, 250, 45, 50);

	btnfiller = Factory.CreateButton(this, wxID_ANY, "", 10, 80, 45, 50);
	btnRestart = Factory.CreateButton(this, 11, "AC", 55, 80, 45, 50); //Restart button
	btnMod = Factory.CreateButton(this, 12, '%', 100, 80, 45, 50);	//Mod button
	btnDiv = Factory.CreateButton(this, 13, '/', 145, 80, 45, 50);	//Divide button
	btnMulti = Factory.CreateButton(this, 14, 'X',145, 130, 45, 50);	//Multiply button
	btnNega = Factory.CreateButton(this, 15, '-', 145, 170, 45, 50); //Substract button
	btnPlus = Factory.CreateButton(this, 16, '+', 145, 210,45, 50); //Plus button
	btnEqual = Factory.CreateButton(this, 18, '=',145, 250, 45, 50); //Equal button

	btnfiller2 = Factory.CreateButton(this, wxID_ANY, "", 210, 80, 65, 50);
	btnDecimal = Factory.CreateButton(this, 19, "Decimal", 210, 210, 65, 50);
	btnBinary = Factory.CreateButton(this, 20, "Binary", 210, 130, 65, 50);
	btnHex = Factory.CreateButton(this, 21, "Hex", 210, 170, 65, 50);
	btnNegative = Factory.CreateButton (this, 17, "Negative", 210, 250, 65, 50);

	
	text = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(315, 60));
}

cMain::~cMain()
{
	
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
	int id = evt.GetId();

	CalculatorProcessor* operations = CalculatorProcessor::GetInstance();
	wxButton* pButton = dynamic_cast<wxButton*>(evt.GetEventObject());

	if (pButton != nullptr)
	{
		text->AppendText(pButton->GetLabel());

		if (pButton->GetId() == 11)
		{
			text->Clear();
			numbers1.clear();
			numbers2.clear();
		}

		if (pButton->GetId() >= 0 && pButton->GetId() <= 9)
		{
			if (operators != true)
				numbers1 += pButton->GetLabel();
			else
				numbers2 += pButton->GetLabel();
				
			operations->SetBaseNumber(wxAtoi(text->GetValue()));

			// This button is for decimal
			if (pButton->GetId() == 19)
			{
				text->Clear();
				text->AppendText(operations->GetDecimal());
			}

			// This button is for Binary
			if (pButton->GetId() == 20)
			{
				text->Clear();
				text->AppendText(operations->GetBinary());
			}

			//This button is for Hexadecimal
			if (pButton->GetId() == 21)
			{
				text->Clear();
				text->AppendText(operations->GetHexadecimal());
			}
		}

		if (pButton->GetId() >= 12 && pButton->GetId() <= 16)
		{
			operators = true;
			character = pButton->GetLabel();
		}
		// Make sure to put an error when you don't have a number and have a operator on the screen
		//else if()

		std::vector<IBaseCommand*> commands;

		wxString info = text->GetValue();
		if (pButton->GetId() == 18)
		{
			text->Clear();
			
			if (character == '+')
			{
				Addition addition(operations, stoi(numbers1), stoi(numbers2));
				commands.push_back(&addition);
			}
			else if (character == '-')
			{
				Substraction sub(operations, stoi(numbers1), stoi(numbers2));
				commands.push_back(&sub);
			}
			else if (character == 'X')
			{
				Multiplication multi(operations, stoi(numbers1), stoi(numbers2));
				commands.push_back(&multi);
			}
			else if (character == '/')
			{
				Division div(operations, stoi(numbers1), stoi(numbers2));
				commands.push_back(&div);
			}

			for (int i = 0; i < commands.size(); i++)
			{
				commands[i]->execute();
				commands.clear();
			}
			text->AppendText(std::to_string(operations->GetAnswer()));
			operators = false;

			operations->SetBaseNumber(wxAtoi(text->GetValue()));
		}

		// This button is for decimal
		if (pButton->GetId() == 19)
		{
			text->Clear();
			text->AppendText(operations->GetDecimal());
		}

		// This button is for Binary
		if (pButton->GetId() == 20)
		{
			text->Clear();
			text->AppendText(operations->GetBinary());
		}

		//This button is for Hexadecimal
		if (pButton->GetId() == 21)
		{
			text->Clear();
			text->AppendText(operations->GetHexadecimal());
		}

		//This button is for negative
		if (pButton->GetId() == 17)
		{
			text->Clear();

		}
	}



//TEST_METHOD()
//ASERT::AREEUQAL / ARENOTEQUAL

	evt.Skip();
}
