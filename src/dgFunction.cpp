#include "dgFunction.hpp"

void dgFunction::addArgument(dgArgument arg)
{
    arguments.push_back(arg);
}

string dgFunction::getDeclaration()
{
    // add visibility mark to function
    //+ means public
    //# means protected
    //- means private
    string temp =
        (visibility == dgVisibility::dgPrivate ? "- " : (visibility == dgVisibility::dgProtected ? "# " : "+ "));
    temp += (modifier == Modifier::dgVirtual ? "virtual " : "");
    temp += name;
    temp += "(( ";
    for (dgArgument arg : arguments)
    {
        temp += arg.getDeclaration() + ", ";
    }

    // remove " ," after last argument
    temp.pop_back();
    temp.pop_back();
    // note: old style for loop would be probsbly more efficient

    temp += " ) : " + type;
    return temp;
}

dgFunction::dgFunction(string type, string name, dgVisibility visibility, Modifier modifier)
    : type(type), name(name), visibility(visibility), modifier(modifier)
{
}
