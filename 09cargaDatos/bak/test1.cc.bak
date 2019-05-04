#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

const long int MAX = 100000000;

void inline f(const char *arr) { int b = sqrt(7); }

int main()
{
    char arr[1024 * 1024];
    clock_t start, end;
    start = clock();
    int a = 7;
    for (int i{0}; i != MAX; i++) f(arr);
    end = clock();
    cout << "Tiempo:" << (double(end - start) / double(CLOCKS_PER_SEC)) << endl;
}
