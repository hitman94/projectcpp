#include "Sin.h"
#include <math.h>


Sin::Sin(Expression * c):expr(c) {}

double const Sin::eval() {
	return sin(expr->eval());
}

string const Sin::affiche() {
	return "Sin(" + expr->affiche() + ")";
}

Sin::~Sin()
{
}
