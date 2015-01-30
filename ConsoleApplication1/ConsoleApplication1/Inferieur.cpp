#include "Inferieur.h"


Inferieur::Inferieur(Expression * e1, Expression * e2) :BinOp(e1, e2)
{
}


Inferieur::~Inferieur()
{
}

double const Inferieur::eval() {
	if (e1->eval() < e2->eval())
		return 1.0;
	else
		return 0.0;
}

string Inferieur::whoAmI() {
	return "<";
}