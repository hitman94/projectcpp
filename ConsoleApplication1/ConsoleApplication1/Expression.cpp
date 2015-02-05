#include "Expression.h"

set<Expression *> Expression::_pool;

Expression::Expression()
{
	Expression::_pool.insert(this);
}

ostream& operator<< (ostream &out, Expression &e) {
	return out << e.affiche().c_str();
}

void Expression::toutLiberer() {
	set<Expression *>::iterator it;

	for (it = Expression::_pool.begin(); it != Expression::_pool.end(); ) {
		delete *it;
		Expression::_pool.erase(it++);
	}
}

Expression * Expression::derive(string var) {
	return this;
}

Expression::~Expression()
{
}
