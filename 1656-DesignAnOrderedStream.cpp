class OrderedStream {
public:
    OrderedStream(int n) {
        
    }
    int ptr{1};
    map<int, vector<string>> m;
    vector<string> insert(int id, string value) {
        //cout<<"call to insert "<<id<<endl;
        m[id].push_back(value);
        vector<string> res;
        int l = -1;
        if(m.find(ptr)!=m.end()){
            //cout<<"found "<<ptr<<endl;
            for(const auto& it : m){
                if(it.first<ptr) continue;
                if(l==-1) {
                    //cout<<"inserting... "<<it.first<<endl;
                    l = it.first;
                    res.insert(res.end(), it.second.begin(), it.second.end());
                }
                else if(it.first==l+1){
                    l = it.first;
                    res.insert(res.end(), it.second.begin(), it.second.end());
                }
            }
            //cout<<"setting ptr to "<<id+1<<endl;
            ptr = l+1;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
