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
	std::set<Expression *>::iterator it = Expression::_pool.begin();
	while (it != Expression::_pool.end()) {
		Expression * suppression = *it;
		it++;
		delete suppression;
	}
}

Expression * const Expression::clone() {
	return this;
}

Expression * Expression::derive(string var) {
	return this;
}

Expression * Expression::simplifier(){
	return this;
}

Expression::~Expression()
{
	Expression::_pool.erase(this);
}

Type Expression::getType(){
	return Type::expression;
}


