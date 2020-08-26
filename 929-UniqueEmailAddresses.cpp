class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniq;
        for(auto e : emails){
            auto local = e.substr(0, e.find('@', 0));
            auto beforePlus = local.substr(0, e.find('+', 0));
            string beforePlusWithoutDot;
            for(int i = 0; i<beforePlus.length(); i++){
                if(beforePlus[i]!='.'){
                    beforePlusWithoutDot+=beforePlus[i];
                }
            }
            string cleaned = beforePlusWithoutDot+e.substr(e.find('@'), string::npos);
            uniq.insert(cleaned);
        }
        return uniq.size();
    }
};
