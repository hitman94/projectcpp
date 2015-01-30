#include "Difference.h"


Difference::Difference(Expression *e1, Expression * e2) :BinOp(e1,e2) {

}

double const Difference::eval() {
	return e1->eval() - e2->eval();
}

string Difference::whoAmI() {
	return "-";
}

Difference::~Difference()
{
}
