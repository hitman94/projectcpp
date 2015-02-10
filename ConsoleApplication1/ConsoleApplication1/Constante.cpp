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

Expression * Constante::derive(string var) {
	return new Constante(0);
}
Expression * const Constante::clone() {
	return new Constante(value);
}
Constante::~Constante()
{
}
