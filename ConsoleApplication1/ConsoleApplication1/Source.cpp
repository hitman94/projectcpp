#include <iostream>
#include <math.h>
#include "Cos.h"
#include "Constante.h"
#include "Sin.h"
#include "Exponentielle.h"
#include "Somme.h"
#include "Produit.h"
#include "Pour.h"
#include "Conditionnel.h"
#include "SuperieurEgal.h"
#include "IfThenElse.h"
#include "Superieur.h"
#include "Inferieur.h"
#include "Variable.h"
#include "Affectation.h"
#include "Bloc.h"
#include "Polynome.h"
using namespace std;



void testDerivation() {
	Expression * var = new Variable("x");
	Expression * c = new Cos(var);

	cout << *c << "' = " << *(c->derive("x")) << "\n";
	Expression * exp1 = new Produit(new Exponentielle(var), new Sin(new Variable("y")));

	cout << *exp1 << "' = " << *(exp1->derive("x")) << "\n";

}

void testPolynome() {
	std::set<std::pair<double, double>> set;

	set.insert(std::pair<double, double>(1, 1));
	set.insert(std::pair<double, double>(0, 0));
	
	set.insert(std::pair<double, double>(2, 4));
	Variable * var = new Variable("x",3);
	Polynome * poly = new Polynome(set, var);

	cout << *poly << "\n";
	cout << "valeur pour x =" << var->eval() << " : " << poly->eval()<< "\n";

	cout << "\npool size:" << Expression::_pool.size() << "\n";

	//cout << "polynome derive:" <<  *poly->derive("x") << "\n";

	//cout << "polynome addition:" << *(*poly + *poly) << "\n";

}

void testSimplifier(){
	Expression * exp = new Produit(new Constante(1.0),
		new Somme(
			new Produit(new Constante(1.0), new Variable("x", 4)),
			new Produit(new Variable("x", 4), new Constante(1.0))));
	cout << exp << endl;
	exp = exp->simplifier();
	cout << exp << endl;

}

void testVariable1()
{
	// x = 3
	Variable x("x", 3.0);
	// y = 0
	Variable y("y");
	cout << x << " = " << x.eval() << endl;
	cout << y << " = " << y.eval() << endl;


	//IL FAUT FAIRE UN NEW POUR LE X
	// exp = 1 + 2 * x
	//Expression * exp = new Somme(new Constante(1.0), new Produit(new Constante(2.0), &x));
	// a = (y <- exp)
	//Affectation * a = new Affectation(new Variable("y"), exp->clone());
	//cout << *a << " = " << a->eval() << endl;
	cout << y << " = " << y.eval() << endl;
	
	Variable::effacerMemoire();
	//delete exp; // OK car il existe un clone
	//delete a;
	cout << "destruction automatique des variables locales allouees sur la PILE: ICI X et Y" << endl;
}

void testVariable2()
{
	// x = PI/3
	Variable * x = new Variable("x", 3.14 / 3.0);
	cout << *x << " = " << x->eval() << endl;
	// x = x + (-10)
	x->set(x->eval() + -10);
	cout << *x << " = " << x->eval() << endl;

	Variable::effacerMemoire();
}
void testBinaires() {
	Somme *s = new Somme(new Constante(1.0),
		new Produit(new Constante(2.0),
		new Sin(new Constante(3.14 / 6.0))
		));
	cout << *s << " = " << s->eval() << endl;
	//SuperieurEgal comp(s, new Constante(1.8));
	//cout << comp << " = " << (bool)comp.eval() << endl;
	Expression::toutLiberer();
}

void testExp() {
	Exponentielle *c = new Exponentielle(new Constante(3.14 / 3.0));
	cout << "\n" << *c << " = " << c->eval() << endl;
	Expression::toutLiberer();
}

void testSin() {
	Sin *c = new Sin(new Constante(3.14 / 3.0));
	cout << "\n" << *c << " = " << c->eval() << endl;
	Expression::toutLiberer();
}

void testCos() {
	Cos *c = new Cos(new Constante(3.14 / 3.0));
	cout << "\n" <<  *c << " = " << c->eval() << endl;
	Expression::toutLiberer();
}

void testConstante() {
	Expression * c = new Constante(5.0);
	cout << *c;
	Expression::toutLiberer();
}


void testConditionnel()
{
	// x = 0
	Variable * x = new Variable("x", 8);

	// expr = (x > 0) ? x + 10 : x * 10
	Conditionnel * expr =
		new Conditionnel(new Superieur(x, new Constante(0.0)),
		new Somme(x, new Constante(10.0)),
		new Produit(x, new Constante(10.0)));

	cout << *x << " = " << x->eval() << endl;
	cout << *expr << "\n EVAL ternaire : " << expr->eval() << endl;;
	cout << *x << " = " << x->eval() << endl;
	// x = expr OU ENCORE x = (x > 0) ? x + 10 : x * 10
	x->set(expr->eval());
	cout << *x << " = " << x->eval() << endl;
	cout << *expr << "\n EVAL ternaire : " << expr->eval() << endl;
	cout << *x << " = " << x->eval() << endl;
	Variable::effacerMemoire();
}

void testIfThenElse()
{
	// x = 0
	Variable  * x = new Variable("x", 8);

	// expr = if (x > 0) x = x + 10  else x = x * 10
	IfThenElse * expr =
		new IfThenElse(new Superieur(x, new Constante(0.0)),
		new Affectation(x, new Somme(x, new Constante(10.0))),
		new Affectation(x, new Produit(x, new Constante(10.0))));
	cout << *x << " = " << x->eval() << endl;
	cout << *expr << "\n EVAL if then else : " << expr->eval() << endl;;
	cout << *x << " = " << x->eval() << endl;

	Variable::effacerMemoire();
}


void testPour1()
{
	// x = 3
	Variable * x = new Variable("x", 3.0);
	cout << *x << " = " << x->eval() << endl;

	// i = 0
	Variable * i = new Variable("i");
	cout << *i << " = " << i->eval() << endl;

	// init = (i = 1)
	Expression * init = new Affectation(i, new Constante(1));
	// condition = (x > i - 1)
	Expression * condition = new Superieur(x, new Somme(i, new Constante(-1)));
	// actionFinDeBoucle = (i = i + 1)
	Expression * actionFinDeBoucle = new Affectation(i, new Somme(i, new Constante(1)));
	// calcul = (res = res * i)
	Variable * res = new Variable("res", 1);
	Expression * calcul(new Affectation(res, new Produit(res, i)));

	// pour = for (i = 1; x > i; i = i + 1) res = res * i
	Expression * pour = new Pour(init, condition, actionFinDeBoucle, calcul);
	cout << *pour << "\n EVAL pour : " << pour->eval() << endl;
	cout << x->eval() << "!" << " = " << res->eval() << endl;
	// x = 5
	x->set(5.0);
	cout << *x << " = " << x->eval() << endl;
	// condition = (x > i - 1)
	condition = new Superieur(x, new Somme(i, new Constante(-1)));
	// pour = for (i = 1; x > i; i = i + 1) res = res * i
	res->set(1);
	pour = new Pour(init, condition, actionFinDeBoucle, calcul);
	cout << *pour << "\n EVAL pour : " << pour->eval() << endl;
	cout << x->eval() << "!" << " = " << res->eval() << endl;
	Variable::effacerMemoire();
}

// boucle avec plusieurs instructions (un bloc)
void testPour2()
{
	// x = 3
	Variable * x = new Variable("x", 3.0);
	cout << *x << " = " << x->eval() << endl;

	// i = 0
	Variable * i = new Variable("i");
	cout << *i << " = " << i->eval() << endl;
	// init = (i = 1)
	Expression * init = new Affectation(i, new Constante(1.0));
	// condition = (4 > i)
	Expression * condition = new Superieur(new Constante(4), i);
	// actionFinDeBoucle = (i = i + 1)
	Expression * actionFinDeBoucle = new Affectation(i, new Somme(i, new Constante(1)));
	// calcul =   {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//              y = 3
	//              y = x + -100
	//          }

	// bloc =   {
	//              x = x + 9
	//          }
	Bloc * bloc = new Bloc("b1", new Affectation(x, new Somme(x, new Constante(9))));

	// bloc =   {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//              y = 3
	//              y = x + -100
	//          }
	bloc->add(new IfThenElse(new Superieur(x, new Constante(20.0)),
		new Affectation(x, new Somme(x, new Constante(10.0))),
		new Affectation(x, new Produit(x, new Constante(10.0)))));
	Variable * y = new Variable("y", 5);
	bloc->add(new Affectation(y, new Somme(x, new Constante(-100))));


	// calcul =   {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//              y = 3
	//              y = x + -100
	//
	Expression * calcul(bloc);

	// pour = for (i = 1; 4 > i; i = i + 1) {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//              y = 3
	//              y = x + -100
	//          }
	Expression * pour = new Pour(init, condition, actionFinDeBoucle, calcul);
	cout << *pour << "\n EVAL pour : " << pour->eval() << endl;
	cout << *x << " = " << x->eval() << endl;
	cout << *y << " = " << y->eval() << endl;
}


void testPour3()
{
	// x = 3
	Variable * x = new Variable("x", 3.0);
	cout << *x << " = " << x->eval() << endl;
	// i = 0
	Variable * i = new Variable("i");
	cout << *i << " = " << i->eval() << endl;

	// init1 = (i = 1)
	Expression * init1 = new Affectation(i, new Constante(1.0));
	// condition1 = (4 > i)
	Expression * condition1 = new Superieur(new Constante(4), i);
	// actionFinDeBoucle1 = (i = i + 1)
	Expression * actionFinDeBoucle1 = new Affectation(i, new Somme(i, new Constante(1)));

	// y = 5
	Variable * y = new Variable("y", 5.0);
	cout << *y << " = " << y->eval() << endl;
	// j = 0
	Variable * j = new Variable("j");
	cout << *j << " = " << j->eval() << endl;
	// init2 = (j = 1)
	Expression * init2 = new Affectation(j, new Constante(1.0));
	// condition2 = (3 > j)
	Expression * condition2 = new Superieur(new Constante(3), j);
	// actionFinDeBoucle2 = (j = j + 1)
	Expression * actionFinDeBoucle2 = new Affectation(j, new Somme(j, new Constante(1)));


	// bloc =   {
	//              x = x + 9
	//          }
	Bloc * bloc = new Bloc("b1", new Affectation(x, new Somme(x, new Constante(9))));

	// bloc =   {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//              y = 3
	//              y = x + -100
	//          }
	bloc->add(new IfThenElse(new Superieur(x, new Constante(20.0)),
		new Affectation(x, new Somme(x, new Constante(10.0))),
		new Affectation(x, new Produit(x, new Constante(10.0)))));
	bloc->add(new Affectation(y, new Somme(x, new Constante(-100))));


	// calcul =   {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//              y = 3
	//              y = x + -100
	//          }
	Expression * calcul(bloc);


	// pour = for (i = 1; 4 > i; i = i + 1) {
	//      pour = for (j = 1; 2 > j; j = j + 1) {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//              y = 3
	//              y = x + -100
	//          }
	// }
	Expression * pour2 = new Pour(init2, condition2, actionFinDeBoucle2, calcul);
	Expression * pour1 = new Pour(init1, condition1, actionFinDeBoucle1, pour2);
	cout << *pour1 << "\n EVAL pour1 : " << pour1->eval() << endl;
	cout << *x << " = " << x->eval() << endl;
	cout << *y << " = " << y->eval() << endl;
}

void testBloc()
{
	// x = 5
	Variable * x = new Variable("x", 5);
	// bloc = { x = x + 9 }
	Bloc * bloc = new Bloc("b1", new Affectation(x, new Somme(x, new Constante(9))));

	//  bloc =  {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//          }
	bloc->add(new IfThenElse(new Superieur(x, new Constante(20.0)),
		new Affectation(x, new Somme(x, new Constante(10.0))),
		new Affectation(x, new Produit(x, new Constante(10.0)))));
	// y = 3
	Variable * y = new Variable("y", 3);
	//  bloc =  {
	//              x = x + 9
	//              if (x > 20) x = x + 10  else x = x * 10
	//              y = x + -100
	//          }
	bloc->add(new Affectation(y, new Somme(x, new Constante(-100))));

	cout << *x << " = " << x->eval() << endl;
	cout << *y << " = " << y->eval() << endl;
	cout << *bloc << "\n EVAL bloc : " << bloc->eval() << endl;
	cout << *x << " = " << x->eval() << endl;
	cout << *y << " = " << y->eval() << endl;

	Variable::effacerMemoire();
}


void verifBoucle2()
{
	double x = 3;
	double y = 5;
	int i = 0;
	for (i = 1; 4 > i; i = i + 1)
	{
		x = x + 9;
		if (x > 20)
			x = x + 10;
		else
			x = x * 10;
		y = 3;
		y = x + -100;
	}

	cout << " x = " << x << endl;
	cout << " y = " << y << endl;
}

void verifBoucle3()
{
	double x = 3;
	double y = 5;
	int i = 0;
	int j = 0;
	for (i = 1; 4 > i; i = i + 1)
	{
		for (j = 1; 3 > j; j = j + 1)
		{
			x = x + 9;
			if (x > 20)
				x = x + 10;
			else
				x = x * 10;
			y = 3;
			y = x + -100;
		}
	}

	cout << " x = " << x << endl;
	cout << " y = " << y << endl;
}


int main(int argc, char** argv) {
	int choix = -1;



	do
	{
		cout << " 0 : constante" << endl;
		cout << " 1 : cosinus" << endl;
		cout << " 2 : binaire" << endl;
		cout << " 3 : variable1" << endl;
		cout << " 4 : variable2" << endl;
		cout << " 5 : conditionnel" << endl;
		cout << " 6 : if then else" << endl;
		cout << " 7 : bloc" << endl;
		cout << " 8 : boucle avec une seule expression" << endl;
		cout << " 9 : boucle avec bloc d'expressions" << endl;
		cout << " 10 : boucles imbriques" << endl;
		cout << " 11 : tous les tests" << endl;
		cout << " 12 : polynomes" << endl;
		cout << " 666 : quitter" << endl;
		cout << "choix : ";
		cin >> choix;
		switch (choix)
		{
		case 0:
			testConstante();
			break;
		case 1:
			testCos();
			break;
		case 2:
			testBinaires();
			break;
		case 3:
			testVariable1();
			break;
		case 4:
			testVariable2();
			break;
		case 5:
			testConditionnel();
			break;
		case 6:
			testIfThenElse();
			break;
		case 7:
			testBloc();
			break;
		case 8:
			testPour1();
			break;
		case 9:
			testPour2();
			cout << "VERIFICATION" << endl;
			verifBoucle2();
			break;
		case 10:
			testPour3();
			cout << "VERIFICATION" << endl;
			verifBoucle3();
			break;
		case 11:
			testConstante();
			testCos();
			testBinaires();
			testVariable1();
			testVariable2();
			testConditionnel();
			testIfThenElse();
			testBloc();
			testPour1();
			testPour2();
			cout << "VERIFICATION" << endl;
			verifBoucle2();
			testPour3();
			cout << "VERIFICATION" << endl;
			verifBoucle3();
			break;
		case 12:
			testPolynome();
			break;
		case 13:
			testSimplifier();
			break;
		default:
			cout << "cas inconnu!" << endl;
			break;
		}
	} while (choix != 666);

	Expression::toutLiberer();
	system("PAUSE");
}