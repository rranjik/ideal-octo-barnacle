class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> z(numRows);
        int i = 0;
        bool forward = true;
        bool backward = false;
        if(numRows==1){
            return s;
        }
        for(const auto& c : s){
            z[i]+=c;
            if(forward){
               if((i+1)!=numRows){
                   i=i+1;
               } 
               else{
                backward = true;
                forward = false;
                i = numRows - 2;
               }
            }
            else{
               if(i!=0){
                   i = i-1;
               } 
               else{
                   backward=false;
                   forward=true;
                   i = 1;
               }
            }
        }
        string res;
        for(const auto& p : z){
            cout<<p<<endl;
            res+=p;
        }
        return res;
    }
};
