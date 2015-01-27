#include "Exponentielle.h"
#include <math.h>

Exponentielle::Exponentielle(double value) :value(value)
{
}
Exponentielle::Exponentielle(Constante *  c) : value(c->eval())
{
}

Exponentielle::~Exponentielle()
{
}

const double Exponentielle::eval() {
	return exp(this->value);
}

string const Exponentielle::affiche() {
	return "Exp(" + to_string(this->value) + ")";
}
