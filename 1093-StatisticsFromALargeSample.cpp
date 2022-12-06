class Solution {
public:
    double mode(vector<int>& count){
        double res = -1;
        int mf{};
        for(int i = 0; i<count.size(); i++){
            if(count[i]>mf){
                mf = count[i];
                res = i;
            }
        }
        return res;
    }
    double median(vector<int>& count){
        int n{};
        for(int i = 0; i<count.size(); i++){
            if(count[i]) n+=count[i];
        }
        if(n%2){
            int s{};
            int h = n/2+1;
            for(int i = 0; i<count.size(); i++){
                s+=count[i];
                if(s>=h) return i;
            }
        }else{
            int s{};
            int h = n/2;
            double first = -1;
            for(int i = 0; i<count.size(); i++){
                if(first!=-1){
                    if(count[i]){
                        return (first+i)/2;
                    }
                }
                if(first==-1){
                    s+=count[i];
                    if(s>=h){
                        if(s==h) first = i;
                        else return i;
                    }
                }
            }
        }
        return -1;
    }
    double mean(vector<int>& count){
        double sum{};
        int n{};
        for(int i = 0; i<count.size(); i++){
            sum+=(count[i]*i);
            n+=count[i];
        }
        if(!n) return -1;
        return sum/=n;   
    }
    int maxi(vector<int>& count){
        for(int i = count.size()-1; i>=0; i--){
            if(count[i])return i;
        }
        return -1;
    }
    int mini(vector<int>& count){
        for(int i = 0; i<count.size(); i++){
            if(count[i])return i;
        }
        return -1;
    }
    vector<double> sampleStats(vector<int>& count) {
        vector<double> res;
        res.push_back(mini(count));
        cout<<"done min"<<endl;
        res.push_back(maxi(count));
        cout<<"done maxi"<<endl;
        res.push_back(mean(count));
        cout<<"done mean"<<endl;
        res.push_back(median(count));
        cout<<"done median"<<endl;
        res.push_back(mode(count));
        cout<<"done mode"<<endl;
        return res;
    }
};
