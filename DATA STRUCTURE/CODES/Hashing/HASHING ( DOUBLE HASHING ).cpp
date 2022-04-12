#include <bits/stdc++.h> 
using namespace std; 
  
// Hash table size 
#define TABLE_SIZE 13 
  
// Used in second hash function. 
#define PRIME 7 
  
class DoubleHash 
{ 
   
    int *hashTable; 
    int curr_size; 
  
public: 
  
   
    bool isFull() 
    { 
  
   
        return (curr_size == TABLE_SIZE); 
    } 
  
    int hash1(int key) 
    { 
        return (key % TABLE_SIZE); 
    } 
  
  
    int hash2(int key) 
    { 
        return (PRIME - (key % PRIME)); 
    } 
  
    DoubleHash() 
    { 
        hashTable = new int[TABLE_SIZE]; 
        curr_size = 0; 
        for (int i=0; i<TABLE_SIZE; i++) 
            hashTable[i] = -1; 
    } 
  
  
    void insertHash(int key) 
    { 
        // if hash table is full 
        if (isFull()) 
            return; 
  
        // get index from first hash 
        int index = hash1(key); 
  
        // if collision occurs 
        if (hashTable[index] != -1) 
        { 
            // get index2 from second hash 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) 
            { 
                // get newIndex 
                int newIndex = (index + i * index2) % 
                                        TABLE_SIZE; 
  
                // if no collision occurs, store 
                // the key 
                if (hashTable[newIndex] == -1) 
                { 
                    hashTable[newIndex] = key; 
                    break; 
                } 
                i++; 
            } 
        } 
  
  
        else
            hashTable[index] = key; 
        curr_size++; 
    } 
  
    void displayHash() 
    { 
        for (int i = 0; i < TABLE_SIZE; i++) 
        { 
            if (hashTable[i] != -1) 
                cout << i << " --> "
                     << hashTable[i] << endl; 
            else
                cout << i << endl; 
        } 
    } 
}; 
  

int main() 
{ 
    int a[] = {19, 27, 36, 10, 64}; 
    int n = sizeof(a)/sizeof(a[0]); 
  
    // inserting keys into hash table 
    DoubleHash h; 
    for (int i = 0; i < n; i++) 
        h.insertHash(a[i]); 
  
    // display the hash Table 
    h.displayHash(); 
    return 0; 
}
