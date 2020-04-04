class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        cout<<"here 1"<<endl;
        auto pairs = p;
        int n = pairs.size();
        if(!n) return 0;
        cout<<"here 2.1"<<endl;
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){return a[1]<b[1];});
        cout<<"here 2.2"<<endl;
        vector<int> ls = pairs[0];
        int res = 1;
        for(int i = 1; i<n; i++){
            if(pairs[i][0]>ls[1]){
                res++;
                ls = pairs[i];
            }
        }
        cout<<"here 3"<<endl;
        return res;
    }
};
