#include "dgArgument.hpp"
string dgArgument::getDeclaration()
{
	return type + " " + name + (defaultValue.size() != 0 ? " = " + defaultValue : "");
}

dgArgument::dgArgument(string type, string name, string defaultValue) : type(type), name(name), defaultValue(defaultValue)
{

}
