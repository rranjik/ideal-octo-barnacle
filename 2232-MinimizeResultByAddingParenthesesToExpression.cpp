class Solution {
public:
    int eval(string s){
        //cout<<"eval("<<s<<") called"<<endl;
        //cout<<"s.find(\')\') = "<<s.find(')')<<endl;
        int mult1 = 1;
        int mult2 = 1;
        int add1 = 0;
        int add2 = 0;
        auto bo = s.substr(0, s.find('('));
        //cout<<"before open = "<<bo<<endl;
        
        mult1 = bo.empty()?1:stoi(bo);
        
        auto ac = s.substr(s.find(')')+1);
        //cout<<"after close = "<<ac<<endl;
        
        mult2 = ac.empty()?1:stoi(ac);
        
        auto otp = s.substr(s.find('(')+1, s.find('+')-1);
        //cout<<"open to plus = "<<otp<<endl;
        
        add1 = otp.empty()?0:stoi(otp);
        
        auto ptc = s.substr(s.find('+')+1, s.find(')')-s.find('+')-1);
        //cout<<"plus to close = "<<ptc<<endl;
        
        add2 = ptc.empty()?0:stoi(ptc);
        
        int res = (add1+add2)*mult1*mult2;
        cout<<"eval("<<s<<") = "<<res<<endl;
        return res;
    }
    string minimizeResult(string e) {
        int p = e.find('+');
        int n = e.size();
        int mres = 1e9;
        string res;
//       eval("(23+43)");
//       eval("1(3+4)3");
        for(int i = 0; i<=p-1; i++){
            for(int j = p+2; j<=n; j++){
                string s = e.substr(0, i)+"("+
                    e.substr(i, j-i)+ ")"+e.substr(j);
                auto v = eval(s);
                if(mres>v){
                    mres = v;
                    res = s;
                }
            }
        }
        return res;
    }
};
