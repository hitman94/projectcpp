#include "Produit.h"
#include "Somme.h"
Produit::Produit(Expression * e1, Expression * e2) :BinOp(e1,e2){}

double const Produit::eval() {
	return e1->eval() * e2->eval();
}

Expression * Produit::derive(string var) {
	return new Somme(new Produit(e1->derive(var), e2), new Produit(e1, e2->derive(var)));
}

string Produit::whoAmI() {
	return "*";
}
Expression * const Produit::clone() {
	return new Produit(e1->clone(), e2->clone());
}
Produit::~Produit()
{
}
