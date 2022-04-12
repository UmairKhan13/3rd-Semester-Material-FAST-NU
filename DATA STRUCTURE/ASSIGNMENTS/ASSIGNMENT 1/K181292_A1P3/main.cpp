/****************************************************************************
* Author: k181292 Muhammad Umair Khan                                       *
* Purpose: Unique characters in a string                                    *
* Dated: September 28, 2019                                                 *
* Version: 1.0                                                              *                                                 
* Last modified: September 30, 2019                                         *
*****************************************************************************/

// HEADER FILES
#include"K181292_A1P3.h"

#define MAX 80 // Max Size Of Array

// DRIVER PROGRAM
int main()
{
   // CREATING OBJECT OF CLASS AND ALLOCATING MEMORY
    UNIQUE_CHAR OBJ(MAX); 
    
    OBJ.INPUT_FILE();  // GETTING INPUT FROM INPUTFILE
    
    
	int lenght = OBJ.getlenght(); // calculation lenght of string
  	int index = 1; // index to be compared
  	int compare_index = index - 1 ; // index to compare with
  	
  	OBJ.REPLACE(index,lenght,compare_index); // CALL THE RECURSIVE FUNCTION
    OBJ.OUTPUT_FILE(); // WRITING OUTPUT IN OUTPUT FILE and displaying output
    OBJ.~UNIQUE_CHAR(); // CALLING DESTRUCTOR

}

