class Solution {
public:
    int reverse(int x) {
        #include <algorithm>
        string x_as_string = to_string(x);
        if(x_as_string[0]=='-'){
            x_as_string = string(x_as_string.begin()+1, x_as_string.end());
        }
        cout<<"x_as_string: "<<x_as_string<<endl;
        std::reverse(x_as_string.begin(), x_as_string.end());
        cout<<"reversed: "<<x_as_string<<endl;
        long long int reversed_x = stoll(x_as_string);
        cout<<"reversed_x as long long: "<<reversed_x<<endl;
        if((pow(-2, 31)>(reversed_x*-1))||((pow(2,31)-1)<reversed_x))
            return 0;
        if(x<0)
            return reversed_x*-1;
        else return reversed_x;
        
    }
};
