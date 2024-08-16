class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k==0) return s;
        int n = s.size();
        string res;
        unordered_map<char, int> d;
        priority_queue<pair<int, char>> pq;
        for(const auto& c : s) d[c]++;
        for(const auto& [c, f]:d) pq.push({f,c});
        while(!pq.empty()){
            vector<pair<int, char>> ca;
            for(int i = 0; i<k; i++){
                if(pq.empty()) return "";
                auto [f, c] = pq.top(); pq.pop();
                res.push_back(c);
                if(res.size()==n) return res;
                if(f-1) ca.push_back({f-1, c});
            }
            for(const auto& p : ca) pq.push(p);
        }
        return "";
    }
};
