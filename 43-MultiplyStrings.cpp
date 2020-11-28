class Solution {
public:
    vector<char> digitToChar = {'0', '1', '2', '3', '4',
                               '5', '6', '7', '8', '9'};
    string multiply(string num1, string num2) {
        if(num1.length()<num2.length()) 
            swap(num1, num2);
        vector<string> partials;
        for(int i = num2.length()-1; i>=0; i--){
            int nz = num2.length()-i-1;
            int d1 = num2[i]-'0';
            string partial;
            partial.append(nz, '0');
            int carry = 0;
            for(int j = num1.length()-1; j>=0; j--){
                int d2 = num1[j]-'0';
                partial.push_back(digitToChar[((d1*d2)+carry)%10]);
                carry = (d1*d2+carry)/10;
                //cout<<"carry = "<<carry<<endl;
            }
            //reverse(begin(partial), end(partial));
            if(carry){
                auto cs = to_string(carry);
                for(const auto c : cs){
                    partial.push_back(c);
                }
            }
            cout<<"partial @ i = "<<i<<" is "<<partial<<endl;
            partials.push_back(partial);
        }
        
        
        string res;
        for(const auto& p : partials){
            cout<<p<<endl;
        }
        int w = partials[partials.size()-1].length();
        int i = 0;
        cout<<"w = "<<w<<endl;
        int carry = 0;
        bool sig = false;
        while(i<=w){
            int d = 0;
            bool add = false;
            for(int j  = 0; j<partials.size(); j++){
                if(i<partials[j].size()){
                    add = true;
                    d+=((int)(partials[j][i]-'0'));
                }
            }
            d+=carry;
            if(i<w)
            carry = d/10;
            d = d%10;
            if(add){
                res.push_back(digitToChar[d]);
                if(d) sig = true;
            }
            i++;
        }
        if(carry) {
            res.push_back(digitToChar[carry]);
            sig = true;
        }
        if(!sig) res = "0";
        reverse(begin(res), end(res));
        return res;
    }
};
