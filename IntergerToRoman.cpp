class Solution {
public:
    string intToRoman(int num) {
        string res;
        int n = num;
        int place = 1;
        while(n){
            int r = n%10;
            n = (n-r)/10;
            cout<<"n = "<<n<<" r = "<<r<<" place = "<<place<< endl;
            switch(place){
                case 1:{
                   switch(r){
                       case 0:
                        break;
                       case 1:
                           res += "I";
                        break;
                       case 2:
                           res += "II";
                        break;
                       case 3:
                           res += "III";
                        break;
                       case 4:
                           res += "IV";
                        break;
                       case 5:
                           res += "V";
                        break;
                       case 6:
                           res += "VI";
                        break;
                       case 7:
                           res += "VII";
                        break;
                       case 8:
                           res += "VIII";
                        break;
                       case 9:
                           res += "IX";
                        break;
                           
                   }
                }
                    break;
                case 2:
                   switch(r){
                       case 0:
                        break;
                       case 1:
                           res.insert(0,"X");
                        break;
                       case 2:
                           res.insert(0, "XX");
                        break;
                       case 3:
                           res.insert(0, "XXX");
                        break;
                       case 4:
                           res.insert(0, "XL");
                        break;
                       case 5:
                           res.insert(0, "L");
                        break;
                       case 6:
                           res.insert(0, "LX");
                        break;
                       case 7:
                           res.insert(0, "LXX");
                        break;
                       case 8:
                           res.insert(0, "LXXX");
                        break;
                       case 9:
                           res.insert(0, "XC");
                        break;
                           
                   }
                    break;
                case 3:
                    switch(r){
                       case 0:
                        break;
                       case 1:
                           res.insert(0, "C");
                        break;
                       case 2:
                           res.insert(0, "CC");
                        break;
                       case 3:
                           res.insert(0, "CCC");
                        break;
                       case 4:
                           res.insert(0, "CD");
                        break;
                       case 5:
                           res.insert(0, "D");
                        break;
                       case 6:
                           res.insert(0, "DC");
                        break;
                       case 7:
                           res.insert(0, "DCC");
                        break;
                       case 8:
                           res.insert(0, "DCCC");
                        break;
                       case 9:
                           res.insert(0, "CM");
                        break;
                           
                   }
                    break;
                case 4:
                    switch(r){
                       case 0:
                        break;
                       case 1:
                           res.insert(0, "M");
                        break;
                       case 2:
                           res.insert(0, "MM");
                        break;
                       case 3:
                           res.insert(0, "MMM");
                        break;
                   }
                    break;
            }
            cout<<"res = "<<res<<endl;
            place++;
        }
        //reverse(res.begin(), res.end());
        return res;
    }
};
