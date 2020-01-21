#include<thread>
#include<mutex>
using namespace std;
class FooBar {
private:
    int n;
    mutex m;
    bool pB = true;
    bool pF = false;
    condition_variable cv;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]{return this->pB;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            pB = false;
            pF = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> l(m);
            cv.wait(l, [this]{return this->pF;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            pF = false;
            pB = true;
            cv.notify_all();
        }
    }
};
