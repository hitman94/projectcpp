#include "Exponentielle.h"
#include "Produit.h"
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

Expression * Exponentielle::derive(string var) {
	return new Produit(expr->derive(var), this);
}

string const Exponentielle::affiche() {
	return "Exp(" + expr->affiche() + ")";
}
