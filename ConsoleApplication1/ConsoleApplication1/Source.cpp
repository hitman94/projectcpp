#include <iostream>
#include <math.h>
#include "Cos.h"
#include "Constante.h"
#include "Sin.h"
#include "Exponentielle.h"
#include "Somme.h"
#include "Produit.h"
#include "Conditionnel.h"
#include "SuperieurEgal.h"
#include "Variable.h"
#include "Affectation.h"
using namespace std;


void testVariables() {
	Variable x("x", 3.0);
	Variable y("y");
	cout << x << " = " << x.eval() << endl;
	cout << y << " = " << y.eval() << endl;
	Expression *exp = new Somme(new Constante(1.0),
		new Produit(new Constante(2.0), new Variable("x")));
	Affectation *a = new Affectation(new Variable("y"), exp);
	cout << *a << " = " << a->eval() << endl;
	cout << y << " = " << y.eval() << endl;
	Variable::effacerMemoire();
	cout << y << " = " << y.eval() << endl;
}

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


void testConditionnel()
{
	// x = 0
	Variable * x = new Variable("x", 8);

	// expr = (x > 0) ? x + 10 : x * 10
	Conditionnel * expr =
		new Conditionnel(new SuperieurEgal(x, new Constante(0.0)),
		new Somme(x, new Constante(10.0)),
		new Produit(x, new Constante(10.0)));

	cout << *x << " = " << x->eval() << endl;
	cout << *expr << "\n EVAL ternaire : " << expr->eval() << endl;;
	cout << *x << " = " << x->eval() << endl;
	// x = expr OU ENCORE x = (x > 0) ? x + 10 : x * 10
	//x->set(expr->eval());
	cout << *x << " = " << x->eval() << endl;
	cout << *expr << "\n EVAL ternaire : " << expr->eval() << endl;
	cout << *x << " = " << x->eval() << endl;
	Variable::effacerMemoire();
}


int main(int argc, char** argv) {
/*	testConstante();
	testCos();
	testSin();
	testExp();
	testBinaires();*/

	testVariables(); 
	//testConditionnel();
	system("PAUSE");
}