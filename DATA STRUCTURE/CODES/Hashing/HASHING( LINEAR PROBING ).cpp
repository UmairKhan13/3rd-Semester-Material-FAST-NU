#include<bits/stdc++.h> 
using namespace std; 
  

template<typename K, typename V>   
class HashNode 
{ 
    public: 
    V value; 
    K key; 
      

    HashNode(K key, V value) 
    { 
        this->value = value; 
        this->key = key; 
    } 
}; 

  
template<typename K, typename V>
class HashMap 
{ 
    //hash element array 
    HashNode<K,V> **arr; 
    int capacity; 
    //current size 
    int size; 
    //dummy node 
    HashNode<K,V> *dummy; 
  
    public: 
    HashMap() 
    { 
        capacity = 20; 
        size=0; 
        arr = new HashNode<K,V>*[capacity]; 
          
        for(int i=0 ; i < capacity ; i++) 
            arr[i] = NULL; 
          
        dummy = new HashNode<K,V>(-1, -1); 
    } 
    int hashCode(K key) 
    { 
        return key % capacity; 
    } 

      
    void insertNode(K key, V value) 
    { 
        HashNode<K,V> *temp = new HashNode<K,V>(key, value); 
          

        int hashIndex = hashCode(key); 

          
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
               && arr[hashIndex]->key != -1) 
        { 
            hashIndex++; 
            hashIndex %= capacity; 
        } 

          
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
            size++; 
        arr[hashIndex] = temp; 
    } 

      
    V deleteNode(int key) 
    { 
        int hashIndex = hashCode(key); 
          
        while(arr[hashIndex] != NULL) 
        { 
            if(arr[hashIndex]->key == key) 
            { 
                HashNode<K,V> *temp = arr[hashIndex]; 
                  
                arr[hashIndex] = dummy; 
                  
                size--; 
                return temp->value; 
            } 
            hashIndex++; 
            hashIndex %= capacity; 
  
        } 
          
        return NULL; 
    } 
      
    //Function to search the value for a given key 
    V get(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
        int counter=0; 
        //finding the node with given key    
        while(arr[hashIndex] != NULL) 
        {    int counter =0; 
             if(counter++>capacity)  //to avoid infinite loop 
                return NULL;         
            //if node found return its value 
            if(arr[hashIndex]->key == key) 
                return arr[hashIndex]->value; 
            hashIndex++; 
            hashIndex %= capacity; 
        } 
          
        //If not found return null 
        return NULL; 
    } 
      
    //Return current size  
    int sizeofMap() 
    { 
        return size; 
    } 
      
   
    bool isEmpty() 
    { 
        return size == 0; 
    } 
      
   
    void display() 
    { 
        for(int i=0 ; i<capacity ; i++) 
        { 
            if(arr[i] != NULL && arr[i]->key != -1) 
                cout << "key = " << arr[i]->key  
                     <<"  value = "<< arr[i]->value << endl; 
        } 
    } 
}; 
   
int main() 
{ 
    HashMap<int, int> *h = new HashMap<int, int>; 
    h->insertNode(1,1); 
    h->insertNode(2,2); 
    h->insertNode(2,3); 
    h->display(); 
    cout << h->sizeofMap() <<endl; 
    cout << h->deleteNode(2) << endl; 
    cout << h->sizeofMap() <<endl; 
    cout << h->isEmpty() << endl; 
    cout << h->get(2); 
  
    return 0; 
} 
