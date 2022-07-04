class Solution {
public:
    int convertTime(string a, string e) {
        int res = 0;
        if(a == e) return 0;
        auto ah = stoi(a.substr(0, a.find(':')));
        auto eh = stoi(e.substr(0, e.find(':')));
        auto am = stoi(a.substr(a.find(':')+1));
        auto em = stoi(e.substr(e.find(':')+1));
        auto acc = ah*60+am;
        auto ecc = eh*60+em;
        cout<<"acc = "<<acc<<" ecc = "<<ecc<<endl;
        while(acc+60<=ecc){
            acc+=60;
            res++;
        }
        while(acc+15<=ecc){
            acc+=15;
            res++;
        }
        while(acc+5<=ecc){
            acc+=5;
            res++;
        }
        while(acc+1<=ecc){
            acc+=1;
            res++;
        }
        return res;
    }
};
