class Solution {
public:
    int sofar{};
    string res;
    void dfs(char l, string c){
        if(c.length()==n){
            sofar++;
            if(sofar==k){
                res = c;
            }
            return;
        }
        vector<char> ch;
        switch(l){
            case 'n':{ch.push_back('a'); ch.push_back('b');ch.push_back('c');}break;
            case 'a':{ch.push_back('b'); ch.push_back('c');}break;
            case 'b':{ch.push_back('a'); ch.push_back('c');}break;
            case 'c':{ch.push_back('a'); ch.push_back('b');}break;
        }
        for(const auto& cc : ch){
            if(sofar<k){
                c.push_back(cc);
                dfs(cc, c);
                c.pop_back();
            }
        }
    }
    int n;
    int k;
    string getHappyString(int n, int k) {
        this->n = n;
        this->k = k;
        string c;
        dfs('n', c);
        return res;
    }
};
