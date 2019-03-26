#include <iostream>
#include <list> 
#include <queue>
using namespace std;
class CopyFile {
public:
    int merge11(int* input,int size){
        int totalcost = 0;
        list <int> file;
        for (int i = 0;i < size; i++)
            file.push_front(input[i]);
        while(file.size() > 1) {
            file.sort();
            int cost1 = file.front();
            file.pop_front();
            int cost2 = file.front();
            file.pop_front();
            file.push_front(cost1+cost2);
            totalcost += (cost1 + cost2);
        }
        return totalcost;
    }
    int merge12(int* input,int size){
        int totalcost = 0;
        list <int> file;
        int flag = 0;
        for (int i = 0;i < size; i++)
            file.push_front(input[i]);
            file.sort();
            list <int> :: iterator it;
        while(file.size() > 1) {
            int cost1 = file.front();
            file.pop_front();
            int cost2 = file.front();
            file.pop_front();
            int temp = cost1 + cost2;
            int i = 0;
            flag = 0;
            for(it = file.begin(); it != file.end(); ++it) {
                if (temp < *it) {
                    file.insert(it, 1 , temp);
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                file.push_back(temp);
                
            totalcost += (cost1 + cost2);
        }
        return totalcost;
    }
    int merge13(int* input,int size){
        int totalcost = 0;
        priority_queue <int> file;
        for (int i = 0;i < size; i++)
            file.push(input[i]);
        while(file.size() > 2) {
            int cost1 = file.top();
            file.pop();
            int cost2 = file.top();
            file.pop();
            int temp = cost1 + cost2;
            file.push(temp);
            totalcost += temp;
        }
        return totalcost;
    }
};

int main()
{
    int input[6] = {10, 5, 4,11, 19, 20};
    CopyFile c;
    cout << "Min Cost:: "<<c.merge11(input, 6) << endl;
    cout << "Min Cost:: "<<c.merge12(input, 6) << endl;
    cout << "Min Cost:: "<<c.merge13(input, 6) << endl;
    return 0;
}
