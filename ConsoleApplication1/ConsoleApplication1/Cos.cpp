#include "Cos.h"
#include "Produit.h"
#include "Sin.h"
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

Expression * Cos::derive(string var) {
	return new Produit(new Constante(-1),new Produit(expr->derive(var), new Sin(expr)));
}

Expression * const Cos::clone() {
	return new Cos(expr->clone());
}
Cos::~Cos()
{
}

Expression * Cos::simplifier(){
	expr->simplifier();
	return this;
}
