#pragma once
#include<iostream>
#include<exception>
using namespace std;

class ArrayException :public exception
{
public:
	ArrayException();
	virtual const char* what() const;
	virtual ~ArrayException();
};

class ArrayExceptionLowerBound : public ArrayException
{
public:
	ArrayExceptionLowerBound();
	const char* what() const;
	~ArrayExceptionLowerBound();
};

class ArrayExceptionUpperBound : public ArrayException
{
public:
	ArrayExceptionUpperBound();
	const char* what() const;
	~ArrayExceptionUpperBound();
};