class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ab;
        for(const auto& a : A){
            for(const auto& b : B){
                ab[a+b]++;
            }
        }
        int res = 0;
        for(const auto& c : C){
            for(const auto& d: D){
                res+=ab[-c-d];
            }
        }
        return res;
        //unordered_set<int> d;
        //map<int, int> df;
        //for(const auto& n : D){
        //    d.insert(n);
        //    df[n]++;
        //}
        //int res = 0;
        //set<vector<int>> rres;
        //for(int i = 0; i<A.size(); i++){
        //    for(int j = 0; j<B.size(); j++){
        //        for(int k= 0; k<C.size(); k++){
        //            int s = A[i]+B[j]+C[k];
        //            int t = -s;
        //            if(d.find(t)!=d.end()){
        //                //cout<<"a = "<<A[i]<<"; b = "<<
        //                    //B[j]<<"; c = "<<C[k]<<"; t = "<<t<<endl;
        //                //vector<int> r{A[i], B[j], C[k], t};
        //                //sort(begin(r), end(r));
        //                res+=df[t];
        //                //rres.insert(r);
        //            }
        //        }
        //    }
        //}
        //return res;
    }
};
