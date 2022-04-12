/****************************************************************************
* Author: k181292 Muhammad Umair Khan                                       *
* Purpose: Counting Paths in MAZE                                   *
* Dated: September 28, 2019                                                 *
* Version: 1.0                                                              *                                                 
* Last modified: September 30, 2019                                         *
*****************************************************************************/



// HEADER FILES
#include<fstream>
#include<iostream>
#include<cstring> 
using namespace std; 

// FUNCTION PROTOTYPE
int SOLVE_MAZE(int **maze,int N, int C);
  
// Driver code 
int main() 
{ 
    // DECLARATION OF VARIABLES
    int N,M;
    int **maze=new int*[N];
    
	
	ifstream file;
	file.open("Input.txt",ios::in );

    if (! file) {
    cout << "Error, file couldn't be opened" << endl; 
    return 1; 
}   

    file >> N;
    file >> M;
	cout << N << " " << M << endl;
	
	for(int i=0;i<N;i++)
    {
    	*(maze+i)=new int[M]; // allocating memory to array
	}
	
		
    for(int i =0; i < N ; i++)
    {
    	for(int j=0 ; j < M ; j ++)
    	{
    		maze[i][j] = 0; // setting array to NULL
		}
	}
    
	
    for(int i =0; i < N ; i++) // taking input in array from file
    {
    	for(int j=0 ; j < M ; j ++)
    	{
    		file >> maze[i][j];
    		cout << maze[i][j];
	        
		}
		
		cout << endl;
	
	}
    
    file.close(); // input file is closed
    
    
    int result;
    result = SOLVE_MAZE(maze,N,M);
	result = 0 - result;
	cout << result; 
	
	ofstream output; // WRITING OUTPUT IN OUTPUT FILE
	output.open("Output.txt",ios::out );
    
    if(result != 0)
	{
		output << result;
    }
    else
    {
    	output << "NO PATH";
	}
 	output.close(); // closing output file
 	
 	
	
	
    return 0;
    
}

  
// THE Function Returns number of possible paths in a maze[N][M] from (0,0) to (N-1,M-1) 

int SOLVE_MAZE(int **maze,int N, int M) 
{ 
    // If the initial cell is blocked, theNe is no 
    // way of moving anywhere 
    if ( maze[0][0]== 1 ) 
        return 0; 
  
    
    // Initializing the leftmost column 
    for (int i=0; i<N; i++) 
    { 
        if (maze[i][0] == 0) 
            maze[i][0] = -1; 
  
        // If we encounter a blocked cell in leftmost 
        // row, there is no way of visiting any cell 
        // directly below it. 
        else
            break; 
    } 
  
    // Similarly initialize the topmost row 
    for (int i=1; i<M; i++) 
    { 
        if (maze[0][i] == 0) 
            maze[0][i] =  -1; 
  
        // If we encounter a blocked cell in bottommost 
        // row, there is no way of visiting any cell 
        // directly below it. 
        else
            break; 
    } 
  
    // The only difference is that if a cell is -1, 
    // simply ignore it else recursively compute 
    // count value maze[i][j] 
    for (int i=1; i<N; i++) 
    { 
        for (int j=1; j<M; j++) 
        { 
            // If blockage is found, ignore this cell  
            if (maze[i][j] == 1) 
                continue; 
  
            // If we can reach maze[i][j] from maze[i-1][j] 
            // then increment count. 2
            if (maze[i-1][j] < 0) 
                maze[i][j] = (maze[i][j] + maze[i-1][j]); 
  
            // If we can reach maze[i][j] from maze[i][j-1] 
            // then increment count. 
            if (maze[i][j-1] < 0) 
                maze[i][j] = (maze[i][j] + maze[i][j-1]); 
        } 
    } 
  
    // return the answer and check final block
    return (maze[N-1][M-1] < 0) ? maze[N-1][M-1] : 0; 
} 

