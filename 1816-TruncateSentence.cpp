class Solution {
public:
    string truncateSentence(string s, int K) {
        string res;
        int last_pos = 0;
        int pos = -1;
        int k = 0;
        while((pos = s.find(' ', last_pos))!=string::npos){
            //cout<<"pos = "<<pos<<endl;
            //cout<<"res = "<<res<<endl;
            k++;
            res = s.substr(0, pos);
            if(k==K) return res;
            last_pos = pos+1;
        }
        return s;
    }
};
