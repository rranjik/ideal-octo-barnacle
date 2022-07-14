#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'stockPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY stocksProfit
 *  2. LONG_INTEGER target
 */

int stockPairs(vector<int> stocksProfit, long target) {
    unordered_map<long, int> m;
    for(int i = 0; i<stocksProfit.size(); i++){
        m[stocksProfit[i]] = i;
    }
    set<pair<long, long>> s;
    for(int i = 0; i<stocksProfit.size(); i++){
        int t = target-stocksProfit[i];
        if(m.find(t)!=m.end()&&m[t]!=i){
            auto a = stocksProfit[i];
            auto b = t;
            if(a>b) swap(a, b);
            s.insert({a, b});
            cout<<t<<"+"<<stocksProfit[i]<<"="<<target<<endl;
        }
    }
    return s.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string stocksProfit_count_temp;
    getline(cin, stocksProfit_count_temp);

    int stocksProfit_count = stoi(ltrim(rtrim(stocksProfit_count_temp)));

    vector<int> stocksProfit(stocksProfit_count);

    for (int i = 0; i < stocksProfit_count; i++) {
        string stocksProfit_item_temp;
        getline(cin, stocksProfit_item_temp);

        int stocksProfit_item = stoi(ltrim(rtrim(stocksProfit_item_temp)));

        stocksProfit[i] = stocksProfit_item;
    }

    string target_temp;
    getline(cin, target_temp);

    long target = stol(ltrim(rtrim(target_temp)));

    int result = stockPairs(stocksProfit, target);

    fout << result << "\n";

    fout.close();

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
