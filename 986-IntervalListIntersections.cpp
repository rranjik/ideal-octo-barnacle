class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, 
        vector<vector<int>>& b) {
        int i = 0; int j = 0;
        vector<vector<int>> res;
        res.push_back({-1, -2});
        while(i<a.size()&&j<b.size()){
            if(a[i][0]<=b[j][0]){
                if(b[j][0]<=a[i][1]){
                    vector<int> r = {b[j][0], min(b[j][1], a[i][1])};
                    if(res.back()[1]==r[0]){
                        res.back()[1] = r[1];
                    }else res.push_back(r);
                }
                if(a[i][1]<b[j][1]) i++;
                else j++;
            }
            else if(b[j][0]<=a[i][0]){
                if(a[i][0]<=b[j][1]){
                    vector<int> r = {a[i][0], min(b[j][1], a[i][1])};
                    if(res.back()[1]==r[0]){
                        res.back()[1] = r[1];
                    }else res.push_back(r);
                }
                if(a[i][1]<b[j][1]) i++;
                else j++;
            }
        }
        res.erase(res.begin());
        return res;
    }
};
