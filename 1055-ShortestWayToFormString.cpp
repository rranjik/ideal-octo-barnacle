class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> present;
        for(const auto& c : source) present.insert(c);
        for(const auto& c : target) if(present.find(c)==present.end()) return -1;
        int j = 0;
        int res = 0;
        while(target.size()){
            int j = 0;
            for(int i = 0; i<source.size(); i++){
                if(source[i]==target[j]) j++;
            }
            target = target.substr(j);
            res++;
        }
        return res;
    }
};
