#include <iostream>
#include "Constante.h"
#include "parser.h"
#include "lex.h"
using namespace std;

void testConstante() {
	Constante c = Constante(5.0);
	cout << c;
}


int main(int argc, char** argv) {
	testConstante();
	cout << "\n";
	Expression * exp = *Expression::_pool.begin();
	cout << *exp;
	cout << "\n";
	system("PAUSE");
}