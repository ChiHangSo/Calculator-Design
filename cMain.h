#pragma once
#include "wx/wx.h"
#include <string>
#include "ButtonFactory.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton *btn0 = nullptr;
	wxButton *btn1 = nullptr;
	wxButton *btn2 = nullptr;
	wxButton *btn3 = nullptr;
	wxButton *btn4 = nullptr;
	wxButton *btn5 = nullptr;
	wxButton *btn6 = nullptr;
	wxButton *btn7 = nullptr;
	wxButton *btn8 = nullptr;
	wxButton *btn9 = nullptr;
	wxButton *btnPlus = nullptr;
	wxButton *btnNega = nullptr;
	wxButton *btnMulti = nullptr;
	wxButton *btnDiv = nullptr;
	wxButton *btnEqual = nullptr;
	wxButton *btnRestart = nullptr;
	wxButton *btnMod = nullptr;
	wxButton *btnBinary = nullptr;
	wxButton *btnHex = nullptr;
	wxButton *btnDecimal = nullptr;
	wxButton *btnNegative = nullptr;
	wxButton *btnComma = nullptr;
	
	wxTextCtrl *text = nullptr;
	wxListBox *list = nullptr;

public:
	void OnButtonClicked(wxCommandEvent &evt);

	wxDECLARE_EVENT_TABLE();

};