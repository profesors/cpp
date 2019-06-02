#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h> // usleep

using namespace std;

mutex mtx;

void do_work()
{
    for (int i{0}; i != 1000; ++i) {
        cout << i << endl;
        usleep(100000);
    }
}

class Contador {
  public:
    int n{0};

    Contador(int n) : n(n) {}

    void operator()()
    {
        for (int i{0}; i != 1000; ++i) {
            mtx.lock();
            cout << n << endl;
            mtx.unlock();
            usleep(1000);
        }
    }
};

int main()
{
    atomic<int> c{0};
    Contador a = Contador(1);
    Contador b = Contador(2);
    thread t1(do_work);
    thread t2(do_work);
    t1.join();
    t2.join();
    return 0;
}
