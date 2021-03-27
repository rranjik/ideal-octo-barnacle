class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int slargest = -1;
        for(int i = 0; i<s.size(); i++){
            if(s[i]>='0'&&s[i]<='9'){
                auto n = s[i]-'0';
                if(largest<n){
                    slargest = largest;
                    largest = n;
                }else if(n!=largest&&slargest<n){
                    slargest = n;
                }
            }
        }
        return slargest;
    }
};
