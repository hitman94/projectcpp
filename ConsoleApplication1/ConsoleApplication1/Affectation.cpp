#include "Affectation.h"


Affectation::Affectation(Variable * v, Expression * expr) :var(v), expr(expr)
{
}

double const Affectation::eval() {
	double value = this->expr->eval();
	var->set(value);
	return value;
}

string const Affectation::affiche() {
	return this->var->affiche() +"=" + expr->affiche();
}

Affectation::~Affectation()
{
}
