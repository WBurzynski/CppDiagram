#pragma once

#include <string>

#include "MemberDialog.h"
#include "dgVariable.h"
using std::string;

class DataMemberDialog : public MemberDialog
{
	dgVariable data;
	void OnModifierPicked(wxCommandEvent& event) override;
	void OnVisibilityPicked(wxCommandEvent& event) override;
	void OnCancel(wxCommandEvent& event) override;
	void OnOk(wxCommandEvent& event) override;
public:
	dgVariable GetValue();
	DataMemberDialog(wxWindow* parent);
	DataMemberDialog(wxWindow* parent, dgVariable var);
};

