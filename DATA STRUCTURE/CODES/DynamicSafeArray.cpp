/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: DynamicSafeArray (Examples)                                     *
* Dated: September 18, 2007                                                *
* Version: 1.0                                                             *                                                 
* Last modified: September 27, 2007                                        *
****************************************************************************/

#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include<cstdlib>

using namespace std;

class ArrayIndexOutOfBound: public exception
{
  virtual const char* what() const throw()
  {
    return "Index Out of Bound";
  }
} ArrayBoundException;

class LowerIndexBound: public ArrayIndexOutOfBound
{
  virtual const char* what() const throw()
  {
    return "Lower Index Out of Bound";
  }
} LowerIndexException;

class UpperIndexBound: public ArrayIndexOutOfBound
{
  virtual const char* what() const throw()
  {
    return "Upper Index Out of Bound";
  }
} UpperIndexException;

class DynamicSafeArray{
	
	 private:
	 	int *Data;
	 	int size;
	 	
	 	
	public:
		DynamicSafeArray(){
			
			Data=new int;
			size=1;
			
			
		}
	
    	DynamicSafeArray(int n)
		{
			
			size=n;
			Data= new int[size];
			memset(this->Data, 0, sizeof(int)*size);
			
		}
		
		
	   DynamicSafeArray(const DynamicSafeArray & rhs){
			
			 this->size= rhs.size;
			 this->Data= new int[size];
			 memcpy(this->Data,rhs.Data,(sizeof(int)*rhs.getSize()));
			
		}
		
       ~DynamicSafeArray()
	   {
	    	if(Data !=0)
	    	{
			
		    	delete [] Data;
		    	Data=0;
		    	size=0;
		   }
		
    	}
    	
    	void ReSize(int nSize){
    		
    		if (size != nSize )  
			{
			 int * temp= new int[size];
			 	
			    for(int i=0; i<size ; i++){
			    	
			    	temp[i]= *(Data+i);
			    }
			    delete[] Data;
			    Data=0;
			    
			    Data = new int[nSize];
			    memset(this->Data, 0, sizeof(int)*nSize);
  				for(int i=0; i<size ; i++){
			    	
			    	*(Data+i)=temp[i];
			    }
			    size= nSize;
			    delete [] temp;
			    temp=0;
  	
				
			} 		
    		
    	}
	
	   
	 unsigned int getSize() const
	{
	 
	   return size;
	   
	}
	
	
	DynamicSafeArray& operator=( DynamicSafeArray & rhs)
     {
         if (this  != &rhs)
        {
               
        int s=rhs.getSize(); 
        this->size=s;
        this->Data= new int[s];
        memcpy(this->Data,rhs.Data, sizeof(int)*s);
		}
        return *(this);
         
     }

	//DynamicSafeArray 
	//lval
	 int& operator[](int i) 
	 {
	    if (i>=0 && i < size) 
	    { 
	    	return *(Data+i); // safe access
	      
	    }
	    else if ( i > size )// upper bound crossed
	    { 
			throw UpperIndexException;
	    }
		else 
		{
	      throw LowerIndexException;
		}
	       
	  	  
	  }
	 
//	   DyanmicSafeArray 
//	 rval
	const int& operator[](unsigned int i) const
	{
	    if (i < 0) // lower bound crossed 
	    { 
	      throw LowerIndexException;
	    }
	    else if ( i > getSize()-1) // upper bound crossed
	    { 
	      throw UpperIndexException;
	    }
		else
	       return *(Data+i); // safe access
	  	  
	  }



friend istream& operator >> (istream& infile, DynamicSafeArray & rhs)
{
	for (int count=0;count<rhs.size;count++)
		infile>>rhs.Data[count];
    return infile;
}

friend ostream& operator << (ostream& outfile,DynamicSafeArray & rhs)
{
	for (int count=0;count<rhs.size;count++)
	{
		outfile<<rhs.Data[count] << " ";
	}
		
    return outfile;
}


};


int main()
{  
  	DynamicSafeArray  DSA1(10); 
	cin >> DSA1[-1];
	return 0;

}
