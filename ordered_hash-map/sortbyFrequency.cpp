#include <iostream>
#include <iterator> 
#include <map> 
using namespace std;

class sortbyfrequency {
public:
    string frequencySort(string s) {
       int bkp = 0;
       map<char, int> freq;
       map<char, int>::iterator itr;
       multimap<int, char> revfreq;
        for (int i = 0; i < s.size(); i++) {
            auto itr = freq.find(s[i]);
            if(itr != freq.end()) {
                freq.insert({ s[i], ++itr->second });
            } else 
                freq.insert({ s[i], 1 });
        } 
        int i = 0;
        for (auto itr = freq.begin(); itr != freq.end(); ++itr) 
             revfreq.insert({ itr->second, itr->first });
        multimap<int, char>::iterator itr;
        for (auto itr = revfreq.begin(); itr != revfreq.end(); ++itr) 
            cout << itr->first << itr->second<< endl;
        for (auto itr = revfreq.rbegin(); itr != revfreq.rend(); ++itr) {
             while(i < itr->first) {
                 s[i+bkp] = itr->second;
                 i++;
             }
             bkp += itr->first;
             i = 0;
        }
        return s;
    }
};

int main()
{
	sortbyfrequency sfreq;
	cout << sfreq.frequencySort("tree") << endl;
	return 0;
}
