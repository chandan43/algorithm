#include <iostream>
#include <string>
#include <iterator> 
#include<set> 
using namespace std;

class KemptySlots {
public: 
     set<int> tset; 
     set<int>::iterator itr;
     set<int>::iterator floor(int key) {
        itr = tset.lower_bound(key);
        if (*itr != key)
            return itr;
        else { 
            itr--;
            return itr;
        }
     }
     set<int>::iterator ceil(int key){
        itr = tset.upper_bound(key);
        return itr;
     }
     int kemptySlot2(int *arr, int k)
     {
        if(tset.size() == 0) {
            tset.insert(arr[0]);
        }
        /*Size is fixed : 7*/
        for(int i = 1; i < 7; i++) {
            itr = floor(arr[i]);
            cout << "floor" <<*itr <<endl; 
            int prev = *itr;
            if (prev && (arr[i] - prev - 1) == k )
                return i+1;
            itr = ceil(arr[i]);
            cout << "Ceil "<<*itr <<endl; 
            int next = *itr;
            if (next && (arr[i] - next - 1) == k )
                return i+1;
            tset.insert(arr[i]);
        }
     return -1;
        
     }
     
};
int main()
{
    int input[7] = {6, 0, 5, 1, 3, 2,4};
    KemptySlots myslot;
    cout << myslot.kemptySlot2(input,2)<< endl;
    set<int>::iterator itr; 
    cout << "\nThe map events is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = myslot.tset.begin(); itr != myslot.tset.end(); ++itr) { 
        cout << '\t' << *itr << '\n'; 
    } 
    return 0;
    //myslot.tset.insert(1); 
    myslot.tset.insert(2); 
    myslot.tset.insert(3); 
    myslot.tset.insert(4); 
    //set<int>::iterator itr; 
    cout << "\nThe map events is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = myslot.tset.begin(); itr != myslot.tset.end(); ++itr) { 
        cout << '\t' << *itr << '\n'; 
    } 
    itr = myslot.floor(10);
    cout << "Floor:: "<< *itr << endl;  
    itr = myslot.ceil(10);
    cout << "Ceil :: "<< *itr << endl;  
    cout << endl; 
    return 0; 
}
