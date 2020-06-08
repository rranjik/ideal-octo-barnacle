class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> s;
        vector<int> res(t);
        for(int i = 0; i<t.size(); i++){
            //cout<<"t["<<i<<"] = "<<t[i]<<endl;
            if(!s.empty()){
                //cout<<"not empty"<<endl;
                if(s.top().first>=t[i]){
                    //cout<<"top is >= "<<endl;
                    s.push(make_pair(t[i], i));
                }else{
                    while(!s.empty()&&s.top().first<t[i]){
                        //cout<<"top is < "<<s.top().first<<endl;
                        res[s.top().second] = i - s.top().second;
                        s.pop();
                    }
                    //cout<<"pushed "<<endl;
                    s.push(make_pair(t[i], i));
                }
            }else{
                //cout<<"simply pushed "<<endl;
                s.push(make_pair(t[i], i));
            }
        }
        while(!s.empty()){
            //cout<<s.top().first<<" receives a 0"<<endl;
            res[s.top().second] = 0;
            s.pop();
        }
        return res;
    }
};
