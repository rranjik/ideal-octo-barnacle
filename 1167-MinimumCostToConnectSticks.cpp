class Solution {
public:
    int connectSticks(vector<int>& a) {
        if(a.size()==1)return 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i<a.size(); i++){
            q.push(a[i]);
        }
        int res = 0;
        while(!q.empty()){
            int s = q.top();
            q.pop();
            if(q.empty()){
                break;
            }else{
                int as = q.top();
                q.pop();
                int ns = s + as;
                res += (s+as);
                q.push(ns);
            }
        }
        return res;
    }
};
