class Solution {
public:
    int val(char c){
        return c-'a'+1;
    }
    string getSmallestString(int n, int k) {
        string res;
        for(int i = 0; i<n; i++) res.push_back('a');
        if(k==n) return res;
        for(int i = n-1; i>=0; i--){
            //cout<<"here = "<<(n-1-i)*26+26+i<<endl;
            if((n-1-i)*26+26+i<k) res[i] = 'z';
            else{
                for(int j = 0; j<26; j++){
                    if((n-1-i)*26+j+1+i==k) {
                        res[i] = static_cast<char>('a'+j);
                        return res;
                    }
                }
            }
            //cout<<"res = "<<res<<endl;
        }
        return res;
    }
};
