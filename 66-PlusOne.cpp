class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int c = (digits[i] + 1)/10;
        digits[i]=(digits[i]+1)%10;
        i--;
        while(c && i>=0){
            c = (digits[i] + 1)/10;
            digits[i]=(digits[i]+1)%10;
            i--;
        }
        if(i<0&&c){
            vector<int> res = vector<int>(digits.size()+1);
            res[0] = 1;
            for(int i = 0; i<digits.size(); i++)
                res[i+1] = digits[i];
            return res;
        }
        return digits;
    }
};
