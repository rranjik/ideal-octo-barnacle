class Solution {
public:
    int shortestDistance(vector<string>& s, string word1, string word2) {
        vector<bool> v(s.size(), false);
        vector<int> res(s.size());
        queue<int> q;
        for(int i = 0; i<s.size(); i++){
            if(s[i]==word1){
                v[i] = true;
                res[i] = 0;
                q.push(i);
            }
        }
        while(!q.empty()){
            auto n = q.front();
            q.pop();
            auto prev = n-1;
            auto next = n+1;
            if(prev>=0){
                if(!v[prev]){
                    if(s[prev]==word2) return res[n]+1;
                    v[prev] = true;
                    res[prev] = res[n]+1;
                    q.push(prev);
                }
            }
            if(next<s.size()){
                if(!v[next]){
                    if(s[next]==word2) return res[n]+1;
                    v[next] = true;
                    res[next] = res[n]+1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
