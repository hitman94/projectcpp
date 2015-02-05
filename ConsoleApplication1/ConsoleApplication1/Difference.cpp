#include "Difference.h"


Difference::Difference(Expression *e1, Expression * e2) :BinOp(e1,e2) {

}

double const Difference::eval() {
	return e1->eval() - e2->eval();
}

Expression * Difference::derive(string var) {
	return new Difference(e1->derive(var), e2->derive(var));
}

string Difference::whoAmI() {
	return "-";
}

Difference::~Difference()
{
}
