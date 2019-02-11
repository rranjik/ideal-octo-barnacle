#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    vector<pair<int, bool>> arr2;
    for(const auto& a : arr){
        arr2.push_back(pair<int, bool>((int)(a), false));
    }
    //arr2[0].second=true;
    int total_cycles = 0;
    for(int i = 0; i<arr2.size(); i++){
        int elem = i;
        int cycle_size=0;
        if (arr2[elem].first != elem + 1 &&
            !(arr2[arr2[elem].first - 1].second)) {
          while (!arr2[arr2[elem].first - 1].second) {
            cout<<"inside while: \"arr2[elem].first - 1\": "<<arr2[elem].first - 1
            <<"; elem: "<<elem<<" ; \"arr2[arr2[elem].first - 1].first\":"
            <<arr2[arr2[elem].first - 1].first<<endl;
            cycle_size++;
            arr2[arr2[elem].first - 1].second = true;
            elem = arr2[elem].first-1;
            }
            //cycle_size++;
        }
        cout<<"cycle_size: "<<cycle_size<<endl;
        total_cycles += (cycle_size)?(cycle_size-1):(0);
    }
    return total_cycles;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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
