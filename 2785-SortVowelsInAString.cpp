class Solution {
public:
    string sortVowels(string s) {
        vector<char> v;
        unordered_set<char> vs = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(const auto& c : s){
            if(vs.find(c)!=vs.end()){
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        string res;
        int i = 0;
        for(const auto& c : s){
            if(vs.find(c)!=vs.end()){
                res.push_back(v[i]);
                i++;
            }else{
                res.push_back(c);
            }
        }
        return res;
    }
};
