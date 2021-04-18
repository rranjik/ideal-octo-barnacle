class Solution {
public:
    using pii = pair<int, int>;
    //keyboard
    unordered_map<char, pii> kbd = {
        {'a', {0, 0}},
        {'b', {0, 1}},
        {'c', {0, 2}},
        {'d', {0, 3}},
        {'e', {0, 4}},
        {'f', {1, 0}},
        {'g', {1, 1}},
        {'h', {1, 2}},
        {'i', {1, 3}},
        {'j', {1, 4}},
        {'k', {2, 0}},
        {'l', {2, 1}},
        {'m', {2, 2}},
        {'n', {2, 3}},
        {'o', {2, 4}},
        {'p', {3, 0}},
        {'q', {3, 1}},
        {'r', {3, 2}},
        {'s', {3, 3}},
        {'t', {3, 4}},
        {'u', {4, 0}},
        {'v', {4, 1}},
        {'w', {4, 2}},
        {'x', {4, 3}},
        {'y', {4, 4}},
        {'z', {5, 0}}
    };
    //f from, t to
    string sp(pii f, pii t){
        cout<<"from ("<<f.first<<", "<<f.second<<") to ("<<t.first<<", "<<t.second<<")"<<endl;
        if(f==t) return "";
        if(f==make_pair(5, 0)){
            return "U"+sp(make_pair(4, 0), t);
        }
        if(t==make_pair(5, 0)){
            return sp(f, make_pair(4, 0))+"D";
        }
        //from from
        string res;
        if(f.first<t.first){
            res+=string(t.first-f.first, 'D');
        }else if(f.first>t.first){
            res+=string(f.first-t.first, 'U');
        }
        
        if(f.second<t.second){
            res+=string(t.second-f.second, 'R');
        }else if(f.second>t.second){
            res+=string(f.second-t.second, 'L');
        }
        
        return res;
    }
    string alphabetBoardPath(string target) {
        string res;
        auto from = make_pair(0, 0);
        for(const auto& c : target){
            res+=sp(from, kbd[c]);
            res+="!";
            from = kbd[c];
        }
        return res;
    }
};
