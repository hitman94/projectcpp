#include "Sin.h"
#include "Produit.h"
#include "Cos.h"
#include <math.h>


Sin::Sin(Expression * c):UnaireOp(c) {}

double const Sin::eval() {
	return sin(expr->eval());
}

string const Sin::affiche() {
	return "Sin(" + expr->affiche() + ")";
}

Expression * Sin::derive(string var) {
	return new Produit(expr->derive(var), new Cos(expr));
}

Expression * const Sin::clone() {
	return new Sin(expr->clone());
}
Sin::~Sin()
{
}

Expression * Sin::simplifier(){
	expr->simplifier();
	return this;
}
