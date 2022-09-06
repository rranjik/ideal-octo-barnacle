class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> r(s.size()+1);
        for(const auto& v : shifts){
            int b = v[2]==0?-1:1;
            r[v[0]]+=b;
            r[v[1]+1]-=b;
            //for(auto& x : r){
            //    cout<<x<<" ";
            //}
            //cout<<endl;
        }
        for(int i = 0; i<r.size()-1; i++){
            r[i+1] += r[i];
        }
        for(auto& x : r){
            //cout<<x<<" ";
            if(x<0){
                x*=-1;
                x%=26;
                x*=-1;
            }else{
                x%=26;
            }
        }
        //cout<<endl;
        //for(auto& x : r){
        //    cout<<x<<" ";
        //}
        //cout<<endl;
        //cout<<"fin"<<endl;
        for(int i = 0; i<r.size()-1; i++){
            auto o = s[i];
            if(r[i]<0){
                for(int j = r[i]; j<0; j++){
                    s[i]--;
                    if(s[i]<'a') s[i] = 'z';
                }
            }else{
                for(int j = r[i]; j>0; j--){
                    s[i]++;
                    if(s[i]>'z') s[i] = 'a';
                }
            }
            //cout<<"i = "<<i<<endl;
            //s[i]+=r[i];
            //if(s[i]>'z'){
            //    s[i] = 'a'+(s[i]-'z'-1);
            //}else if(s[i]<'a'){
            //    s[i] = 'z'-('a'-s[i]-1);
            //}
            //cout<<o<<"->"<<s[i]<<endl;
        }
        return s;
    }
};
