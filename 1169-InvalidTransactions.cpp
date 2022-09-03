class Solution {
public:
    struct tx{
        int tid;
        string name;
        string city;
        int time;
        int money;
        tx(int _tid, string _name, string _city, int _time, int _money):
        tid(_tid), name(_name), city(_city), time(_time), money(_money){}
        bool operator<(const tx& t) const{
            return time<t.time;
        }
        string print() const{
            string res;
            res+="tid = "+to_string(tid);
            res+=" name = "+name;
            res+=" city = "+city;
            res+=" time = "+to_string(time);
            res+=" money = "+to_string(money);
            return res;
        }
    };
    tx makeTx(string& t, int i){
        string last;
        vector<string> toks;
        for(const auto& c : t){
            if(c!=',')
                last+=c;
            else{
                toks.push_back(last);
                last = "";
            }
        }
        toks.push_back(last);
        return tx{i, toks[0], toks[3], stoi(toks[1]), stoi(toks[2])};
    }
    vector<tx> makeTx(vector<string>& transactions){
        vector<tx> txs;
        for(int i = 0; i<transactions.size(); i++){
            txs.push_back(makeTx(transactions[i], i));
        }
        sort(txs.begin(), txs.end());
        return txs;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        auto txs = makeTx(transactions);
        unordered_map<string, vector<tx>> txm;
        for(const auto& t : txs){
            txm[t.name].push_back(t);
        }
        unordered_set<int> res;
        for(const auto& [p, txs] : txm){
            cout<<"p = "<<p<<endl;
            auto first = true;
            unordered_set<int> iv;
            for(const auto& t : txs){
                cout<<t.print()<<endl;
                if(first){
                    first = false;
                    if(t.money>1000){
                        iv.insert(t.tid);
                        continue;
                    }
                    continue;
                }
                if(t.money>1000){
                    iv.insert(t.tid);
                }
                tx txhour(-1, "", "", t.time-60, 0);
                auto tx60 = vector<tx>(lower_bound(txs.begin(), txs.end(), txhour), txs.end());
                cout<<"tx60 = ";
                for(const auto& tx6 : tx60){
                    cout<<tx6.print()<<"; ";
                    if(tx6.time>t.time) break;
                    if(tx6.city!=t.city){
                        iv.insert(tx6.tid);
                        iv.insert(t.tid);
                    }
                }
                cout<<endl;
            }
            for(const auto& i : iv){
                res.insert(i);
            }
        }
        vector<string> ress;
        for(const auto& i :res){
            ress.push_back(transactions[i]);
        }
        return ress;
    }
};
