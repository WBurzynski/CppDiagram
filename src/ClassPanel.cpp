#include "ClassPanel.hpp"
#include "State.hpp"
#include "diagramWindow.hpp"
#include <fstream>

ClassPanel::ClassPanel(wxPanel *parent, string name) : wxPanel(parent, wxID_ANY)
{
    SetWindowStyleFlag(wxSIMPLE_BORDER);
    MainSizer = new wxBoxSizer(wxVERTICAL);
    DataSizer = new wxBoxSizer(wxVERTICAL);
    FunctionSizer = new wxBoxSizer(wxVERTICAL);
    ClassName = new wxStaticText(this, wxID_ANY, name /* + std::to_string(ID)*/, wxDefaultPosition, wxDefaultSize,
                                 wxALIGN_CENTRE);
    ClassName->SetForegroundColour(wxColour(0, 0, 0));
    ClassName->Bind(wxEVT_LEFT_DOWN, &ClassPanel::onMouseDown, this);
    ClassName->Wrap(-1);
    MainSizer->Add(ClassName, 0, wxALL | wxEXPAND, 5);

    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    m_staticline1->Bind(wxEVT_LEFT_DOWN, &ClassPanel::onMouseDown, this);
    MainSizer->Add(m_staticline1, 0, wxEXPAND | wxALL, 0);

    MainSizer->Add(DataSizer, 0, wxEXPAND, 5);
    m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    m_staticline2->Bind(wxEVT_LEFT_DOWN, &ClassPanel::onMouseDown, this);
    MainSizer->Add(m_staticline2, 0, wxEXPAND | wxALL, 0);

    MainSizer->Add(FunctionSizer, 0, wxEXPAND, 5);

    this->SetSizer(MainSizer);
    this->Layout();
    MainSizer->Fit(this);

    Bind(wxEVT_LEFT_DOWN, &ClassPanel::onMouseDown, this);
    Bind(wxEVT_LEFT_UP, &ClassPanel::onMouseUp, this);
    Bind(wxEVT_MOTION, &ClassPanel::onMove, this);
}

int ClassPanel::getID() const
{
    return ID;
}

void ClassPanel::addMember(dgFunction fun)
{
    FunctionPanel *temp = new FunctionPanel(this, fun);
    temp->Bind(wxEVT_LEFT_DOWN, &ClassPanel::onMouseDown, this);
    FunctionSizer->Add(temp, 0, wxALL, 5);
    memberFunctions.push_back(temp);
    Fit();
}

void ClassPanel::addMember(dgVariable var)
{
    // Create new member
    VariablePanel *temp = new VariablePanel(this, var);
    temp->Bind(wxEVT_LEFT_DOWN, &ClassPanel::onMouseDown, this);
    DataSizer->Add(temp, 0, wxALL, 5);
    memberVariables.push_back(temp);
    Fit();
}

void ClassPanel::removeMember(FunctionPanel *fun)
{
    for (auto member : memberFunctions)
    {
        if (member == fun)
        {
            FunctionSizer->Detach(member);
            delete member;
            member = nullptr;
            break;
        }
    }
    memberFunctions.erase(std::remove(memberFunctions.begin(), memberFunctions.end(), nullptr), memberFunctions.end());
    Fit();
}

void ClassPanel::removeMember(VariablePanel *var)
{
    for (auto member : memberVariables)
    {
        if (member == var)
        {
            DataSizer->Detach(member);
            delete member;
            member = nullptr;
            break;
        }
    }
    memberVariables.erase(std::remove(memberVariables.begin(), memberVariables.end(), nullptr), memberVariables.end());
    Fit();
}

void ClassPanel::serialize(std::ofstream &file)
{
    ///////////////////////////////////////////////////////////////////
    // Structure of a file:
    // ID\n
    // ClassName\n
    // number_of_member_variables member_variables(separated with ';')\n
    // number_of_member_functions member_functions(separated with ';')\n
    // number_of_parents parents(separated with ' ')\n
    // number_of_friends friends(separated with ' ')\n
    // outer->ID(or 0)\n
    ///////////////////////////////////////////////////////////////////
    return;
}

void ClassPanel::deserialize(std::ifstream &file)
{
    ///////////////////////////////////////////////////////////////////
    // Structure of a file:
    // ID\n
    // ClassName\n
    // number_of_member_variables member_variables(separated with ';')\n
    // number_of_member_functions member_functions(separated with ';')\n
    // number_of_parents parents(separated with ' ')\n
    // number_of_friends friends(separated with ' ')\n
    // outer->ID(or 0)\n
    ///////////////////////////////////////////////////////////////////
    return;
}

void ClassPanel::onMouseDown(wxMouseEvent &evt)
{
    State::get()->onClassDown(this, evt);
}

void ClassPanel::onMouseUp(wxMouseEvent &evt)
{
    State::get()->onClassUp(this, evt);
}

void ClassPanel::onMove(wxMouseEvent &evt)
{
    State::get()->onClassMove(this, evt);
}

int ClassPanel::NextID = 1; // note: ID = 0 is reserved for indicating that classPanel don't have outer class
