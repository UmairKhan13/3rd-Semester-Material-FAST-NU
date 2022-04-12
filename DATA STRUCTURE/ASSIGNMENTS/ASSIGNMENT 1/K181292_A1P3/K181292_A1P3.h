#ifndef _K181292_A1P3
#define _K181292_A1P3

// HEADER FILES
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

// CLASS DECLARATION 
class UNIQUE_CHAR 
{
	private:
	
	char* array;
	int size;
		
	public:	
	
	// FUNCTION DECLARATION
	UNIQUE_CHAR ();
	UNIQUE_CHAR (int Size);
	UNIQUE_CHAR (const UNIQUE_CHAR & rhs);
	~UNIQUE_CHAR ();
	void REPLACE( int j , int k, int i);
	void INPUT_FILE();
	void OUTPUT_FILE();
	int getlenght();
};


#endif
