#include <iostream>
#include <time.h>
#include <sys/time.h>
using namespace std;

class randomGen {
private:
    long a = 0X5DEECE6602;
    long b = 0XBL;
    long m = (1L << 48) - 1;
    static long seed;
public:
    long getMicrotime()
    {
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
    }
    randomGen()
    {
        this->seed = getMicrotime();
    }
    randomGen(long seed)
    {
        this->seed = seed;
    }
    int nextint1(int n)
    {
        return getMicrotime() % n;
    }

    int nextint2(int n) 
    {
        long temp = (a * seed + b) & m;
        seed = temp;
        return (int)(temp % n);
    }
    /*Not working*/
    int nextint3(long n) // RAND_MAX assumed to be 32767 
    { 
        long next = (next * 1103515245) + 12345; 
        return (unsigned int)((next/65536) % 32768); 
    } 
};
long randomGen:: seed = 1;

int main()
{
    int n = 10;
    randomGen r(100);
    for (int i = 0; i < n; i++ )
        cout << r.nextint1(10) << "\t";
    cout << endl;
    for (int i = 0; i < n; i++ )
        cout << r.nextint2(10) << "\t";
    cout << endl;
    for (int i = 0; i < n; i++ )
        cout << r.nextint3(10)%10 << "\t";
    cout << endl;
    return 0;
}
