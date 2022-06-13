#include "ButtonFactory.h"


wxButton* ButtonFactory::CreateButton(wxWindow* window, int ID, wxString letter, int x, int y, int width, int height)
{
	return new wxButton(window, ID, letter, wxPoint(x, y), wxSize(width, height));
}
