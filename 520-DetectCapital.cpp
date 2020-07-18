class Solution {
public:
    bool allUpper(string w){
        for(const auto& c : w){
            if(!isupper(c)) return false;
        }
        return true;
    }
    bool alllower(string w){
        for(const auto& c : w){
            if(!islower(c)) return false;
        }
        return true;
    }
    bool isFirstAlone(string w){
        if(!isupper(w[0])) return false;
        for(int i = 1; i<w.size(); i++){
            if(!islower(w[i])) return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        return allUpper(word)||alllower(word)||isFirstAlone(word);
    }
};
