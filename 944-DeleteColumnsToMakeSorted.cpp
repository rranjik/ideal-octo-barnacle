class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        for(int j = 0; j<A[0].size(); j++){
            vector<char> c;
            for(int i = 0; i<A.size(); i++){
                c.push_back(A[i][j]);
            }
            if(!is_sorted(begin(c), end(c))){
                res++;
            }
        }
        return res;
    }
};
