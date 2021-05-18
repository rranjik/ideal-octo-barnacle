class ZeroEvenOdd {
private:
    int n;
    bool print0 = true;
    bool printeven = false;
    bool printodd = false;
    mutex m0; mutex meven; mutex modd;
    condition_variable cv0;
    condition_variable cveven;
    condition_variable cvodd;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        int j = 0;
        for(int i = 0; i<n; i++){
            unique_lock lk(m0);
            cv0.wait(lk, [&](){return print0;});
            cout<<"print 0"<<endl;
            printNumber(0);
            lk.unlock();
            print0 = false;
            j++;
            if(j%2) {
                if(j<=n){
                    printodd = true;
                    cvodd.notify_one();
                }
            }else {
                if(j<=n){
                    printeven = true;
                    cveven.notify_one();
                }
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for(int j = 2; j<=n; j+=2){
            unique_lock lk(meven);
            cveven.wait(lk, [&](){return printeven;});
            cout<<"print "<<j<<endl;
            printNumber(j);
            lk.unlock();
            printeven = false;
            print0 = true;
            cv0.notify_one();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int j = 1; j<=n; j+=2){
            unique_lock lk(modd);
            cvodd.wait(lk, [&](){return printodd;});
            cout<<"print "<<j<<endl;
            printNumber(j);
            lk.unlock();
            printodd = false;
            print0 = true;
            cv0.notify_one();
        }
    }
};
