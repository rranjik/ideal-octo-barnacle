class Solution {
public:
    vector<int> gc(int n){
        vector<int> res;
        if(n==0){
            res.push_back(0);
            return res;
        }
        else if(n==1){
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        else{
            auto pr = gc(n-1);
            auto p = pr;
            reverse(pr.begin(), pr.end());
            int f = pow(2,n-1);
            for(const auto& k : p){
                res.push_back(k);
            }
            for(const auto& k : pr){
                res.push_back(f+k);
            }
            return res;
        }
    }
    vector<int> cirs(int n, int start){
        auto g = gc(n);
        //for(const auto& nn :g){
        //    cout<<nn<<" ";
        //}
        cout<<endl;
        vector<int> res;
        auto beg = find(g.begin(), g.end(), start);
        //cout<<"found "<<start<<" at index "<<beg-g.begin()<<endl;
        //cout<<"beg - 1 = "<<(beg-1)-g.begin()<<endl;
        res.insert(res.end(), beg, g.end());
        res.insert(res.end(), g.begin(), beg);
        return res;
    }
    vector<int> circularPermutation(int n, int start) {
        return cirs(n, start);
    }
};
