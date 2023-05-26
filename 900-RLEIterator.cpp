class RLEIterator {
public:
    vector<int> A;
    int i{};
    RLEIterator(vector<int>& A) {
        this->A = A;
    }
    
    int next(int n) {
        while(i<A.size()&&n>A[i]){
            n-=A[i];
            i+=2;
        }
        if(i>=A.size()) return -1;
        A[i]-=n;
        return A[i+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
