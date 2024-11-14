class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
        for(const auto& a : arr){
            auto t = a;
            while(!s.empty()&&s.top()>a){
                t = max(t, s.top()); s.pop();
            }
            s.push(t);
        }
        return s.size();
    }
};
