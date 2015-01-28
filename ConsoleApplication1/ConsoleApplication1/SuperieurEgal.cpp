#include "SuperieurEgal.h"


SuperieurEgal::SuperieurEgal(Expression * e1, Expression * e2) :BinOp(e1,e2)
{
}

double const SuperieurEgal::eval() {
	if (e1->eval() >= e2->eval())
		return 1.0;
	else
		return 0.0;
}

string SuperieurEgal::whoAmI() {
	return ">=";
}

SuperieurEgal::~SuperieurEgal()
{
}
