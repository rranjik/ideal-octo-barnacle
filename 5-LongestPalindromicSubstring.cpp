class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0||s.length()==1)
            return s;
        vector<vector<bool>> isPal = vector<vector<bool>>(s.length(), vector<bool>(s.length(), false));
        int l = 0;
        int r = 0;
        
        for(int j = 1; j<s.length(); j++){
            for(int i = 0; i<j; i++){
                //cout<<"i = "<<i<<"; j = "<<j<<endl;
                bool isInnerWordPal = isPal[i+1][j-1]||(j-i<=2);
                if(s[i]==s[j]&&isInnerWordPal){
                    isPal[i][j] = true;
                    
                    if(j-i>r-l){
                        l = i;
                        r = j;
                    }
                }
            }
        }
        return s.substr(l, (r-l+1));
    }
};
