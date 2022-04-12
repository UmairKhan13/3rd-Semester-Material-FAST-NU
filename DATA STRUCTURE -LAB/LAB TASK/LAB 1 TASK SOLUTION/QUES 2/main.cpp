/*Create a class "Student" with private data members Name, Semester and GPA and two public member functions Input_Data() and Extract_Highest().
Input_Data(): This function creates object of the class and takes name, semester and GPA as input from user for 3 students and write the objects to a text file as whole. 
Extract_Highest(): This function reads the stored data from the text file and displays the name of the student with the highest GPA
*/

#include <iostream>
#include "STUDENT_DATA.h"

int main()
 {
 	STUDENT S;
	S.Input_Data();
	S.Extract_Highest();
	return 0;
}
