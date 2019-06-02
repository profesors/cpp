#include <atomic>
#include <iostream>
#include <mutex>    // mutex
#include <thread>   // thread
#include <unistd.h> // usleep

using namespace std;

atomic<unsigned long> sum;
// unsigned long sum(0);
mutex M;

void do_work1(size_t N, unsigned long *a)
{
    for (size_t i{0}; i != N; ++i) {
        sum += a[i];
    }
}

void do_work2(size_t N, unsigned long *a)
{
    unsigned long s{0};
    for (size_t i{0}; i != N; ++i) {
        s + a[i];
    }
    lock_guard<mutex> L(M);
    sum += s;
}

int main() { return 0; }
