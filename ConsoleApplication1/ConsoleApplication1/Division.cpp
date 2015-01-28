#include "Division.h"


Division::Division(Expression *e1, Expression * e2) :BinOp(e1,e2)
{
}

double const Division::eval() {
	return e1->eval() / e2->eval();
}

string Division::whoAmI() {
	return "/";
}

Division::~Division()
{
}
