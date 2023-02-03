class Solution {
public:
    string interpret(string c) {
        string res;
        for(int i = 0; i<c.size();){
            cout<<"i = "<<i<<" c[i] = " <<c[i]<<endl;
            if(c[i]=='G'){
                res.push_back('G');
                i++;
            }else if(c[i]=='('){
                if(c[i+1]==')'){
                    res.push_back('o');
                    i++;
                    i++;
                }else {
                    res.push_back('a');
                    res.push_back('l');
                    i++;
                    i++;
                    i++;
                    i++;
                }
            }
        }
        return res;
    }
};
