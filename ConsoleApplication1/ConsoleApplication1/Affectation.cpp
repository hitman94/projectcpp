#include "Affectation.h"


Affectation::Affectation(Variable * v, Expression * expr) :var(v), expr(expr)
{
}

double const Affectation::eval() {
	var->set(this->expr->eval());
	return this->expr->eval();
}

string const Affectation::affiche() {
	return this->var->affiche();
}

Affectation::~Affectation()
{
}
