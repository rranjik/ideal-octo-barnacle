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
                mini = max(mini-1, 0);
            }else{
                maxi++;
                mini = max(mini-1, 0);
            }
            if(maxi<0) return false;
        }
        return mini==0;
    }
};
