#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    stack<int> stk;
    int tp;
    int area;
    int max_area = 0;
    int i=0;
    for(; i<h.size();){
        if(stk.empty()||h[stk.top()]<h[i])
            stk.push(i++);
        else{
            tp = stk.top();
            stk.pop();
            area = h[tp]*(stk.empty()?(i):(i-stk.top()-1));
            max_area = max(area, max_area);
        }
    }
    while(!stk.empty()){
        tp = stk.top();
        stk.pop();
        area = h[tp]*(stk.empty()?(i):(i-stk.top()-1));
        max_area = max(area, max_area);
    }
    return max_area;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
