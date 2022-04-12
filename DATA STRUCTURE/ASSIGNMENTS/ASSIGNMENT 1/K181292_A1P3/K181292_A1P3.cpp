/****************************************************************************
* Author: k181292 Muhammad Umair Khan                                       *
* Purpose: Unique characters in a string                                    *
* Dated: September 28, 2019                                                 *
* Version: 1.0                                                              *                                                 
* Last modified: September 30, 2019                                         *
*****************************************************************************/

// HEADER FILES
#include"K181292_A1P3.h"
#define MAX 80 // max size of array

// recursive function to find unique character in a string
void UNIQUE_CHAR::REPLACE( int j , int size , int i)
{
	if(j < size ) // if index is equal to string lenght then terminate the program (recursive case)
	{
	    if( array[j] == array[i]  ) // if the current index element matches with previous element in an array then do further work
  		{
  			if(array[j] != 32)
    			{
					array[j] = '_' ; // replace that element with '_'
    			}
  		}
  		if(i == 0) // if compare index is zero set it equal to current index
  		{
  			j++;
  			i = j;
		}
  		i--; // compared index should be one less than current index 
  	
	  	//again caaling function
  		REPLACE(j,size,i);
   }
   
  else // return the array and terminate recursion (base case)
  {
  	return ;
  }
  
}

void UNIQUE_CHAR::INPUT_FILE()
{
	 //CREATING INPUT FILE AND WRITING INPUT IN IT
	ifstream file;
	file.open("input1.txt",ios::in );

    file.getline(array,MAX);
   
	
 	file.close(); // input file is closed 
 	
    cout << "INPUT FILE =  " << array << endl; // show input file string
}

void UNIQUE_CHAR::OUTPUT_FILE()
{
  	
  	// writing output in output file
  	ofstream output;
	output.open("output1.txt",ios::out );

	for(int i =0; i < strlen(array); i++ )
	{
		output << array[i];
	}
 	output.close(); // closing output file
 	
 	cout << "OUTPUT FILE = " << array; // DISPLAYING OUTPUT ON SCREEN
}

int UNIQUE_CHAR::getlenght()
{
	int lenght = strlen(array); // calculation lenght of string
	return lenght;
}



UNIQUE_CHAR::UNIQUE_CHAR ()
	{
		size=0;
			
	}
	

UNIQUE_CHAR::UNIQUE_CHAR (int Size)
	{
		array=new char[Size];
		size=Size;
	}
	
UNIQUE_CHAR::~UNIQUE_CHAR(){

 if (array != 0)
 {
 	delete [] array;
 	array=0;
 	size=0;
 }

}
	

UNIQUE_CHAR::UNIQUE_CHAR(const UNIQUE_CHAR & rhs){
			
			 this->size= size;
			 this->array= new char[size];
			 memcpy(this->array,rhs.array,(sizeof(char)*size));
}





