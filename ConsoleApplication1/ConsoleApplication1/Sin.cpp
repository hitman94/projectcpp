#include "Sin.h"
#include <math.h>

Sin::Sin(double value) :value(value)
{
}

Sin::Sin(Constante * c):value(c->eval()) {}

double const Sin::eval() {
	return sin(this->value);
}

string const Sin::affiche() {
	return "Sin(" + std::to_string(this->value) + ")";
}

Sin::~Sin()
{
}
