class Bank {
public:
    vector<long long> b;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size();
        b = balance;
    }
    
    bool transfer(int a1, int a2, long long m) {
        if(a1-1<0||a1-1>=n) return false;
        if(a2-1<0||a2-1>=n) return false;
        if(b[a1-1]<m) return false;
        b[a1-1]-=m;
        b[a2-1]+=m;
        return true;
    }
    
    bool deposit(int a, long long m) {
        if(a-1<0||a-1>=n) return false;
        b[a-1]+=m;
        return true;
    }
    
    bool withdraw(int a, long long m) {
        if(a-1<0||a-1>=n) return false;
        if(b[a-1]<m) return false;
        b[a-1]-=m;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
