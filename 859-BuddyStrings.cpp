class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length()!=B.length()) return false;
        if(A==B){
            vector<int> freq(26, 0);
            for(const auto& c :A){
                freq[c-'a']++;
                if(freq[c-'a']>=2) {
                    return true;
                }
            }
            return false;
        }
        int n = 0;
        int one = -1;int two = -1;
        for(int i= 0; i<A.length(); i++){
            if(A[i]!=B[i]) {
                n++;
                if(n<=2){
                    if(one==-1){
                        one = i;
                    }else {
                        two = i;
                    }
                }
            }
        }
        if(n!=2)
            return false;
        if((A[one]==B[two])&&(A[two]==B[one]))
            return true;
         return false;
    }
};
