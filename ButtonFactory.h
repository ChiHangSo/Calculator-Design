#pragma once
#include "wx/wx.h"
#include <vector>


class ButtonFactory
{
public:
	wxButton* CreateButton(wxWindow* window, int ID, wxString letter, int x, int y, int width, int height);
	
};

