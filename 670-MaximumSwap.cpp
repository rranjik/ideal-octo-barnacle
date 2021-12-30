class Solution {
public:
    vector<int> digitss(int num){
        vector<int> res;
        while(num){
            res.push_back(num%10);
            num/=10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int maximumSwap(int num) {
        auto digits = digitss(num);
        auto sorted = is_sorted(digits.begin(), digits.end(), greater<int>());
        if(sorted) return num;
        int i{};
        for(; i<digits.size()-1; i++){
            if(digits[i]<digits[i+1]) break;
        }
        i++;
        int maxd = digits[i];
        //maxdigit index
        int maxdi = i;
        for(int k = i; k<digits.size(); k++){
            //even if it's equal we want to change the change the index
            if(maxd<=digits[k]){
                maxd = digits[k];
                maxdi = k;
            }
        }
        for(int j = 0; j<maxdi; j++){
            if(digits[j]<digits[maxdi]){
                //swap the first occurance and break
                swap(digits[j], digits[maxdi]);
                break;
            }
        }
        int res{};
        for(int i = 0; i<digits.size(); i++){
            res*=10;
            res+=digits[i];
        }
        return res;
    }
};
