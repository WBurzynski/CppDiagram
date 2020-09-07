#pragma once

#include "MemberPanel.hpp"
#include "dgFunction.hpp"

class FunctionPanel : public MemberPanel
{
  private:
    dgFunction data;

  private:
    void OnEditPressed(wxCommandEvent &event) override;
    void OnDeletePressed(wxCommandEvent &event) override;

  public:
    FunctionPanel(wxWindow *parent, dgFunction _data);
};
