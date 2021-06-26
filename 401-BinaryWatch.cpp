class Solution {
public:
    string getTime(bitset<10> t){
        bitset<4> h;
        for(int i = 0; i<4; i++){
            h[i] = t[i];
        }
        bitset<6> m;
        for(int i = 4; i<10;i++){
            m[i-4] = t[i];
        }
        if(h.to_ulong()<=11&&m.to_ulong()<=59){
            string hs = to_string(h.to_ulong());
            string ms = to_string(m.to_ulong());
            if(m.to_ulong()<=9) ms = string(1, '0')+ms;
            return hs+":"+ms;
        }
        return "";
    }
    vector<string> readBinaryWatch(int num) {
        if(!num) return {"0:00"};
        vector<string> res;
        int i = 1;
        while(i){
            bitset<10> b(i);
            if(b.count()==num){
                string s = getTime(b);
                if(s.size()) res.push_back(s);
            }
            i++;
            i%=1024;
        }
        return res;
    }
};
