class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        res.push_back({-1, 0});
        while(i<A.size()&&j<B.size()){
            if(A[i][0]<=B[j][0]){
                if(B[j][0]<=A[i][1]){
                    vector<int> r = {B[j][0], min(B[j][1], A[i][1])};
                    if(res.back()[1]==r[0]){
                        res.back()[1] = min(B[j][1], A[i][1]);
                    }else {
                        res.push_back(r);
                    }
                }
                if(B[j][1]<=A[i][1]) j++;
                else i++;
            }else{
                if(A[i][0]<=B[j][1]){
                    vector<int> r = {A[i][0], min(A[i][1], B[j][1])};
                    if(res.back()[1]==r[0]){
                        res.back()[1] = min(A[i][1], B[j][1]);
                    }else {
                        res.push_back(r);
                    }
                }
                if(A[i][1]<=B[j][1]) i++;
                else j++;
            }
            //for(const auto& i : res){
            //    cout<<"["<<i[0]<<", "<<i[1]<<"]"<<" ";
            //}
            //cout<<endl;
        }
        if(res[0][1] == 0){
            res.erase(res.begin());
        }else {
            res[0][0] = 0;
        }
        return res;
    }
};
