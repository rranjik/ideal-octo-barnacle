class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for(int i = 0; i<nums.size(); i++){
            //cout<<"nums["<<i<<"] = "<<nums[i]<<endl;
            if(s.empty()) {
                //cout<<"empty!"<<endl;
                s.push(nums[i]);
            }else{
                auto t = s.top();
                s.pop();
                //cout<<"t = "<<t<<endl;
                int a = t;
                int b = nums[i];
                //if(a>b) swap(a, b);
                auto g = gcd(a, b);
                //cout<<"gcd("<<a<<", "<<b<<") = "<<g<<endl;
                if(g==1){
                    s.push(t);
                    s.push(nums[i]);
                }else{
                    auto l = lcm(t, nums[i]);
                    //cout<<"lcm("<<t<<", "<<nums[i]<<") = "<<l<<endl;
                    if(s.empty())
                        s.push(l);
                    else{
                        auto b = false;
                        while(!s.empty()){
                            auto tt = s.top();
                            s.pop();
                            int gc = gcd(tt, l);
                            if(gc==1){
                                b = true;
                                s.push(tt);
                                s.push(l);
                                break;
                            }else{
                                l = lcm(tt, l);
                            }
                        }
                        if(!b)
                            s.push(l);
                    }
                }
            }
        }
        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        //if(found)
        //    return replaceNonCoprimes(res);
        return res;
    }
};
