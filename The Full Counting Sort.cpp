#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

//vector<vector<pair<bool, string>>> buckets;

// Complete the countSort function below.
void countSort(vector<vector<string>> arr) {
    vector<vector<pair<bool, string>>> buckets(arr.size());
    for(int i=0; i<arr.size()/2;i++){
        buckets[stoi(arr[i][0])].push_back(make_pair<bool, string>(true,string(arr[i][1])));
    }
    for(int i=arr.size()/2;i<arr.size();i++){
        buckets[stoi(arr[i][0])].push_back(make_pair<bool, string>(false,string(arr[i][1])));
    }
    for(int i=0; i<buckets.size(); i++){
        for(auto p:buckets[i]){
            if(p.first==true)
            cout<<"- ";
            else
            cout<<p.second<<" ";
        }
    }
    // for(int i = 0;i<arr.size();i++){
    //     cout<<stoi(arr[i][0])<<"\t"<<arr[i][1]<<endl;
    // }

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
