#include "Exponentielle.h"
#include <math.h>

Exponentielle::Exponentielle(Expression *  c) : expr(c)
{
}

Exponentielle::~Exponentielle()
{
}

const double Exponentielle::eval() {
	return exp(expr->eval());
}

string const Exponentielle::affiche() {
	return "Exp(" + expr->affiche() + ")";
}
