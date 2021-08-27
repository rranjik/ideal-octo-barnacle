class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> s;
        int done = 0;
        for(const auto& p : pushed){
            s.push(p);
            while(!s.empty()&&done<n&&s.top()==popped[done]){
                s.pop();
                done++;
            }
        }
        if(done == n) return true;
        return false;
    }
};
