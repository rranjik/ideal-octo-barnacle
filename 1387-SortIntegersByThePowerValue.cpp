class Solution {
public:
    map<int, vector<int>> m;
    void trans(int n){
        auto nc = n;
        int steps = 0;
        while(n!=1){
            if(n%2) n=3*n+1;
            else n/=2;
            steps++;
        }
        m[steps].push_back(nc);
        cout<<"power of "<<nc<<" : "<<steps<<endl;
    }
    int getKth(int lo, int hi, int k) {
        for(int i = lo; i<=hi; i++){
            trans(i);
        }
        auto count = 0;
        for(auto& it :  m){
            for(const auto& n : it.second){
                count++;
                if(count==k) return n;
            }
        }
        return -1;
    }
};
