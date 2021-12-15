class Solution {
public:
    bool queryString(string S, int N) {
        for(int i = 1; i<=N; i++){
            bitset<32> b = i;
            string bs = b.to_string();
            int j = 0;
            while(bs[j]=='0') j++;
            bs = bs.substr(j);
            cout<<"bs = "<<bs<<endl;
            if(S.find(bs)==string::npos){
                return false;
            }
        }
        return true;
    }
};
