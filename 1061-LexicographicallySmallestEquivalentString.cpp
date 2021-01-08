class Solution {
public:
    void cc(int i, set<char>& c){
        v[i] = true;
        c.insert(static_cast<char>('a'+i));
        for(const auto& j : adjl[i]){
            if(!v[j]){
                cc(j, c);
            }
        }
    }
    vector<int> v = vector<int>(26, false);
    vector<set<int>> adjl = vector<set<int>>(26);
    string smallestEquivalentString(string A, string B, string S) {
        for(int i = 0; i<A.size(); i++){
            adjl[A[i]-'a'].insert(B[i]-'a');
            adjl[B[i]-'a'].insert(A[i]-'a');
        }
        cout<<"here "<<endl;
        unordered_map<char, set<char>> charc;
        for(int i = 0; i<26; i++){
            set<char> s;
            if(!v[i]){
                cc(i, s);
                for(const auto& it : s){
                    charc[it] = s;
                }
            }
        }
        cout<<"here2"<<endl;
        string res;
        for(const auto& c : S){
            res.push_back(*charc[c].begin());
        }
        return res;
    }
};
