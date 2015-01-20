#include<set>
#include <iostream>
using namespace std;
class Expression
{
public:
	Expression();

	virtual double eval()=0;

	virtual ~Expression();
	friend ostream& operator<< (ostream &out, Expression &e);
	static set<Expression *> _pool;
};

