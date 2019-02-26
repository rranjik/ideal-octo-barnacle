
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     cout<<"stoi(\"07\") is "<<stoi("07")<<endl;
     cout << "stoi(\"07\")+12 is " << stoi("07")+12 << endl;
     cout << "to_string(stoi(\"07\")+12) is " << to_string(stoi("07") + 12) << endl;
     string ans = string(s.begin(), s.end()-2);
     cout << "ans is initially " << ans << endl;
     cout << "string(s.begin(), s.begin() + 1): "
          << string(s.begin(),
                    s.begin() +
                        2)<<endl;
    if (s[s.length() - 2] == 'P' &&
                               (string(s.begin(), s.begin() + 2) != "12")) {
       auto rep =
           to_string(((stoi(string(s.begin(), s.begin() + 2))) + 12));
           cout<<"rep is: "<<rep<<endl;
               ans.replace(
                   0, 2,
                   rep);
     }
     if (s[s.length() - 2] == 'A' && (string(s.begin(), s.begin() + 2) == "12")){
         cout<<"in case 2"<<endl;
       ans.replace(0, 2,
                   "00");
     }
     return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
