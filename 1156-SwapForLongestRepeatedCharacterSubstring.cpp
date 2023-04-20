class Solution {
public:
    int maxRepOpt1(string t) {
        unordered_map<char, vector<pair<int, int>>> m;
        auto last = t[0];
        auto lsi = 0;
        int f = 0;
        for(int i = 0; i<t.size(); i++){
            if(t[i]==last){
                f++;
            }else{
                m[last].push_back({lsi, i-1});
                f = 1;
                lsi = i;
                last = t[i];
            }
        }
        m[last].push_back({lsi, t.size()-1});
        int res{};
        unordered_map<char, int> c;
        for(const auto& it : m){
            cout<<it.first<<"->";
            for(const auto& p : it.second){
                cout<<"("<<p.first<<", "<<p.second<<") ";
            }
            cout<<endl;
        }
        for(const auto& it : m){
            auto ch = it.first;
            for(int i = 0; i<it.second.size(); i++){
                auto p = it.second[i];
                auto si  = p.first;
                auto ei  = p.second;
                //just yourself
                res = max(res, ei-si+1);
                //if there's a group next to you but just one char apart
                if(i+1<it.second.size()&&ei+2==it.second[i+1].first){
                    //then you can swap the ends of one of the list 
                    //with the char in the middle and the total is the 
                    //sum of the two parts
                    //it.second[i+1].second-1 is the new ending (one char off because 
                    //it was swapped with the middle char)
                    //'it.second[i+1].second-1'-start+1 to get count
                    res = max(res, it.second[i+1].second-1-si+1);
                    //if there's one other group besides this
                    //we can take one from it. i.e swap the middle weird char
                    //for free and the total length is 
                    //end-start+1 where end is the end of the second group because 
                    //it stays as such
                    if(m[ch].size()>=3) {
                        res = max(res, it.second[i+1].second-si+1);
                    }
                }
                //you can always expand a group by one if there's just one other group
                //somewhere out there
                if(m[ch].size()>=2) {
                    res = max(res, ei-si+1+1);
                }
            }
        }
        return res;
    }
};
