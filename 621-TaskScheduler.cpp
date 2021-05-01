class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f = vector<int>(26, 0);
        for(const auto& t : tasks) f[t-'A']++;
        priority_queue<int> q;
        for(int i = 0; i<26; i++){
            if(f[i]) q.push(f[i]);
        }
        int res = 0;
        while(!q.empty()){
            vector<int> exec;
            for(int i = 0; i<n+1; i++){
                if(!q.empty()) {
                    exec.push_back(q.top()-1);
                    q.pop();
                }
            }
            for(const auto& t : exec){
                if(t) q.push(t);
            }
            res+=(q.empty()?exec.size():n+1);
        }
        return res;
    }
};
