#pragma once
//TODO: Create namespace diagram and remove dg suffix
#include <string>

#include "dgArgument.hpp"

using std::string;

struct dgVariable : public dgArgument
{
	//Inherited variables:
	//std::string type;
	//std::string name;
	//std::string defaultValue;
	enum class Modifier
	{
		dgNone,
		dgMutable,
		dgStatic
	} modifier;
	dgVisibility visibility;
	string getDeclaration();

	dgVariable(string type, string name, string defaultValue = "",dgVisibility visibility = dgVisibility::dgPublic, Modifier modifier = Modifier::dgNone);
};


