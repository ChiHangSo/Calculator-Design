#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(350, 425))
{
	list = new wxListBox(this, wxID_ANY, wxPoint(10, 10), wxSize(315, 60));
	btn1 = new wxButton(this, wxID_ANY, "1", wxPoint(10, 130), wxSize(45, 50));
	btn2 = new wxButton(this, wxID_ANY, "2", wxPoint(10, 170), wxSize(45, 50));
	btn3 = new wxButton(this, wxID_ANY, "3", wxPoint(10, 210), wxSize(45, 50));
	btn4 = new wxButton(this, wxID_ANY, "4", wxPoint(55, 130), wxSize(45, 50));
	btn5 = new wxButton(this, wxID_ANY, "5", wxPoint(55, 170), wxSize(45, 50));
	btn6 = new wxButton(this, wxID_ANY, "6", wxPoint(55, 210), wxSize(45, 50));
	btn7 = new wxButton(this, wxID_ANY, "7", wxPoint(100, 130), wxSize(45, 50));
	btn8 = new wxButton(this, wxID_ANY, "8", wxPoint(100, 170), wxSize(45, 50));
	btn9 = new wxButton(this, wxID_ANY, "9", wxPoint(100, 210), wxSize(45, 50));
	btn0 = new wxButton(this, wxID_ANY, "0", wxPoint(10, 250), wxSize(90, 50));
	btnComma = new wxButton(this, wxID_ANY, ",", wxPoint(100, 250), wxSize(45, 50));

	btn1 = new wxButton(this, wxID_ANY, "", wxPoint(10, 80), wxSize(45, 50));
	btnRestart = new wxButton(this, wxID_ANY, "AC", wxPoint(55, 80), wxSize(45, 50));
	btnMod = new wxButton(this, wxID_ANY, "%", wxPoint(100, 80), wxSize(45, 50));
	btnDiv = new wxButton(this, wxID_ANY, "÷", wxPoint(145, 80), wxSize(45, 50));
	btnMulti = new wxButton(this, wxID_ANY, "x", wxPoint(145, 130), wxSize(45, 50));
	btnNega = new wxButton(this, wxID_ANY, "-", wxPoint(145, 170), wxSize(45, 50));
	btnPlus = new wxButton(this, wxID_ANY, "+", wxPoint(145, 210), wxSize(45, 50));
	btnEqual = new wxButton(this, wxID_ANY, "=", wxPoint(145, 250), wxSize(45, 50));

	btn0 = new wxButton(this, wxID_ANY, "", wxPoint(210, 80), wxSize(65, 50));
	btnBinary = new wxButton(this, wxID_ANY, "Binary", wxPoint(210, 130), wxSize(65, 50));
	btnHex = new wxButton(this, wxID_ANY, "Hex", wxPoint(210, 170), wxSize(65, 50));
	btnDecimal = new wxButton(this, wxID_ANY, "Decimal", wxPoint(210, 210), wxSize(65, 50));
	btnNegative = new wxButton(this, wxID_ANY, "Negative", wxPoint(210, 250), wxSize(65, 50));
	
	text = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 310), wxSize(310, 45));
}

cMain::~cMain()
{
	
}
