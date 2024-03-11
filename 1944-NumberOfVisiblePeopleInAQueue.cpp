class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        int n = h.size();
        vector<int> res(n);
        stack<int> s;
        for(int i = h.size()-1; i>=0; i--){
            while(!s.empty()&&h[i]>=s.top()){
                s.pop();
                res[i]++;
            }
            if(!s.empty()) res[i]++;
            s.push(h[i]);
        }
        return res;
    }
};
