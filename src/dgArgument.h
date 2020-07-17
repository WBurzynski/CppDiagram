#pragma once
//TODO: Create namespace diagram and remove dg suffix
#include <string>

using std::string;
enum class dgVisibility
{
	dgPublic,
	dgProtected,
	dgPrivate
};
struct dgArgument
{
	std::string type;
	std::string name;
	std::string defaultValue;


	string getDeclaration();

	dgArgument(string _type, string _name, string _defaultValue = "");
};


