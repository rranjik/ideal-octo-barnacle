class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& n) {
        vector<int> res(n.size(), -1);
        stack<int> s;
        //int stop = 0;
        //int mod = n.size();
        for(int i = 0; i<n.size(); i++){
            while(!s.empty()&&n[s.top()]<n[i]){
                res[s.top()] = n[i];
                s.pop();
            }
            //if(s.empty()){
            //    stop = i;
            //}
            s.push(i);
        }
        if(!s.empty()){
            for(int i = 0;i<n.size(); i++){
                while(!s.empty()&&n[s.top()]<n[i]){
                    res[s.top()] = n[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        return res;
    }
};
