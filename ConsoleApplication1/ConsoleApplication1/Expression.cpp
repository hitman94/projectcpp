#include "Expression.h"

set<Expression *> Expression::_pool;

Expression::Expression()
{
	Expression::_pool.insert(this);
}

ostream& operator<< (ostream &out, Expression &e) {
	return out << "Salut";
}


Expression::~Expression()
{
}
