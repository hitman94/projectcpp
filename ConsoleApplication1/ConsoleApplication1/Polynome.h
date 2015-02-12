#ifndef POLY
#define POLY
#include "Expression.h"
#include "Variable.h"
#include <string>
class Polynome :
	public Expression
{
public:
	Polynome(set<std::pair<double,double>> * set, Variable * nomVar);
	virtual double const eval();
	virtual string const affiche();
	virtual Expression * const clone();
	virtual Expression * derive(string var);
	Polynome * const operator+(const Polynome &polynom);
	Polynome * const operator+=(const Polynome &polynom);
	Polynome * const operator-=(const Polynome &polynom);
	Polynome * const operator*=(const Polynome &polynom);
	Polynome * const operator*(const Polynome &polynom);
	Polynome * const operator=(const Polynome &polynom);
	Polynome * const operator-(const Polynome &polynom);
	bool const operator==(const Polynome &polynom);
	bool const operator!=(const Polynome &polynom);
	~Polynome();

private:
	set<std::pair<double, double>> * coeff;
	void setCoeff(set<std::pair<double, double>> * set);
	Variable * variable;

};
#endif