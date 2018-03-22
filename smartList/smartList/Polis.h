#pragma once

#include "smartList.h"
#include <string>
#include <sstream>

using namespace std;

class Binar
{
public:
	float a;
	float b;
	char operand;
};

class Polis
{
public:
	Polis(const string& exp);
	~Polis();

	float calculate(); // TODO
private:
	SmartList<Binar*> _expresion;
};

