class Solution {
public:
    int gn(char r){
        switch(r){
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;
                break;
        }
    }
    int romanToInt(string s) {
        int l = 0;
        int c = s.length();
        int ans = 0;
        while(c>=0){
            if(gn(s[c])>=l){
                ans+=gn(s[c]);
            }
            else{
                ans-=gn(s[c]);
            }
            l = gn(s[c]);
            c--;
        }
        return ans;
    }
};
