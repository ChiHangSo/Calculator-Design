#include "cMain.h"

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
EVT_BUTTON(21, OnButtonClicked)	//Hexadecimal button

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

	//btn = new wxButton(this, wxID_ANY, "", wxPoint(10, 80), wxSize(45, 50));
	btnRestart = Factory.CreateButton(this, 11, "AC", 55, 80, 45, 50); //Restart button
	btnMod = Factory.CreateButton(this, 12, '%', 100, 80, 45, 50);	//Mod button
	btnDiv = Factory.CreateButton(this, 13, '÷', 145, 80, 45, 50);	//Divide button
	btnMulti = Factory.CreateButton(this, 14, 'x',145, 130, 45, 50);	//Multiply button
	btnNega = Factory.CreateButton(this, 15, '-', 145, 170, 45, 50); //Substract button
	btnPlus = Factory.CreateButton(this, 16, '+', 145, 210,45, 50); //Plus button
	btnEqual = Factory.CreateButton(this, 18, '=',145, 250, 45, 50); //Equal button

	//btn0 = new wxButton(this, wxID_ANY, "", wxPoint(210, 80), wxSize(65, 50));
	btnBinary = Factory.CreateButton(this, wxID_ANY, "Binary", 210, 130, 65, 50);
	btnHex = Factory.CreateButton(this, wxID_ANY, "Hex", 210, 170, 65, 50);
	btnDecimal = Factory.CreateButton(this, wxID_ANY, "Decimal", 210, 210, 65, 50);
	btnNegative = Factory.CreateButton (this, 17, "Negative", 210, 250, 65, 50);

	
	text = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(315, 60));
}

cMain::~cMain()
{
	
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
	int id = evt.GetId();

	//evt.GetEventObject();
	switch (id)
	{
	case 1:
		text->AppendText(btn1->GetLabel());
		break;
	case 2:
		text->AppendText(btn2->GetLabel());
		break;
	case 3:
		text->AppendText(btn3->GetLabel());
		break;
	case 4:
		text->AppendText(btn4->GetLabel());
		break;
	case 5:
		text->AppendText(btn5->GetLabel());
		break;
	case 6:
		text->AppendText(btn6->GetLabel());
		break;
	case 7:
		text->AppendText(btn7->GetLabel());
		break;
	case 8:
		text->AppendText(btn8->GetLabel());
		break;
	case 9:
		text->AppendText(btn9->GetLabel());
		break;
	case 0:
		text->AppendText(btn0->GetLabel());
		break;

	case 11:
		text->Clear();
		break;
	case 12:
		text->AppendText(btnMod->GetLabel());
		break;
	case 13:
		text->AppendText(btnDiv->GetLabel());
		break;
	case 14:
		text->AppendText(btnMulti->GetLabel());
		break;
	case 15:
		text->AppendText(btnNega->GetLabel());
		break;
	case 16:
		text->AppendText(btnPlus->GetLabel());
		break;
	case 17:
		text->AppendText(btnNegative->GetLabel());
		break;
	case 18:
		text->AppendText(btnEqual->GetLabel());
		break;
	}



	evt.Skip();
}
