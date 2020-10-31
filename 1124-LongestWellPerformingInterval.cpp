class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> m;
        m[0] = -1;
        int count = 0;
        int res = 0;
        for(int i = 0; i<hours.size(); i++){
            if(hours[i]<=8) count--;
            else {
                count++;
            }
            if(count>0)
                res = i+1;
            else if(m.find(count-1)!=m.end()){
                res = max(res, i-m[count-1]);
            }
            if(m.find(count)==m.end()){
                m[count] = i;
            }
        }
        for(auto it : m){
            cout<<it.first<<" "<<it.second<<endl;
        }
        return res;
    }
};
