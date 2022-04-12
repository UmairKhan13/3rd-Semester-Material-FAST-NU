#include <iostream>
const int T_S = 200;
using namespace std;
struct HashTableEntry {
   int v, k;
   HashTableEntry *n;
   HashTableEntry *p;
   HashTableEntry(int k, int v) {
      this->k = k;
      this->v = v;
      this->n = NULL;
   }
};
class HashMapTable {
   public:
      HashTableEntry **ht, **top;
      HashMapTable() {
         ht = new HashTableEntry*[T_S];
         for (int i = 0; i < T_S; i++)
            ht[i] = NULL;
      }
      int HashFunc(int key) {
         return key % T_S;
      }
      void Insert(int k, int v) {
         int hash_v = HashFunc(k);
         HashTableEntry* p = NULL;
         HashTableEntry* en = ht[hash_v];
         while (en!= NULL) {
            p = en;
            en = en->n;
         }
         if (en == NULL) {
            en = new HashTableEntry(k, v);
            if (p == NULL) {
               ht[hash_v] = en;
            } else {
               p->n = en;
            }
         } else {
            en->v = v;
         }
      }
      void Remove(int k) {
         int hash_v = HashFunc(k);
         HashTableEntry* en = ht[hash_v];
         HashTableEntry* p = NULL;
         if (en == NULL || en->k != k) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         }
         while (en->n != NULL) {
            p = en;
            en = en->n;
         }
         if (p != NULL) {
            p->n = en->n;
         }
         delete en;
         cout<<"Element Deleted"<<endl;
      }
      void SearchKey(int k) {
         int hash_v = HashFunc(k);
         bool flag = false;
         HashTableEntry* en = ht[hash_v];
         if (en != NULL) {
            while (en != NULL) {
               if (en->k == k) {
                  flag = true;
               }
               if (flag) {
                  cout<<"Element found at key "<<k<<": ";
                  cout<<en->v<<endl;
               }
               en = en->n;
            }
         }
         if (!flag)
            cout<<"No Element found at key "<<k<<endl;
      }
      ~HashMapTable() {
         delete [] ht;
      }
};
int main() {
   HashMapTable hash;
   int k, v;
   int c;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>v;
            cout<<"Enter key at which element to be inserted: ";
            cin>>k;
            hash.Insert(k, v);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            hash.SearchKey(k);
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.Remove(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }
   return 0;
}
