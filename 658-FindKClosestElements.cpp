class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(begin(arr), end(arr), x);
        multiset<int> res;
        if(it==arr.end()){
            int i = arr.size()-1;
            while(k){
                res.insert(arr[i]);
                i--;
                k--;
            }
        }else if(it==arr.begin()){
            int i = 0;
            while(k){
                res.insert(arr[i]);
                i++;
                k--;
            }
        }else {
            if(*it>x) it--;
            int i = it -arr.begin();
            int j = (++it) - arr.begin();
            //cout<<"greater i = "<<i<<"; j = "<<j<<end;
            while(k){
                if(i>=0&&j<arr.size()){
                    if(abs(x-arr[i])<abs(x-arr[j])){
                        res.insert(arr[i]);
                        i--;
                    }else if(abs(x-arr[i])>abs(x-arr[j])){
                        res.insert(arr[j]);
                        j++;
                    }else{
                        if(arr[i]<=arr[j]){
                            res.insert(arr[i]);
                            i--;
                        }else{
                            res.insert(arr[j]);
                            j++;
                        }
                    }
                }else if(i>=0){
                    res.insert(arr[i]);
                    i--;
                }else{
                    res.insert(arr[j]);
                    j++;
                }
                k--;
            }
        }
        vector<int> rres;
        for(const auto& n : res)
            rres.push_back(n);
        return rres;
    }
};
