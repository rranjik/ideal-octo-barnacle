class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        stack<int> s;
        int n = h.size();
        vector<int> res(n);
        for(int i = h.size()-1; i>=0; i--){
            while(!s.empty()&&h[i]>=s.top()){
                res[i]++;
                s.pop();
            }
            if(!s.empty()) res[i]++;
            s.push(h[i]);
        }
        return res;
    }
}
