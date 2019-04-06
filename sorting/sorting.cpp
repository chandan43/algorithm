#include <iostream>
#include <string>
#include <cstdlib>
#include <iterator> 
#include <set>
#include <queue> 
using namespace std;

#define MAX(a, b) a > b ? a : b

class sorting {
private:
        void swap(int *ex1, int *ex2)
        {
            int temp = *ex1;
            *ex1 = *ex2;
            *ex2 = temp;
        }
public:
    multiset<int> tset; 
    multiset<int>::iterator itr;
    priority_queue <int> tq;
    int* input(int size)
    {
        int* in =  new int[size];
        for (int i = 0; i < size; i++)
            in[i] = rand()%size;
        return in;
    }
    void display(int *in, int size)
    {
        for(int i = 0; i < size; i++)
            cout << in[i] << " ";
        cout << endl;
    }
    /*Normal sort , TC = O(n^2) */
    void sort1(int* in, int size) 
    {
        int mini = 0;
        int exchange = 0;
        for (int i = 0; i < size; i++) {
            mini = i;
            for (int j = i + 1; j < size; j++) {
                if(in[j] < in[mini]) {
                    exchange = 1;
                    mini = j;
                }
                if(exchange) {
                    swap(&in[i], &in[mini]);
                    exchange = 0;
                }
            }
        }
    }
    /*Sort using Hashset, TC = O(nlogn) */
    void sort2(int* in, int size) 
    {
        for (int i = 0; i < size; i++) {
            tset.insert(in[i]);
        }
        int i = 0;
        for (itr = tset.begin(); itr != tset.end(); ++itr) {
            in[i++] = *itr;
        
        }
    }
    /*Sort using priority queue, TC = O(nlogn) */
    void sort3(int* in, int size) 
    {
        for (int i = 0; i < size; i++) {
            tq.push(in[i]);
        }
        int i = size;
        while (!tq.empty())
        {
            in[--i] = tq.top();
            tq.pop();
        }
    }
    /*merge Sort, TC = O(nlogn) */
    void sort4(int* in, int size) 
    {
        int* aux = new int[size];
        auxsort4(0,size - 1, in , aux);
    }

    void auxsort4(int l, int r, int* in, int* aux)
    {
        if (l == r)
            return;
        int mid = l + (r -l)/2;
        auxsort4(l, mid, in, aux);
        auxsort4(mid+1, r, in, aux);
        merge(in, l, mid, r, aux);
    }

    void merge(int* in, int l, int m, int r, int* aux)
    {
        int ls = l, rs = m + 1, k = 0;
        while (ls <= m && rs <= r) {
            if (in[ls] < in[rs])
                aux[k++] = in[ls++];
            else
                aux[k++] = in[rs++];
        }
        while(ls <= m) {
            aux[k++] = in[ls++];
        }
        while(rs <= r) {
            aux[k++] = in[rs++];
        }
        for (int i = 0; i < k; i++) 
            in[l++] = aux[i];
    }
    int partition(int* input, int start, int end)
    {
        int j = start; // pvot input[0]
        //int j = get_random(start, end); // pvot input[random]
        for (int i = start + 1; i <= end; i++){
            if  (input[i] < input[start]) {
                 swap(&input[++j], &input[i]);
            }
        } 
        swap(&input[start],&input[j]);
        return j;
    }
    void auxsort5(int *arr, int start, int end)
    {
	if (start < end) {
		int pvot_pos = partition(arr, start, end);
		auxsort5(arr, start,  pvot_pos - 1);
		auxsort5(arr, pvot_pos + 1, end);
	}
    }
    void sort5(int* in, int size) 
    {
        auxsort5(in, 0, size - 1);
    }
    void sort6(int* in, int size) 
    {
        int divisor = 1;
        int k = findNumberofpasses(in, size);
        for (int d = 0; d < k; d++) {
            auxsort6(in, size, d, divisor);
            divisor *= 10;
        }
    }
    int findNumberofpasses(int* in, int size)
    {
        int max = 0;
        int k = 0;
        for (int i = 0; i < size; ++i) 
           max =  MAX(max, in[i]); 
        while(max > 0) {
            max = max / 10;
            ++k;
        }
        return k;
    }
    void auxsort6(int *in, int size, int d, int divisor)
    {
        int* out = new int[size];
        int* aux = new int[10];
        for (int i = 0;  i < size; i++) {
            int index = (in[i]/divisor)%10;
            aux[index] = ++aux[index];
        }
        display(aux,10);
        for (int i = 1;  i < 10; i++) {
            aux[i] += aux[i - 1];
        }
        display(aux,10);
        for (int i = size-1;  i >=0 ; i--) {
            int index = (in[i]/divisor) % 10;
            out[--aux[index]] = in[i];
        }
        display(out,size);
        for (int i = 0;  i < size ; i++) {
            in[i] = out[i];
        }
    }
};

int main()
{
    int size;
    cin >> size;
    sorting st;
    int* in = st.input(size);
    st.display(in, size);
    //st.sort1(in, size);
    //cout << "Sorted Array" << endl;
    //st.display(in, size);
    //st.sort2(in, size);
    //st.sort3(in, size);
    //st.sort4(in, size);
    //st.sort5(in, size);
    st.sort6(in, size);
    cout << "Sorted Array" << endl;
    st.display(in, size);
    return 0;
}
