class Solution {
public:
    void print(const vector<int>& a){
        for(const auto& e : a){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        vector<int> d(A.size()-1);
        for(int i = 0; i<A.size()-1; i++){
            d[i] = A[i+1]-A[i];
        }
        print(d);
        vector<int> ei;
        for(int j = 0; j<d.size()-1; j++){
            if(d[j]==d[j+1]){
                ei.push_back(j+2);
            }
        }
        print(ei);
        vector<int> count(A.size(), 0);
        for(int k = 0; k<ei.size(); k++){
            count[ei[k]] = 1;
        }
        for(int i = 1; i<count.size(); i++){
            if(count[i]){
                count[i]+=count[i-1];
            }
        }
        int res = 0;
        for(const auto& t :count)
            res+=t;
        return res;
    }
};
