class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res{};
        int mini = *min_element(heaters.begin(), heaters.end());
        int maxi = *max_element(heaters.begin(), heaters.end());
        for(const auto& h : houses){
            //cout<<"checking h = "<<h<<endl;
            auto nearest = abs(mini - maxi);
            auto l = lower_bound(heaters.begin(), heaters.end(), h);
            if(l!=heaters.end()){
                if(l!=heaters.begin()){
                    if(*l!=h){
                        l = prev(l);
                        //cout<<"**"<<endl;
                        //cout<<"lb is "<<*l<<endl;
                        nearest= min(nearest, abs(*l - h));
                    }else{
                        //cout<<"lb is "<<*l<<endl;
                        nearest= min(nearest, abs(*l - h));
                    }
                }else{
                    if(*l==h){
                        //cout<<"lb is "<<*l<<endl;
                        nearest= min(nearest, abs(*l - h));
                    }
                }
            }
            auto u = upper_bound(heaters.begin(), heaters.end(), h);
            if(u!=heaters.end()){
                //cout<<"ub is "<<*u<<endl;
                nearest= min(nearest, abs(*u - h));
            }
            if(h <= mini){
                nearest = abs(h - mini);
            }
            if(h>=maxi){
                nearest = abs(h - maxi);
            }
            //cout<<"nearest heater for h = "<<h <<" is "<<nearest<<" away "<<endl;
            res = max(res, nearest);
        }
        return res;
    }
};
