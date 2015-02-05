#include "Division.h"
#include "Difference.h"
#include "Produit.h"

Division::Division(Expression *e1, Expression * e2) :BinOp(e1,e2)
{
}

double const Division::eval() {
	return e1->eval() / e2->eval();
}

Expression * Division::derive(string var) {
	return new Division( new Difference(new Produit(e1->derive(var),e2 ),new Produit(e1,e2->derive(var) )),new Produit(e2,e2) );
}

string Division::whoAmI() {
	return "/";
}

Division::~Division()
{
}
