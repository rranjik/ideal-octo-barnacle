class Solution {
public:
    unordered_set<char> vows = {'a', 'e', 'i', 'o', 'u'};
    int countVowelSubstrings(string w) {
        int j = 0;
        int k = 0;
        int n = w.size();
        int v = 0;
        int res = 0;
        unordered_map<char, int> m = {
            {'a', 0},
            {'e', 0},
            {'i', 0},
            {'o', 0},
            {'u', 0},
        };
        for(int i = 0; i<n; i++){
            cout<<"i = "<<i<<endl;
            if(vows.find(w[i])!=vows.end()){
                m[w[i]]++;
                //first time seeing this vowel
                if(m[w[i]]==1) v++;
                //find first point where we don't have all vowels 
                while(v==5){
                    m[w[k]]--;
                    if(m[w[k]]==0) v--;
                    k++;
                }
                cout<<"k = "<<k<<endl;
                //since we(k) already past decrement by 1
                res+=(k-j);               
            }else{
                m = {
                    {'a', 0},
                    {'e', 0},
                    {'i', 0},
                    {'o', 0},
                    {'u', 0},
                };
                v = 0;
                j = i+1;
                k = i+1;
            }
        }
        return res;
    }
};
