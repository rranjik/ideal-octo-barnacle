class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string w;
        vector<string> ws;
        for(const auto& c :sentence){
            if(c!=' ')
                w.push_back(c);
            else{
                ws.push_back(w);
                w = "";
            }
        }
        cout<<fixed<<setprecision(2);
        ws.push_back(w);
        string res;
        for(const auto& w : ws){
            if(w[0]=='$'&&w.size()>1){
                bool okay = true;
                for(int i = 1; i<w.size(); i++){
                    auto c = w[i];
                    if(c<'0'||c>'9'){
                        okay = false;
                    }
                }
                if(okay){
                    double l = stol(w.substr(1));
                    l=(l-l*(discount/100.0));
                    stringstream ss;
                    ss<<fixed<<setprecision(2);
                    ss<<"$"<<l;
                    res+=ss.str()+" ";
                }else{
                    cout<<w<<" "<<endl;
                    res+=w+" ";
                }
            } else{
                cout<<w<<" "<<endl;
                res+=w+" ";
            }
        }
        if(!res.empty())
            res.pop_back();
        return res;
    }
};
