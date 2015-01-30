#include "Constante.h"


Constante::Constante(double value) :value(value)
{
	
}

double const Constante::eval() {
	return this->value;
}

string const Constante::affiche() {
	return to_string(this->value);
}

Constante::~Constante()
{
}
