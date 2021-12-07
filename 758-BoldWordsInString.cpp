class Solution {
public:
    using pii = pair<int, int>;
    vector<pii> merge(vector<pii>& intervals){
        vector<pii> res;
        for(const auto& i : intervals){
            if(!res.size()){
                res.push_back(i);
            }else{
                if(res.back().second>=i.first){
                    auto l = res.back();
                    res.pop_back();
                    l.second = max(l.second, i.second);
                    res.push_back(l);
                }else{
                    res.push_back(i);
                }
            }
        }
        return res;
    }
    string boldWords(vector<string>& words, string S) {
        vector<pii> intervals;
        for(const auto& w : words){
            int pos = 0;
            int last_pos = 0;
            while((pos=S.find(w, last_pos))!=string::npos){
                intervals.push_back(make_pair(pos, pos+w.length()));
                last_pos = pos+1;
            }
        }
        for(const auto& e : intervals){
            cout<<e.first<<" "<<e.second<<endl;
        }
        sort(begin(intervals), end(intervals), [](const auto& a, const auto& b){return a.first<b.first;});
        if(!intervals.size()) return S;
        auto mintervals = merge(intervals);
        for(const auto& e : mintervals){
            cout<<e.first<<" "<<e.second<<endl;
        }
        for(int i = mintervals.size()-1; i>=0; i--){
            S.insert(mintervals[i].second, "</b>");
            S.insert(mintervals[i].first, "<b>");
        }
        return S;
    }
};
