class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        multiset<int, greater<int>> z, o, t, f;
        int sum = 0;
        for(const auto& d : digits){
            sum+=d;
            if(d%3==2) t.insert(d);
            else if(d%3==1) o.insert(d);
            else z.insert(d);
        }
        if(sum%3==1){
            if(o.size()>0){
                o.erase(prev(o.end()));
            }else if(t.size()>1){
                t.erase(prev(t.end()));
                t.erase(prev(t.end()));
            }//else t.clear();
        }else if(sum%3==2){
            if(t.size()>0){
                t.erase(prev(t.end()));
            }else if(o.size()>1){
                o.erase(prev(o.end()));
                o.erase(prev(o.end()));
            }//else o.clear();
        }
        f.insert(begin(z), end(z));
        f.insert(begin(t), end(t));
        f.insert(begin(o), end(o));
        string res;
        for(const auto& it : f) res+=to_string(it);
        if(res.size()>0&&res[0]=='0') return "0";
        return res;
    }
};
