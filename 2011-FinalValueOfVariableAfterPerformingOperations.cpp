class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(const auto& op : operations){
            if(op.find('+')!=string::npos){
                res++;
            }else res--;
        }
        return res;
    }
};
