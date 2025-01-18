class ATM {
public:
    vector<long long> d;
    ATM() {
        d = vector<long long>(5);
    }
    int dtoi(int d){
        switch(d){
            case 20:
                return 0;
            case 50:
                return 1;
            case 100:
                return 2;
            case 200:
                return 3;
            case 500:
                return 4;
        }
        return -1;
    }
    int itod(int i){
        switch(i){
            case 0:
                return 20;
            case 1:
                return 50;
            case 2:
                return 100;
            case 3:
                return 200;
            case 4:
                return 500;
        }
        return -1;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i<banknotesCount.size(); i++){
            d[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        //cout<<"amount = "<<amount<<endl;
        auto od = d;
        vector<int> res(5);
        for(int i = 4; (amount)&&(i>=0); i--){
            auto den = itod(i);
            auto denz = d[i];
            //cout<<"have "<<denz<<" "<<den<<" bills"<<endl;
            if(denz>0&&den<=amount) {
                auto redn = min(denz, (long long)amount/den);
                auto reda = redn*den;
                d[i] -= redn;
                amount -= reda;
                res[i] += redn;
            }else if(den>amount){
                continue;
            }
        }
        if(amount) {
            d = od;
            return {-1};
        }
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
