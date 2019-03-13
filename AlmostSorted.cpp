
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    //cout<<"inside"<<endl;
    vector<bool> trend(arr.size()-1);
    bool first_decreasing_trend = false;
    bool second_increasing_trend = false;
    int first_decreasing_index = -1;
    int second_decreasing_index = -1;
    int second_increasing_index = -1;
    bool number_of_breakers_exactly_2 = false;
    bool number_of_breakers_more_than_2 = false;
    for(int i = 0; i<arr.size()-1; i++){
        if(arr[i]<arr[i+1]){
            trend[i]=true;
            if(first_decreasing_trend&&second_increasing_index<0){
                second_increasing_index = i;
                second_increasing_trend = true;
            }
        }
        else{
            trend[i]=false;
            if(!first_decreasing_trend){
                first_decreasing_index = i;
                first_decreasing_trend = true;
            }
            else if(second_increasing_trend)
            {
                if(!number_of_breakers_exactly_2){
                    second_decreasing_index = i;
                    number_of_breakers_exactly_2 = true;
                }
                else{
                    number_of_breakers_more_than_2 = true;
                }
            }
        }
    }

    // for(int i = 0; i<trend.size(); i++){
    //     cout<<(trend[i])?" True ":" False ";
    // }
    // cout<<endl;
    // cout<<"first_decreasing_index is "<<first_decreasing_index<<endl;
    // cout<<"second_increasing_index is "<<second_increasing_index<<endl;
    // cout<<"second_decreasing_index is "<<second_decreasing_index<<endl;
    // cout<<"number_of_breakers_more_than_2 "<<number_of_breakers_more_than_2<<endl;
    // cout<<"number_of_breakers_exactly_2 " <<number_of_breakers_exactly_2<<endl;

    if(!first_decreasing_trend)
    {
        cout<<"yes"<<endl;
        return;
    }
    else{
        if(!number_of_breakers_more_than_2)
        {
            auto cpy = arr;
            //cout<<"swapping "<<first_decreasing_index <<" and "<<second_decreasing_index+1<<endl;
            auto temp = cpy[first_decreasing_index];
            cpy[first_decreasing_index] = cpy[second_increasing_index];
            cpy[second_decreasing_index+1] = temp;
            if(std::is_sorted(cpy.begin(), cpy.end())){
                cout<<"yes\nswap "<<first_decreasing_index+1<<" "<<second_decreasing_index +2;
                return;
            }
            // for(const auto& a : cpy){
            //      cout<<a<<" ";
            // }
            reverse(arr.begin()+first_decreasing_index, arr.begin()+second_increasing_index+1);
            // vector<int> toreverse(arr.begin()+first_decreasing_index, arr.begin()+second_increasing_index);
            // reverse(toreverse.begin(), toreverse.end());
            // for(const auto& a : arr){
            //     cout<<a<<" ";
            // }
            //cout<<endl;
            // for(const auto& a : toreverse){
            //     cout<<a<<" ";
            // }
            // cout<<endl;
            if(std::is_sorted(arr.begin(), arr.end())){
                cout<<"yes\nreverse "<<first_decreasing_index+1<<" "<<second_increasing_index+1;
                return;
            }
            else{
                cout<<"no";
                return;
            }
        }
        else{
            cout<<"no";
            return;
        }
    }
    return;
}

int main()
{
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

    almostSorted(arr);

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
