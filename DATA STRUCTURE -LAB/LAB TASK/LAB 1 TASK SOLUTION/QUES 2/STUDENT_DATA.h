#ifndef STUDENT_DATA_H
#define STUDENT_DATA_H

#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class STUDENT
{
	public:
		void Input_Data(); 
		void Extract_Highest();
	private:
		string Name;
		string Semester;
		float GPA;
};

#endif
