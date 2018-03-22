#include "Polis.h"

Polis::Polis(const string & exp)
{
	stringstream ss;
	ss << exp;
	float tmp_a, tmp_b;
	char tmp_oper;
	while (!ss.eof())
	{
		Binar* tmpBinar = new Binar;
		ss >> tmpBinar->a >> tmpBinar->b >> tmpBinar->operand;
		this->_expresion.push_back(tmpBinar);
	}
}

Polis::~Polis()
{
}
