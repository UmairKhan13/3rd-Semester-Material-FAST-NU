#include "ArrayException.h"



ArrayException::ArrayException()
{
}


ArrayException::~ArrayException()
{
}

ArrayExceptionLowerBound::ArrayExceptionLowerBound()
{

}
ArrayExceptionUpperBound::~ArrayExceptionUpperBound()
{

}

const char* ArrayExceptionLowerBound::what() const
{
	return "Array execption lower bound";
}

const char* ArrayExceptionUpperBound::what() const
{
	return "Array execption upper bound";
}