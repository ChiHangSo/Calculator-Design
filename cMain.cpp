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
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(50, 50), wxSize(350, 425))
{
	list = new wxListBox(this, wxID_ANY, wxPoint(10, 310), wxSize(315, 45));
	btn1 = new wxButton(this, 1, "1", wxPoint(10, 130), wxSize(45, 50));
	btn2 = new wxButton(this, 2, "2", wxPoint(10, 170), wxSize(45, 50));
	btn3 = new wxButton(this, 3, "3", wxPoint(10, 210), wxSize(45, 50));
	btn4 = new wxButton(this, 4, "4", wxPoint(55, 130), wxSize(45, 50));
	btn5 = new wxButton(this, 5, "5", wxPoint(55, 170), wxSize(45, 50));
	btn6 = new wxButton(this, 6, "6", wxPoint(55, 210), wxSize(45, 50));
	btn7 = new wxButton(this, 7, "7", wxPoint(100, 130), wxSize(45, 50));
	btn8 = new wxButton(this, 8, "8", wxPoint(100, 170), wxSize(45, 50));
	btn9 = new wxButton(this, 9, "9", wxPoint(100, 210), wxSize(45, 50));
	btn0 = new wxButton(this, 0, "0", wxPoint(10, 250), wxSize(90, 50));
	btnComma = new wxButton(this, wxID_ANY, ",", wxPoint(100, 250), wxSize(45, 50));

	btn1 = new wxButton(this, wxID_ANY, "", wxPoint(10, 80), wxSize(45, 50));
	btnRestart = new wxButton(this, 11, "AC", wxPoint(55, 80), wxSize(45, 50)); //Restart button
	btnMod = new wxButton(this, 12, "%", wxPoint(100, 80), wxSize(45, 50));	//Mod button
	btnDiv = new wxButton(this, 13, "÷", wxPoint(145, 80), wxSize(45, 50));	//Divide button
	btnMulti = new wxButton(this, 14, "x", wxPoint(145, 130), wxSize(45, 50));	//Multiply button
	btnNega = new wxButton(this, 15, "-", wxPoint(145, 170), wxSize(45, 50)); //Substract button
	btnPlus = new wxButton(this, 16, "+", wxPoint(145, 210), wxSize(45, 50)); //Plus button
	btnEqual = new wxButton(this, 18, "=", wxPoint(145, 250), wxSize(45, 50));

	btn0 = new wxButton(this, wxID_ANY, "", wxPoint(210, 80), wxSize(65, 50));
	btnBinary = new wxButton(this, wxID_ANY, "Binary", wxPoint(210, 130), wxSize(65, 50));
	btnHex = new wxButton(this, wxID_ANY, "Hex", wxPoint(210, 170), wxSize(65, 50));
	btnDecimal = new wxButton(this, wxID_ANY, "Decimal", wxPoint(210, 210), wxSize(65, 50));
	btnNegative = new wxButton(this, 17, "Negative", wxPoint(210, 250), wxSize(65, 50));
	
	//text = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(315, 60));
}

cMain::~cMain()
{
	
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
	int id = evt.GetId();
	int value = -1;

	if (id < 10)
	{

	}
	else if (id == 17)
	{

	}

	switch (value)
	{
	case 1:
		break;
	case 2:
		break;
	}
	text->AppendText(std::to_string(evt.GetId()));

	evt.Skip();
}
