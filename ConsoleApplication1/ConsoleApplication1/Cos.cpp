#include "Cos.h"
#include <math.h>

Cos::Cos(Expression *  value) : expr(value)
{
}
double const Cos::eval() {
	return cos(expr->eval());
}

string const Cos::affiche() {
	return "Cos(" + expr->affiche() + ")";
}

Cos::~Cos()
{
}
