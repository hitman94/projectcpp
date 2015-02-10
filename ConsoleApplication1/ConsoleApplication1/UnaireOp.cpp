#include "UnaireOp.h"


UnaireOp::UnaireOp(Expression * c) :expr(c)
{
}


UnaireOp::~UnaireOp()
{
	delete expr;
}
