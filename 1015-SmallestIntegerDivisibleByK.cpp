class Solution {
public:
    int k;
    unordered_map<int, int> ca;
    int mod(int s){
        if(ca.find(s)!=ca.end()) return ca[s];
        if(s==1) {
            ca[s] = 1%k;
            return 1%k;
        }
        else {
            auto res = (((mod(s-1)*10)%k)+1)%k;
            ca[s] = res;
            return res;
        }
    }
    unordered_set<int> r;
    int smallestRepunitDivByK(int K) {
        k = K;
        int s =1;
        int rem = mod(s);
        while(r.find(rem)==r.end()&&rem!=0){
            r.insert(rem);
            s++;
            rem = mod(s);
        }
        if(r.find(rem)!=r.end()) return -1;
        else return s;
    }
};
