class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        struct state{
            int v;
            int f;
            state(int _v, int _f):v(_v), f(_f){}
            bool operator<(const state& other) const {
                if(this->f!=other.f)
                return this->f<other.f;
                return v<other.v;
            }
        };
        priority_queue<state> q;
        unordered_map<int, int> m;
        for(const auto& b : barcodes) m[b]++;
        for(const auto& it : m){
            q.push({it.first, it.second});
        }
        vector<int> res;
        while(!q.empty()){
            auto first = q.top();
            q.pop();
            res.push_back(first.v);
            if(!q.empty()){
                auto second = q.top();
                q.pop();
                res.push_back(second.v);
                second.f--;
                first.f--;
                if(first.f) q.push(first);
                if(second.f) q.push(second);
            }else if(first.f-1){
                return {};
            }
        }
        return res;
    }
};
