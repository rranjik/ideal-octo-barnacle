class FizzBuzz {
private:
    int n;
    //zero is proccessed initially
    bool proc_n = true;
    bool proc_f = false;
    bool proc_b = false;
    bool proc_fb = false;
    mutex m_proc_n; condition_variable cv_proc_n;
    mutex m_proc_f; condition_variable cv_proc_f;
    mutex m_proc_b; condition_variable cv_proc_b;
    mutex m_proc_fb; condition_variable cv_proc_fb;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(int i = 1; i<=n; i++){
            unique_lock lk(m_proc_b);
            cv_proc_b.wait(lk, [&](){return proc_b;});
            if(i%3==0&&i%5!=0) printFizz();
            lk.unlock();
            //lock yourself up
            proc_b = false;           
            //set flag that you're done
            proc_f = true;
            //tell others that you're done
            cv_proc_f.notify_one();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for(int i = 1; i<=n; i++){
            unique_lock lk(m_proc_fb);
            cv_proc_fb.wait(lk, [&](){return proc_fb;});
            if(i%5==0&&i%3!=0) printBuzz();
            lk.unlock();
            //lock yourself up
            proc_fb = false;
            //set flag that you're done
            proc_b = true;
            //tell others that you're done
            cv_proc_b.notify_one();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for(int i = 1; i<=n; i++){
            unique_lock lk(m_proc_n);
            cv_proc_n.wait(lk, [&](){return proc_n;});
            //cout<<"entering fizzbuzz"<<endl;
            if(i%5==0&&i%3==0) printFizzBuzz();
            lk.unlock();
            //lock yourself up
            proc_n = false;
            //set flag that you're done
            proc_fb = true;
            //tell others that you're done
            cv_proc_fb.notify_one();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for(int i = 1; i<=n; i++){
            unique_lock lk(m_proc_f);
            cv_proc_f.wait(lk, [&](){return proc_f;});
            if(i%5!=0&&i%3!=0) printNumber(i);
            lk.unlock();
            //lock yourself up
            proc_f = false;
            //set flag that you're done
            proc_n = true;
            //tell others that you're done
            cv_proc_n.notify_one();
        }
    }
};
