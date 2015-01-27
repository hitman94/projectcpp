#include <iostream>
#include <math.h>
#include "Cos.h"
#include "Constante.h"
#include "Sin.h"
#include "Exponentielle.h"
using namespace std;


void testExp() {
	Exponentielle *c = new Exponentielle(new Constante(3.14 / 3.0));
	cout << "\n" << *c << " = " << c->eval() << endl;
	Expression::toutLiberer();
}

void testSin() {
	Sin *c = new Sin(new Constante(3.14 / 3.0));
	cout << "\n" << *c << " = " << c->eval() << endl;
	Expression::toutLiberer();
}

void testCos() {
	Cos *c = new Cos(new Constante(3.14 / 3.0));
	cout << "\n" <<  *c << " = " << c->eval() << endl;
	Expression::toutLiberer();
}

void testConstante() {
	Expression * c = new Constante(5.0);
	cout << *c;
	Expression::toutLiberer();
}

int main(int argc, char** argv) {
	testConstante();
	testCos();
	testSin();
	testExp();

	system("PAUSE");
}