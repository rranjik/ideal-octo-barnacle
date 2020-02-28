class Solution {
public:
    vector<string> split(string s){
        vector<string> res;
        stringstream ss(s);
        string split;
        while(getline(ss, split, ' ')){
            res.push_back(split);
        }
        return res;
    }
    struct cmp{
        bool operator()(const vector<string>& s1, const vector<string>& s2)const {
            int i = 1;
            int j = 1;
            while(i<s1.size() && j<s2.size()){
                if(s1[i]<s2[j]){
                    return true;
                }
                else if(s1[i]>s2[j]){
                    return false;
                }
                i++; j++;
            }
            while(i<s1.size()){
                return false;
            }
            while(j<s2.size()){
                return true;
            }
            return true;
        }
    };
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        vector<string> ll;
        vector<string> dl;
        for(const auto& l : logs){
            if(isdigit(l[l.length()-1])){
                dl.push_back(l);
            }
            else ll.push_back(l);
        }
        map<vector<string>, string, cmp> splitll;
        for(const auto& l : ll){
            splitll[split(l)]=(l);
        }
        for(const auto& it : splitll){
            res.push_back(it.second);
        }
        //res.insert(res.end(), splitll.begin(), splitll.end());
        res.insert(res.end(), dl.begin(), dl.end());
        return res;
    }
};
