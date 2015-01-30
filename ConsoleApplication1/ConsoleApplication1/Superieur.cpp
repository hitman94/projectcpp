#include "Superieur.h"


Superieur::Superieur(Expression * e1, Expression * e2) :BinOp(e1, e2)
{
}


Superieur::~Superieur()
{
}


double const Superieur::eval() {
	if (e1->eval() > e2->eval())
		return 1.0;
	else
		return 0.0;
}

string Superieur::whoAmI() {
	return ">";
}