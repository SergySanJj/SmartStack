#include <iostream>
#include "smartList.h"
#include "Polis.h"
#include <string>

using namespace std;

int main()
{
	string expresion;
	getline(cin, expresion);

	Polis p(expresion);

	system("pause");
	return 0;
}