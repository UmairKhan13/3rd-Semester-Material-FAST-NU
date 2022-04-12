// C++ code to print subtree of all nodes 
#include<bits/stdc++.h> 
using namespace std; 

// arrays for keeping position 
// at each dfs traversal for each node 
int start[100001]; 
int endd[100001]; 

// Storing dfs order 
vector<int>dfs_order; 
vector<int>adj[100001]; 
int visited[100001]; 

// Recursive function for dfs 
// traversal dfsUtil() 
void dfs(int a,int &b) 
{ 

	// keep track of node visited 
	visited[a]=1; 
	b++; 
	start[a]=b; 
	dfs_order.push_back(a); 
	
	for(vector<int>:: iterator it=adj[a].begin(); 
						it!=adj[a].end();it++) 
	{ 
		if(!visited[*it]) 
		{ 
			dfs(*it,b); 
		} 
	} 
	endd[a]=b; 
} 

// Function to print the subtree nodes 
void Print(int n) 
{ 
	for(int i = 0; i < n; i++) 
	{ 
		// if node is leaf node 
		// start[i] is equals to endd[i] 
		if(start[i]!=endd[i]) 
		{ 
			cout<<"subtree of node "<<i<<" is "; 
			for(int j=start[i]+1;j<=endd[i];j++) 
			{ 
				cout<<dfs_order[j-1]<<" "; 
			} 
			cout<<endl; 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	// No of nodes n = 10 
	int n =8, c = 0; 

	
	adj[0].push_back(10); 
	adj[0].push_back(5); 
	adj[0].push_back(21); 
	adj[1].push_back(1); 
	adj[1].push_back(6); 
	adj[4].push_back(17); 
	adj[4].push_back(19); 
//	
//	cout << adj[0][1];
////	getch();
	// Calling dfs for node 0 
	// Considering root node at 0 
	dfs(0, c); 

	// Print child nodes 
	Print(n); 

	return 0; 

} 

