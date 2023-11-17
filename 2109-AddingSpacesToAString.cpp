class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        int j = m-1;
        string res;
        for(int i = n-1; i>=0; i--){
            //cout<<"i = "<<i<<" j = "<<j<<endl;
            if(j>=0&&i==spaces[j]){
                res+=s[i];
                res+=' ';
                j--;
            }else{
                res+=s[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
