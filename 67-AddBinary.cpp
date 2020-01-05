class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length()-1;
        int j = b.length()-1;
        int c = 0;
        while(i>=0&&j>=0){
            res+=(char)((((a[i]-'0')+(b[j]-'0')+c)%2)+'0');
            c = ((a[i]-'0')+(b[j]-'0')+c)/2;
            i--;
            j--;
        }
        while(i>=0){
            res+=(char)((((a[i]-'0')+c)%2)+'0');
            c = ((a[i]-'0')+(c))/2;
            i--;
        }
        while(j>=0){
            res+=(char)((((b[j]-'0')+c)%2)+'0');
            c = ((b[j]-'0')+(c))/2;
            j--;
        }
        if(c){
            res+='1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
