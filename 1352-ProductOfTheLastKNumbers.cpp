class ProductOfNumbers {
public:
    vector<int> pms;
    int lz = -1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(!pms.size()) {
            //cout<<"added "<<num<<endl;
            pms.push_back(num);
            if(!num) lz = pms.size()-1;
            return;
        }
        if(pms[pms.size()-1]){
            pms.push_back(pms[pms.size()-1]*num);
        }else{
            pms.push_back(num);
        }
        if(!num) lz = pms.size()-1;
        //cout<<"added "<<num<<endl;
        //for(const auto& n : pms){
        //    //cout<<n <<" ";
        //}
        //cout<<endl;
    }
    
    int getProduct(int k) {
        //cout<<"lz = "<<lz<<" getProdct of last "<<k;
        int n = pms.size();
        if(n-k<=lz) {
            //cout<<" past a zero "<<endl;
            return 0;
        }
        int s = n-k;
        //cout<<" start from "<<s;
        if(!s) {
            //cout<<" from begining "<<pms[n-1]<<endl;
            return pms[n-1];
        }
        //else {
            if(pms[s-1]) {
                //cout<<" prev = "<<pms[s-1]<<" non zero p["<<s<<"] = "<<pms[s]<<endl;
                return pms[n-1]/pms[s-1];
            }
                //cout<<" prev = "<<pms[s-1]<<" zero p["<<s<<"] = "<<pms[s]<<endl;
            /*else*/ return pms[n-1];
        //}
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
