class Solution {
public:
    //is q a substr of p ?
    bool issubstr(string p, string q){
        int j = 0;
        for(int i = 0; i<p.length()&&j<q.length(); i++){
            if(p[i]==q[j]) j++;
        }
        return j==q.length();
    }
    string findLongestWord(string s, vector<string>& d) {
        //length -> all strings of given length
        map<int, vector<string>, greater<int>> m;
        for(const auto& w : d){
            m[w.length()].push_back(w);
        }
        for(auto& it : m){
            sort(it.second.begin(), it.second.end());
            for(const auto& w : it.second){
                if(issubstr(s, w)) return w;
            }
        }
        return "";
    }
};
