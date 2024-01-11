class Solution {
public:
    long long countVowels(string w) {
        long long res = 0;
        long long n = w.size();
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i<n; i++){
            if(v.find(w[i])!=v.end()){
                res+=((i+1)*(n-i));
            }
        }
        return res;
    }
};
