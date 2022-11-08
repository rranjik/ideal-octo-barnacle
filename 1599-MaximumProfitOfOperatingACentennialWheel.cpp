class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int w{};
        vector<int> g(4, 0);
        int gp{};
        int resp{};
        int res = -1;
        int b{};
        int r{};
        int i{}; 
        while(i<customers.size()||w){
            auto c = (i<customers.size())?customers[i]:0;
            if(w){
                w = w+c;
                int ab = min(4, w);
                if(w>4){
                    w = (w-4);
                }else{
                    w = 0;
                }
                r++;
                b+=ab;
                if(resp<b*boardingCost-r*runningCost){
                    resp = b*boardingCost-r*runningCost;
                    res = r;
                }
            }
            else{
                if(c>4){
                    w+=(c-4);
                    b+=4;
                    r++;
                    if(resp<b*boardingCost-r*runningCost){
                        resp = b*boardingCost-r*runningCost;
                        res = r;
                    }
                }else if(!c){
                    r++;
                    if(resp<b*boardingCost-r*runningCost){
                        resp = b*boardingCost-r*runningCost;
                        res = r;
                    }
                }else if(c<=4){
                    b+=c;
                    r++;
                    if(resp<b*boardingCost-r*runningCost){
                        resp = b*boardingCost-r*runningCost;
                        res = r;
                    }
                }
            }
            gp+=1;
            gp%=4;
            i++;
            //cout<<"r = "<<r<<" w = "<<w<<" b = "<<b<<" i = "<<i<<" c = "<<c<<" res = "<<res<<endl;
        }
        return res;
    }
};
