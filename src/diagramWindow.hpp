#pragma once

#include <vector>

#include "wx/scrolwin.h"

#include "ClassPanel.hpp"
#include "RelationPanel.hpp"

using std::vector;

class DiagramWindow : public wxScrolledWindow
{
  public:
    enum relation
    {
        newDerriving,
        newFriendship,
        newNesting
    };

  private:
    wxImage InheritanceArrowHead;
    wxImage FriendshipArrowHead;
    wxImage NestingArrowHead;

    vector<ClassPanel *> classPanels;
    // vector<RelationPanel*> RelationPanels;

    void OnDelPressed(wxKeyEvent &event);
    void onMouseDown(wxMouseEvent &event);
    void onMouseUp(wxMouseEvent &event);
    void onMove(wxMouseEvent &event);
    void OnPaint(wxPaintEvent &event);

  public:
    // serialize content of diagram
    void serialize(std::ofstream &file);
    // deserialize content of a file
    void deserialize(std::ifstream &file);
    // process keyboard events
    // TODO: implement shortcuts
    void ProcessKeyboard(wxKeyEvent &event);
    // clear content of diagram and make diagram empty.
    // TODO: Change name to more expressive
    void clear();
    // helper function for deserialisation
    // Set ID of every ClassPanel on diagram.
    // TODO: Change name to more expressive
    void setIDs();
    DiagramWindow(wxWindow *parent, wxWindowID winid = -1, const wxPoint &pos = wxDefaultPosition,
                  const wxSize &size = wxDefaultSize, long style = -1073741824L, const wxString &name = wxPanelNameStr);
    vector<RelationPanel *> relationPanels; // TODO: make it private

    // TODO: Get rid of friend declarations
    friend RelationPanel::RelationPanel(ClassPanel *_first, ClassPanel *_second, relationType _type);
    friend class NoButtonPressed;
    friend class ClassButtonPressed;
    friend class DataButtonPressed;
};
