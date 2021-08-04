class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(begin(people), end(people), 
             [](const vector<int>& v1, const vector<int>& v2){
                 if(v1[0]==v2[0]) return v1[1]<v2[1];
                 return v1[0]>v2[0];
             });
        list<vector<int>> l;
        for(int i = 0; i<people.size(); i++){
            auto it = begin(l);
            auto c = people[i][1];
            while(c) {it = next(it); c--;}
            l.insert(it, people[i]);
        }
        vector<vector<int>> res;
        for(const auto& it: l){
            res.push_back({it[0], it[1]});
        }
        return res;
    }
};
