/****************************************************************************
* Author: Muhammad Umair Khan                                              *
* Purpose: DynamicSafeArray                                                *
* Dated: November 8, 2019                                                  *
* Version: 1.1                                                             *                                                 
* Last modified: November 8, 2019                                          *
****************************************************************************/
//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 Libraries Included                                                       
#include<iostream>                                                        										
#include<fstream>														  						
#include <cstdio>
#include <cstring>
#include<cstdlib>
//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 Namespaces Used
using namespace std;

//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 DYNMANIC SAFE ARRAY CLASS
class DynamicSafeArray
{
	//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
		" PRIVATE DATA MEMBERS "
	private:
		int* data; // Pointer to Data Of Array
		size_t size; // Size Of Array
	//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
		" PUBLIC DATA MEMBERS "	
	public:
		DynamicSafeArray(); // Default Constructor
		DynamicSafeArray( size_t size ); // Parameterized Constructor
		void ReSize( size_t size ); // Function To Change Size Of Array
		int Get_Size(); // Function That Return Size Of Array
		//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
	    		" RULE OF THREE "
		~DynamicSafeArray(); // Destructor
		DynamicSafeArray( const DynamicSafeArray& rhs ); // Copy Constructor
		DynamicSafeArray& operator=( DynamicSafeArray& rhs ); // '=' Assignment Operator 
		//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
			" FRIEND FUNCTIONS "
		friend ostream& operator << (ostream& outfile, DynamicSafeArray & rhs); // function to print obj's elements
		friend istream& operator >> (istream& infile, DynamicSafeArray & rhs);	// function to take input obj's elements
		//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
			" OPERATORS OVERLOADED "	
		int& operator[]( ssize_t index ); // Subscripting operator for non const obj 
		const int& operator[]( ssize_t index ) const; // Subscripting operator for const obj
};

//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 Exceptions Used ( IF SIZE INPUT IS OUT OF BOUND )
class ArrayIndexOutOfBound: public exception
{
  virtual const char* what() const throw()
  {
    return "Index Out of Bound";
  }
} ArrayBoundException;

class LowerIndexBound: public ArrayIndexOutOfBound // Exception If Lower Bound is Crossed
{
  virtual const char* what() const throw()
  {
    return "Lower Index Out of Bound";
  }
} LowerIndexException;

class UpperIndexBound: public ArrayIndexOutOfBound // Exception If Upper Bound is Crossed
{
  virtual const char* what() const throw()
  {
    return "Upper Index Out of Bound";
  }
} UpperIndexException;

//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 Driver's Code
int main()
{
	DynamicSafeArray DSA1(10);
	cout << "ENTER ELEMENTS OF ARRAY :\n";
	cin >> DSA1;
	cout << "ELEMENTS OF ARRAY ARE :\n";
	cout << DSA1;
	return 0;
}

//\\//\\//\\//\\//\\//\\//\\\//\\//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
	IMPLEMENTATIONS OF FUNCTIONS
	
DynamicSafeArray::DynamicSafeArray()
{
	data = new int;
	size = 1;
}

DynamicSafeArray::DynamicSafeArray( size_t size )
{
	this->size = size; // setting size of array
	data = new int[size]; // Allocating memory to pointer
	memset(this->data,0,sizeof(int)*size); // Setting allocated memory of pointer to zero
}

DynamicSafeArray::DynamicSafeArray(const DynamicSafeArray& rhs )
{
	this->data = new int[size];
	this->size = size;
	memcpy(this->data,data,sizeof(int)*size);
}

int DynamicSafeArray::Get_Size()
{
	return size;
}

DynamicSafeArray& DynamicSafeArray::operator=( DynamicSafeArray& rhs )
{
	if ( this != &rhs )
	{
		this->size = rhs.size;
		this->data = new int[this->size];
		memcpy(this->data,rhs.data,sizeof(rhs.data));	
	}
	
	return (*this);

}

void DynamicSafeArray::ReSize( size_t size )
{
	if ( this->size != size )
	{
		int* temp = new int[size];
		memset(temp,0,sizeof(int)*size);
		
		int i = 0;
		while( i != this->size-1 )
		{
			*(temp+i) = *(data+i);
			i++;
		}
		
		delete[] data;
		data = NULL;
		
		this->size = size;
		data = new int[this->size];
		memset(data,0,sizeof(int)*size);
		i = 0;
		do
		{
			*(data+i) = *(temp+i);
			i++;
		}while( i != this->size - 1 );
		
		delete[] temp;
		temp = 0;
			
	}	
}

DynamicSafeArray::~DynamicSafeArray()
{
	if( data != NULL )
	{
		delete[] data;
		data = NULL;
		size = 0;
	}
}

istream& operator >> (istream& infile, DynamicSafeArray & rhs)
{
	for( int count = 0 ; count < rhs.size ; count++ )
	{
		infile >> rhs.data[count];	
	}	
	return infile;
}

ostream& operator << (ostream& outfile, DynamicSafeArray & rhs)
{
	for( int count = 0 ; count < rhs.size ; count++ )
	{
		outfile << rhs.data[count] << " ";	
	}	
	return outfile;
}

int& DynamicSafeArray::operator[]( ssize_t index )
{
	if ( index >=0 && index < size ) // safe access
	{ 
	    return *(data+index); 
	      
	}
	else if ( index >= size ) // Upper bound crossed
	{ 
		throw UpperIndexException;
	}
	else // Lower Bound Crossed
	{
	    throw LowerIndexException;
	}
}

const int& DynamicSafeArray::operator[]( ssize_t index ) const
{
	if ( index>=0 && index < size ) // safe access
	{ 
	    return *(data+index); 
	      
	}
	else if ( index >= size ) // Upper bound crossed
	{ 
		throw UpperIndexException;
	}
	else // Lower Bound Crossed
	{
	    throw LowerIndexException;
	}
}
