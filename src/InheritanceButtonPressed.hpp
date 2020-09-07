#pragma once

#include "mauseState.hpp"
class ClassPanel;
class DiagramWindow;
class InheritanceButtonPressed : public mauseState
{
    ClassPanel *first{nullptr};
    ClassPanel *second{nullptr};

    void onClassDown(ClassPanel *panel, wxMouseEvent &event) override;

    void onPanelDown(DiagramWindow *panel, wxMouseEvent &event) override;

    friend class State;
};
