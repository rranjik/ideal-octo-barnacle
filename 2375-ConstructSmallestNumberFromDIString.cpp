class Solution {
public:
    string smallestNumber(string pattern) {
        stack<pair<int, int>> s;
        unordered_set<int> u;
        pattern = "I"+pattern;
        s.push({1, 0});
        int n = 2;
        for(int i = 1; i<pattern.size(); i++){
            auto c = pattern[i];
            cout<<"i = "<<i<<" p = "<<c<<endl;
            if(c=='I'){
                s.push({n, i});
                cout<<"pushed"<<endl;
            }else{
                auto [e, j] = s.top(); s.pop();
                cout<<"popped "<<e<<" at "<<j<<endl;
                vector<pair<int, int>> hold;
                hold.push_back({e, j});
                if(!s.empty()){
                    auto nt = s.top(); e = nt.first; j = nt.second;
                    while(pattern[j]=='D'){
                        hold.push_back({e, j});
                        cout<<"popped "<<e<<" at "<<j<<endl;
                        s.pop();
                        if(s.empty()) break;
                        auto tt = s.top(); e = tt.first; j = tt.second;
                    }
                }
                s.push({n, i});
                cout<<"pushed "<<n<<endl;
                reverse(hold.begin(), hold.end());
                for(const auto& h : hold) {
                    cout<<"pushed "<<h.first<<endl;
                    s.push(h);
                }
            }
            n++;
        }
        string res;
        while(!s.empty()){
            res.push_back(static_cast<char>('0'+s.top().first)); s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
