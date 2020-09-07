#pragma once

#include "ArgumentPanel.hpp"
#include "FunctionDialogLayout.hpp"
#include "dgFunction.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

class FunctionDialog : public FunctionDialogLayout
{
    dgFunction data;
    vector<ArgumentPanel *> arguments;

    void OnModifierPicked(wxCommandEvent &event) override;
    void OnVisibilityPicked(wxCommandEvent &event) override;
    void OnAddClicked(wxCommandEvent &event) override;
    void addArgument();
    void OnRemoveClick(wxCommandEvent &event) override;
    void OnCancel(wxCommandEvent &event) override;
    void OnOK(wxCommandEvent &event) override;

  public:
    dgFunction GetValue();
    void addArgument(dgArgument var);
    FunctionDialog(wxWindow *parent);
    FunctionDialog(wxWindow *parent, dgFunction func);
};
