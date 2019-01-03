#include <bits/stdc++.h>
#include <functional>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Function returns the minimum number of swaps 
// required to sort the array 
int minSwaps(int arr[], int n, bool order) 
{ 
    // Create an array of pairs where first 
    // element is array element and second element 
    // is position of first element 
    vector<pair<int, int>> arrPos; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos.push_back(std::make_pair<int, int> (int(arr[i]), int(i)));
        //arrPos[i].first = arr[i]; 
        //arrPos[i].second = i; 
    } 
  
    // Sort the array by array element values to 
    // get right position of every element as second 
    // element of pair. 
    if(order)
      sort(std::begin(arrPos), std::end(arrPos), [](const pair<int, int> &a, const pair<int, int> &b){return a.first>b.first;}); 
    else
      sort(std::begin(arrPos), std::end(arrPos), [](const pair<int, int> &a, const pair<int, int> &b){return a.first<b.first;}); 

    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> vis(n, false); 
  
    // Initialize result 
    int ans = 0; 
  
    // Traverse array elements 
    for (int i = 0; i < n; i++) 
    { 
        // already swapped and corrected or 
        // already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // find out the number of  node in 
        // this cycle and add in ans 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
  
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        // Update answer by adding current cycle.  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
  
    // Return result 
    return ans; 
}

// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {
    int input[arr.size()];
    for(auto i = 0; i<arr.size(); i++){
        input[i] = arr[i];
    }
    return std::min(minSwaps(input, arr.size(), false), minSwaps(input, arr.size(), true));
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

    int result = lilysHomework(arr);

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
