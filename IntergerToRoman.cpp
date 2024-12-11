class Solution {
public:
    string intToRoman(int num) {
        vector<int> bases = {1000, 900, 500, 400, 100, 
                                90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> syms = {"M", "CM", "D", "CD", "C", "XC", 
                                "L", "XL", "X", "IX", "V", "IV", "I"};

        int takes = bases.size();
        string res;
        for(int i=0; i<takes; i++){
            int t = bases[i];
            while(num>=t){
                num-=t;
                res+=syms[i];
            }
        }
        return res;
    }
};
