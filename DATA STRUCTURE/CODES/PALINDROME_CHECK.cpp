#include<stdio.h>
#include<string.h>

void palindrome(char a[],int lenght)
{
	int i;
      bool flag = false;
      length = strlen(a);
      for(i=0;i < length ;i++){
         if(a[i] != a[length-i-1]) {
            flag = true;
            break;
         }
      }
      
      if (flag==false) 
	  {
         printf("%s\n",a);
      }
}


   int main(){
      char string[100];
      gets(string);
      char ch,string2[100];
      int i=0,j=0,lenght;
    
      while(ch!=string[i])
      {
          		
	  }
      palindrome(string2,lenght);
	  
	  return 0;
   }

