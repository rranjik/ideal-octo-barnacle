
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cipher function below.
string cipher(int n, int k, string s) {
    vector<bool> churn(k-1,false);
    reverse(begin(s), end(s));
    string ans;
    auto current = false;
    for(const auto& c : s){             
        // for(const auto& b : churn){
        //         current = (current+b)%2;
        // }
        //std::cout<<"xor is"<<current<<endl;
        if(c=='1'){
            if(current==false){
                ans.append(std::string("1"));
                auto it = churn.begin();
                churn.insert(it, 1);
                auto bn = churn.back();
                current = ((current+bn)%2+1)%2;
                churn.pop_back();
                //churn.set(k-1);
            }
            else{
                ans.append(std::string("0"));
                //ans.push_back("1");
                auto it = churn.begin();
                churn.insert(it, 0);
                auto bn = churn.back();
                current = ((current+bn)%2+0)%2;
                churn.pop_back();
                //churn.set(k-1);
            }
        }
        else{
            //auto current = false;
            if(current==0){
                ans.append(std::string("0"));
                //ans.push_back("1");
                auto it = churn.begin();
                churn.insert(it, 0);
                auto bn = churn.back();
                current = ((current+bn)%2+0)%2;
                churn.pop_back();
                //churn.set(k-1);
            }
            else{
                ans.append(std::string("1"));
                auto it = churn.begin();
                churn.insert(it, 1);
                auto bn = churn.back();
                current = ((current+bn)%2+1)%2;
                churn.pop_back();
                //churn>>=1;
                //churn.set(k-1);
            }
        }
    }
    //cout<<ans<<endl;
    auto temp = string(ans.begin(), ans.begin()+n);
    reverse(temp.begin(), temp.end());
    return temp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = cipher(n, k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
