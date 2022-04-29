class Solution {
public:
    string match(vector<string> c){
        //cout<<"c size = "<<c.size()<<endl;
        if(c.size()==1) return c[0];
        vector<string> m(c.size()/2);
        //cout<<"m size = "<<m.size()<<endl;
        for(int i = 0, j = c.size()-1; i<(c.size()/2); i++, j--){
            //cout<<"i = "<<i<<" j = "<<j<<endl;
            string mtch;
            mtch +="(";
            mtch +=c[i];
            mtch +=",";
            mtch +=c[j];
            mtch +=")";
            m[i]=mtch;
            //cout<<"m@"<<i<<" = "<<m[i]<<endl;
        }
        return match(m);
    }
    string findContestMatch(int n) {
        vector<string> m(n);
        for(int i = 0; i<n ;i++){
            m[i] = to_string(i+1);
        }
        return match(m);
    }
};
