#include "Constante.h"


Constante::Constante(double value) :value(value)
{
}

double Constante::eval() {
	return this->value;
}

ostream& operator<< (ostream &out, Constante &c) {
	return out << c.value;
}

Constante::~Constante()
{
}
