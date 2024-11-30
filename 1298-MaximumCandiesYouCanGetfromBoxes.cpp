class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        set<int> hBoxes;
        set<int> myKeys;
        for(const auto& i : initialBoxes){
            hBoxes.insert(i);
        }
        vector<bool> taken(status.size());
        int res = 0;
        bool foundKey = true;
        while(!hBoxes.empty()||foundKey==true){
            set<int> newHaveBoxes;
            foundKey = false;
            for(const auto& b : hBoxes){
                if(myKeys.find(b)!=myKeys.end()){
                    //cout<<"found a key for "<<b<<" so opening it"<<endl;
                    status[b] = 1;
                }
                if(!status[b]) {
                    //cout<<"box "<<b<<" is closed. continue"<<endl;
                    newHaveBoxes.insert(b);
                    continue;
                }
                if(status[b]&&!taken[b]){
                    res+=candies[b];
                    //cout<<"eating "<<b<<" = "<<candies[b]<<endl;
                    taken[b] = true;
                }
                for(const auto& k : keys[b]){
                    //cout<<"add a key for "<<k<<endl;
                    myKeys.insert(k);
                    foundKey = true;
                }
                for(const auto& c : containedBoxes[b]){
                    //cout<<"have "<<c<<" now"<<endl;
                    newHaveBoxes.insert(c);
                }
            }
            //cout<<"|newHaveBoxes|="<<newHaveBoxes.size()<<endl;
            swap(hBoxes, newHaveBoxes);
            if(hBoxes==newHaveBoxes) break;
            //cout<<"|hBoxes|="<<hBoxes.size()<<endl;
            //cout<<"foundKey = "<<foundKey<<endl;
        }
        return res;
    }
};
