#include "RelationPanel.hpp"
#include "diagramWindow.hpp"
#include "wx/panel.h"

#include "ClassPanel.hpp"

void RelationPanel::setLines()
{
    wxPoint f = first->GetPosition() + first->GetSize() / 2;   // center of child classPanel
    wxPoint s = second->GetPosition() + second->GetSize() / 2; // center of parent classPanel
    wxPoint m(f.x, s.y);

    if (m.y < f.y)
    {
        if (m.x < second->GetPosition().x || m.x > second->GetPosition().x + second->GetSize().GetWidth())
        {
            vertical->SetPosition(m);
            vertical->SetSize(wxSize(2, abs(m.y - f.y) - first->GetSize().GetHeight() / 2));
        }
        else
        {
            vertical->SetPosition(wxPoint(m.x, m.y + second->GetSize().GetHeight() / 2 + 16));
            vertical->SetSize(
                wxSize(2, abs(m.y - f.y) - first->GetSize().GetHeight() / 2 - second->GetSize().GetHeight() / 2 - 16));
        }
    }
    else
    {
        vertical->SetPosition(wxPoint(f.x, f.y + first->GetSize().GetHeight() / 2));
        if (m.x < second->GetPosition().x || m.x > second->GetPosition().x + second->GetSize().GetWidth())
        {
            vertical->SetSize(wxSize(2, abs(m.y - f.y) - first->GetSize().GetHeight() / 2));
        }
        else
        {
            vertical->SetSize(
                wxSize(2, abs(m.y - f.y) - first->GetSize().GetHeight() / 2 - second->GetSize().GetHeight() / 2 - 16));
        }
    }
    if (m.x < s.x)
    {
        if (m.y < first->GetPosition().y || m.y > first->GetPosition().y + first->GetSize().GetHeight())
        {
            horisontal->SetPosition(m);
            horisontal->SetSize(wxSize(abs(m.x - s.x) - second->GetSize().GetWidth() / 2 - 16, 2));
        }
        else
        {
            horisontal->SetPosition(wxPoint(m.x + first->GetSize().GetWidth() / 2, m.y));
            horisontal->SetSize(
                wxSize(abs(m.x - s.x) - second->GetSize().GetWidth() / 2 - first->GetSize().GetWidth() / 2 - 16, 2));
        }
    }
    else
    {
        horisontal->SetPosition(wxPoint(s.x + second->GetSize().GetWidth() / 2 + 16, s.y));
        if (m.y < first->GetPosition().y || m.y > first->GetPosition().y + first->GetSize().GetHeight())
        {
            horisontal->SetSize(
                wxSize(abs(m.x - s.x) - second->GetSize().GetWidth() / 2 - first->GetSize().GetWidth() / 2 + 16, 2));
        }
        else
        {
            horisontal->SetSize(wxSize(abs(m.x - s.x) - second->GetSize().GetWidth() / 2 + 16, 2));
        }
    }
    setArrowhead();
}
void RelationPanel::setArrowhead()
{
    wxPoint f = first->GetPosition() + first->GetSize() / 2;   // center of child classPanel
    wxPoint s = second->GetPosition() + second->GetSize() / 2; // center of parent classPanel
    wxPoint m(f.x, s.y);

    if (m.x < second->GetPosition().x)
    {
        ArrowHead->SetPosition(wxPoint(second->GetPosition().x - 16, s.y - 8));
        ArrowHead->SetBitmap(ArrowHeadImage.Rotate90());
    }
    else if (m.x < second->GetPosition().x + second->GetSize().GetWidth())
    {
        if (m.y > f.y)
        {
            ArrowHead->SetPosition(wxPoint(m.x - 8, second->GetPosition().y - 16));
            ArrowHead->SetBitmap(ArrowHeadImage.Rotate180());
        }
        else
        {
            ArrowHead->SetPosition(wxPoint(m.x - 8, second->GetPosition().y + second->GetSize().GetHeight()));
            ArrowHead->SetBitmap(ArrowHeadImage);
        }
    }
    else
    {
        ArrowHead->SetPosition(wxPoint(second->GetPosition().x + second->GetSize().GetWidth(), s.y - 8));
        ArrowHead->SetBitmap(ArrowHeadImage.Rotate90(false));
    }
}
void RelationPanel::serialize(std::ofstream &file)
{
}
RelationPanel::RelationPanel(ClassPanel *_first, ClassPanel *_second, relationType _type)
    : first(_first), second(_second), type(_type)
{
    vertical = new wxPanel(first->GetParent());
    horisontal = new wxPanel(first->GetParent());
    switch (_type)
    {
    case relationType::Inheritance:
        ArrowHeadImage = dynamic_cast<DiagramWindow *>(first->GetParent())->InheritanceArrowHead;
        break;
    case relationType::Friendship:
        ArrowHeadImage = dynamic_cast<DiagramWindow *>(first->GetParent())->FriendshipArrowHead;
        break;
    case relationType::Nesting:
        ArrowHeadImage = dynamic_cast<DiagramWindow *>(first->GetParent())->NestingArrowHead;
        break;
    }
    ArrowHead = new wxStaticBitmap(first->GetParent(), wxID_ANY, wxBitmap(ArrowHeadImage));
    ArrowHead->SetSize(wxSize(16, 16));
    vertical->SetBackgroundColour(wxColour(0, 0, 0));
    horisontal->SetBackgroundColour(wxColour(0, 0, 0));
    setLines();
    // vertical->Lower();
    // horisontal->Lower();
}
