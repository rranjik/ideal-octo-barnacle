class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        
        if(len1<len2) {
            swap(num1, num2);
            swap(len1, len2);
        }
        
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        int i = 0;
        string res;
        int carry = 0;
        while(i<len2){
            cout<<"i = "<<i<<"; num1[i] = "<<num1[i]<<"; num2[i] = "<<num2[i]<<endl;
            cout<<"adding "<<((num1[i]-'0')+(num2[i]-'0')+carry)%10<<endl;
            res+=(to_string(((num1[i]-'0')+(num2[i]-'0')+carry)%10));
            carry = ((num1[i]-'0')+(num2[i]-'0')+carry)/10;
            i++;
        }
        while(i<len1){
            cout<<"i = "<<i<<"; num1[i] = "<<num1[i]<<endl;
            res+=(to_string(((num1[i]-'0')+carry)%10));
            carry = ((num1[i]-'0')+carry)/10;
            i++;
        }
        if(carry) res+=(to_string(carry));
        reverse(begin(res), end(res));
        return res;
    }
};
