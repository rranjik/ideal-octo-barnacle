class Foo {
public:
    mutex fmu;
    mutex smu;
    condition_variable frst;
    condition_variable scnd;
    bool first_printed{false};
    bool second_printed{false};
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        {
            lock_guard<mutex> lck(fmu);
            // printFirst() outputs "first". Do not change or remove this line.
            printFirst();
            first_printed = true;
        }
        frst.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(fmu);
        unique_lock<mutex> slck(smu);
        // printSecond() outputs "second". Do not change or remove this line.
        frst.wait(lck, [this] { return first_printed; });
        printSecond();
        second_printed = true;
        scnd.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(smu);
        // printThird() outputs "third". Do not change or remove this line.
        scnd.wait(lck, [this] { return second_printed; });
        printThird();
    }
};
