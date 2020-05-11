class Solution {
public:
    unordered_map<int, string> t = {
        {1,"One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"},
        {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, 
        {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, 
        {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"},
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},
        {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"}, 
        {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"}
    };
    string _3digit(int num){
        string res;
        int fn = num/100;
        //lookup hundreds
        if(fn) {res+=t[fn]; res+=" "; res+=t[100]; res+=" ";}
        int ltwo = num%100;
        if(ltwo<20){
            if(ltwo) {res+=t[ltwo]; res+=" ";}
            //lookup
        }else {
            int lastButOne = ltwo/10;
            //lookup + lastdigit
            res+=t[lastButOne*10]; res+=" ";
            int lastdigit = ltwo%10;
            res+=t[lastdigit]; res+=" ";
            //lookup
        }
        return res;
    }
    string numberToWords(int num) {
        if(!num) return "Zero";
        string res;
        int billions = num/1000000000;
        int millions = (num-(billions*1000000000))/1000000;
        int thousands = (num-(billions*1000000000)-(millions*1000000))/1000;
        int lastthree = num%1000;
        if(billions){res+=t[billions]; res+=" "; res+=t[1000000000]; res+=" ";};
        if(millions){res+=_3digit(millions); res+=t[1000000]; res+=" ";};
        if(thousands){res+=_3digit(thousands); res+=t[1000]; res+=" ";};
        if(lastthree){res+=_3digit(lastthree);}
        cout<<_3digit(647)<<endl;
        cout<<_3digit(100)<<endl;
        cout<<_3digit(719)<<endl;
        cout<<_3digit(709)<<endl;
        cout<<_3digit(211)<<endl;
        cout<<_3digit(999)<<endl;
        cout<<_3digit(23)<<endl;
        cout<<_3digit(1)<<endl;
        cout<<_3digit(17)<<endl;
        res = std::regex_replace(res, std::regex("^ +| +$|( ) +"), "$1");
        return res;
    }
};
