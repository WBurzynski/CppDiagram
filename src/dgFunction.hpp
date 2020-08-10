#pragma once
//TODO: Create namespace diagram and remove dg suffix
#include <string>
#include <vector>

#include "dgArgument.hpp"

using std::string;
using std::vector;

struct dgFunction
{
	dgVisibility visibility;
	string type;
	string name;
	vector<dgArgument> arguments;
	enum class Modifier
	{
		dgNone,
		dgVirtual,
		dgStatic
	} modifier;


	void addArgument(dgArgument arg);
	string getDeclaration();

	dgFunction(string type, string name, dgVisibility visibility = dgVisibility::dgPublic, Modifier modifier = Modifier::dgNone);
};

