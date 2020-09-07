#pragma once

#include "wx/panel.h"
#include "wx/statbmp.h"
class ClassPanel;

class RelationPanel
{
    ClassPanel *first;
    ClassPanel *second;
    wxImage ArrowHeadImage;
    wxPanel *vertical;
    wxPanel *horisontal;
    wxStaticBitmap *ArrowHead;

  public:
    enum class relationType
    {
        Inheritance,
        Friendship,
        Nesting
    } type;

    void setLines();
    void setArrowhead();
    void serialize(std::ofstream &file);

    RelationPanel(ClassPanel *_first, ClassPanel *_second, relationType _type);
};
