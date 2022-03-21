class TopVotedCandidate {
public:
    //b for ballot
    unordered_map<int, list<int>> b;
    
    //w for where
    unordered_map<int, list<int>::iterator> wh;
    
    //v for votes
    unordered_map<int, int> v;
    
    //w for winner
    map<int, int> w;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        auto winner = 0;
        for(int i = 0; i<persons.size(); i++){
            //cout<<"vote for "<<persons[i]<<" at "<<times[i]<<endl;
            if(wh.find(persons[i])!=wh.end()){
                auto old = v[persons[i]];
                //cout<<"located @"<<old<<endl;
                b[old].erase(wh[persons[i]]);
                v[persons[i]]++;
                auto newv = v[persons[i]];
                b[newv].push_back(persons[i]);
                wh[persons[i]] = prev(b[newv].end());
                //cout<<"now @"<<newv<<endl;
                if(winner<=newv){
                    winner = newv;
                    w[times[i]] = persons[i];
                }
            }else{
                b[1].push_back(persons[i]);
                wh[persons[i]] = prev(b[1].end());
                v[persons[i]] = 1;
                if(winner<=1){
                    winner = 1;
                    w[times[i]] = persons[i];
                }
            }
        }    
    }
    
    int q(int t) {
        auto lb = w.upper_bound(t);
        if(lb==w.begin()){
            return -1;
        }else {
            return (prev(lb))->second;
        }
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
