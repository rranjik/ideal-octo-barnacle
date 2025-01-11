class Solution {
public:
    int minGroups(vector<vector<int>>& intvs) {
        sort(intvs.begin(), intvs.end());
        multiset<int> m;
        priority_queue<int, vector<int>, greater<int>>q;
        for(const auto& i : intvs){
            auto b = i[0];
            auto e = i[1];
            //cout<<"["<<b<<","<<e<<"]"<<endl;
            auto j = m.lower_bound(b);
            if(j==m.begin()){
                //cout<<"begin"<<endl;
                m.insert(e);
            }else{
                auto jp = prev(j); 
                //cout<<"prev = "<<*jp<<endl;
                if(*jp==b){
                    //cout<<"making "<<endl;
                    m.insert(e);
                }else{
                    //cout<<"updating "<<endl;
                    m.erase(jp);
                    m.insert(e);
                }
            }
        }
        return m.size();
    }
};
