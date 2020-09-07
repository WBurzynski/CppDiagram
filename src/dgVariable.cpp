#include "dgVariable.hpp"

string dgVariable::getDeclaration()
{
    return name + " " + (defaultValue.size() != 0 ? "= " + defaultValue : "") + " : " + type;
}

dgVariable::dgVariable(string type, string name, string defaultValue, dgVisibility visibility, Modifier modifier)
    : dgArgument(type, name, defaultValue), visibility(visibility), modifier(modifier)
{
}
