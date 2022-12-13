class Solution {
public:
    vector<char> v {'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> vi {
        {'a', 0},
        {'e', 1},
        {'i', 2},
        {'o', 3},
        {'u', 4},
    };
    int res{};
    void dfs(int l, char c){
        //cout<<"left = "<<l<<" last = "<<c<<endl;
        if(!l){
            res++;
            return;
        }
        int i{};
        if(c!='0') i = vi[c];
        for(; i<v.size(); i++){
            dfs(l-1, v[i]);
        }
    }
    int countVowelStrings(int n) {
        dfs(n, '0');
        return res;
    }
};
