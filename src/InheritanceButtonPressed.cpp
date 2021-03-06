#include "InheritanceButtonPressed.hpp"
#include "ClassPanel.hpp"
#include "State.hpp"
#include "diagramWindow.hpp"
void InheritanceButtonPressed::onClassDown(ClassPanel *panel, wxMouseEvent &event)
{
    if (first == nullptr)
    {
        first = panel;
    }
    else if (second == nullptr)
    {
        if (panel != first)
        {
            second = panel;
            dynamic_cast<DiagramWindow *>(first->GetParent())
                ->relationPanels.push_back(new RelationPanel(first, second, RelationPanel::relationType::Inheritance));
            first->GetParent()->Refresh();
            State::getSource()->SetValue(false);
            State::set(State::NoButton, nullptr);
        }
    }

    event.Skip();
}

void InheritanceButtonPressed::onPanelDown(DiagramWindow *panel, wxMouseEvent &event)
{
    // TODO: play error sound and/or show message dialog
    event.Skip();
}
