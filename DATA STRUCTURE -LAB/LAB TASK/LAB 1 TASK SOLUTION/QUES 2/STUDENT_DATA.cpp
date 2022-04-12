#include "STUDENT_DATA.h"

void STUDENT::Input_Data()
{
	STUDENT S[3];
	
	for(int i = 0; i <3 ; i++)
	{
	cout << "ENTER STUDENT " << i+1 << " NAME = " << endl;
	cin >> S[i].Name;
    cout << "ENTER STUDENT " << i+1 << " SEMESTER = " << endl;
    cin >> S[i].Semester;
	cout << "ENTER STUDENT " << i+1 << " GPA = " << endl;	
    cin >> S[i].GPA; 
    }
    
    ofstream file;
    file.open ("student.txt" );
     
    	for(int i = 0; i <3 ; i++)
	{

	file << S[i].Name << endl;
    
    file << S[i].Semester << endl;

    file << S[i].GPA << endl; 
    
    }
    
    file.close();
}

void STUDENT::Extract_Highest()
{
    string a[3][3];
	ifstream file;
	file.open("student.txt");
	
	for(int i = 0; i <3 ; i++)
	{
	    for(int j=0;j<3;j++)
        {
        
	    file >> a[i][j];
	    }
   }
   
  
   file.close();
  
        int i=0;
        
	    if(a[i][2] > a[i+1][2]  && a[i][2] > a[i+2][2])
	    {
	        cout << "THE STUDENT WITH HIGHEST GPA IS " << a[i][0] << " i.e " << a[i][2] << " and He is in "  << a[i][1] << " Semester" ;
	        
        }
        
         
	    else if (a[i+1][2] > a[i][2]  && a[i+1][2] > a[i+2][2])
	    {
	        cout << "THE STUDENT WITH HIGHEST GPA IS " << a[i+1][0] << " i.e " << a[i+1][2] << " and He is in "  << a[i+1][1] << " Semester" ;
	    
        }
        
        else
        {
             cout << "THE STUDENT WITH HIGHEST GPA IS " << a[i+2][0] << " i.e " << a[i+2][2] << " and He is in "  << a[i+2][1] << " Semester" ;
	    }
	    
	    
}


