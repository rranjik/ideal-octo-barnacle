class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        vector<int> freq(26, 0);
        int count = 0;
        bool uniq = true;
        for(int i = 0; i<min(K, (int)S.length()); i++){
            if(!freq[S[i]-'a']){
                count++;
                freq[S[i]-'a']++;
            }else{
                uniq = false;
                freq[S[i]-'a']++;
            }
        }
        if(K>S.length()){
            return 0;
        }
        int l = 0; int r = K-1;
        int res = 0;
        while(r<S.length()){
            if(count==K){
                res++;
            }
            r++;
            if(r<S.length()){
                if(!freq[S[r]-'a']){
                    count++;
                    freq[S[r]-'a']++;
                }else {
                    freq[S[r]-'a']++;
                }
                freq[S[l]-'a']--;
                if(!freq[S[l]-'a']){
                    count--;
                }
                l++;
            }
        }
        return res;
    }
};
