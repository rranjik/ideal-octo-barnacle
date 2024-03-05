class Solution {
public:
    bool checkValidString(string s) {
        int mini{};
        int maxi{};
        for(const auto& c : s){
            if(c=='('){
                maxi++;
                mini++;
            }else if(c==')'){
                maxi--;
                mini--;
            }else{
                mini--;
                maxi++;
            }
            if(maxi<0) return false;
            mini = max(mini, 0);
        }
        return mini==0;
    }
};
