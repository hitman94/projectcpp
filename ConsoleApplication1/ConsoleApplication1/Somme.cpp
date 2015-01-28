#include "Somme.h"
#include "Constante.h"


Somme::Somme(Expression * e1, Expression *e2) :BinOp(e1,e2)
{
}

double const Somme::eval() {
	return e1->eval() + e2->eval();
}


string Somme::whoAmI() {
	return "+";
}

Somme::~Somme()
{
}
