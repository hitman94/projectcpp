#include <iostream>
#include <math.h>
#include "Cos.h"
#include "Constante.h"
#include "Sin.h"
#include "Exponentielle.h"
#include "Somme.h"
#include "Produit.h"
#include "SuperieurEgal.h"
using namespace std;


void testBinaires() {
	Somme *s = new Somme(new Constante(1.0),
		new Produit(new Constante(2.0),
		new Sin(new Constante(3.14 / 6.0))
		));
	cout << *s << " = " << s->eval() << endl;
	//SuperieurEgal comp(s, new Constante(1.8));
	//cout << comp << " = " << (bool)comp.eval() << endl;
	Expression::toutLiberer();
}

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
	testBinaires();
	system("PAUSE");
}