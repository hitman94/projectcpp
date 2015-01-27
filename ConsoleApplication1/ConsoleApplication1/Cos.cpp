#include "Cos.h"
#include <math.h>
Cos::Cos(double value) :value(value)
{
}
Cos::Cos(Constante *  value) : value(value->eval())
{
}
double const Cos::eval() {
	return cos(this->value);
}

string const Cos::affiche() {
	return "Cos(" + std::to_string(this->value) + ")";
}

Cos::~Cos()
{
}
