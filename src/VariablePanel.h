#pragma once

#include "MemberPanel.h"
#include "dgVariable.h"

class VariablePanel : public MemberPanel
{
private:

	dgVariable data;

public:

	void OnEditPressed(wxCommandEvent& event) override;
	void OnDeletePressed(wxCommandEvent& event) override;
	VariablePanel(wxWindow* parent, dgVariable _data);
};

