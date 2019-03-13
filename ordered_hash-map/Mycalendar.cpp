#include <iostream>
#include <string>
#include <iterator> 
#include <map> 
using namespace std;

class MyCalender {
public: 
     map<int, int> events;
     map<int, int>::iterator itr;
     map<int, int>::iterator floor(int key) {
        itr = events.lower_bound(key);
        if (itr->first == key)
            return itr;
        else { 
            itr--;
            return itr;
        }
     }
     map<int, int>::iterator ceil(int key){
        itr = events.upper_bound(key);
        return itr;
     }
     bool book(int start, int end) {
        if(events.size() == 0) {
            events.insert(pair<int, int>(start, end));
            return true;
        }
        itr = floor(start);
        int floorkey = itr->first;
        /*Key*/
        if (floorkey) {
            int floorval = itr->second;
            if (start < floorval)
                return false;
        }
        itr = ceil(start);
        /* Cpp problem*/
        if(!itr->second) {
            events.insert(pair<int, int>(start, end));
            return true;
        }
        int ceilkey = itr->first;
        if (end > ceilkey)
            return false;
        events.insert(pair<int, int>(start, end));
        return false;
     }
};
int main()
{
    MyCalender mycal;
     // insert elements in random order 
    //mycal.events.insert(pair<int, int>(1, 40)); 
    //mycal.events.insert(pair<int, int>(2, 30)); 
    //mycal.events.insert(pair<int, int>(3, 60)); 
    //mycal.events.insert(pair<int, int>(4, 20)); 
    //mycal.events.insert(pair<int, int>(6, 70)); 
    //mycal.events.insert(pair<int, int>(7, 100)); 
    //mycal.events.insert(pair<int, int>(10, 50)); 
    bool flag;
    flag = mycal.book(1,3);
    flag = mycal.book(4,7);
    flag = mycal.book(8,11);
    flag = mycal.book(10,12);
    flag = mycal.book(12,14);
    // printing map gquiz1 
    map<int, int>::iterator itr; 
    cout << "\nThe map events is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = mycal.events.begin(); itr != mycal.events.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    //itr = mycal.floor(5);
    //cout << "Floor:: "<<itr->first << "\t" << itr->second << endl;  
    //itr = mycal.ceil(5);
    //cout << "Ceil :: "<<itr->first << "\t" << itr->second << endl;  
    //cout << endl; 
    //return 0; 
}
