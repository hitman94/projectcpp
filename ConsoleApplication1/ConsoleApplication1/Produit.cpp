#include "Produit.h"

Produit::Produit(Expression * e1, Expression * e2) :BinOp(e1,e2){}

double const Produit::eval() {
	return e1->eval() * e2->eval();
}

string Produit::whoAmI() {
	return "*";
}

Produit::~Produit()
{
}
