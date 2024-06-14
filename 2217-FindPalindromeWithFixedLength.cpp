class Solution {
public:
    unordered_map<int, int> pz = {
        {1, 9},
        {2, 9},
        {3, 90},
        {4, 90},
        {5, 900}, {6,900},
        {7, 9000}, {8, 9000},
        {9, 90000}, {10, 90000},
        {11,900000}, {12, 900000},
        {13,9000000}, {14, 9000000},
        {15,90000000}
    };
    vector<int> inner = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> outer = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long long> kthPalindrome(vector<int>& queries, int len) {
        vector<long long> res;
        for(int i = 0; i<queries.size(); i++){
            int q = queries[i];
            if(q>pz[len]) {
                res.push_back(-1);
            }else{
                string s;
                int key = q-1;
                //cout<<"q = "<<q<<" key = "<<key<<endl;
                //if(len%2){
                    int l = (len%2)?len/2+1:len/2;
                    while(l){
                        l--;
                        auto k = key%10;
                        //cout<<"k = "<<k<<endl;
                        key/=10;
                        if(l)
                            s.push_back(static_cast<char>('0'+inner[k]));
                        else
                            s.push_back(static_cast<char>('0'+outer[k]));
                    }
                    reverse(s.begin(), s.end());
                    string rs = s;
                    reverse(s.begin(), s.end());
                    if(len%2){
                        rs += s.substr(1);
                    }else{
                        rs += s;
                    }
                    res.push_back(stoll(rs));
                //}else{
                //    
                //}
            }
        }
        return res;
    }
};
