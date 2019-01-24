#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the bricksGame function below.
 */
// vector<string> split_string(string);
// struct pair_hash {
//   template <class T1, class T2>
//   std::size_t operator()(const std::pair<T1, T2> &p) const {
//     auto h1 = std::hash<T1>{}(p.first);
//     auto h2 = std::hash<T2>{}(p.second);

//     // Mainly for demonstration purposes, i.e. works but is overly simple
//     // In the real world, use sth. like boost.hash_combine
//     return h1 ^ h2;
//   }
// };
//int DPA(int q, const vector<int>& arr);
map<int, long long int> lookup;

// int DPB(int q, const vector<int>& arr){
//     //auto coor = pair<bool, int>(turn, q);
//     if(q>=arr.size())
//         return 0;
//     else if((arr.size()-3)<=q && q<=(arr.size()-1)){
//         int result = 0;
//         while(q<arr.size()){
//             result+=arr[q++];
//         }
//         return result;
//     }
//     else if(lookup.find(q)!=lookup.end())
//         return lookup[q];
//     else{
//         lookup[q] = max(max((DPA(q+1, arr)+(arr[q])), 
//                                (DPA(q+2, arr)+(arr[q]+arr[q+1]))), 
//                                (DPA(q+3, arr)+(arr[q]+arr[q+1]+arr[q+2])));
//         return lookup[q];
//     }
// }

long long int DP(int q, const vector<int>& arr){
    //auto coor = pair<bool, int>(turn, q);
    if(q>=arr.size())
        return 0;
    else if((arr.size()-3)<=q && q<=(arr.size()-1)){
        long long int result = 0;
        while(q<arr.size()){
            result+=arr[q++];
        }
        return result;
    }
    // else if((arr.size()-3)<=q && q<=(arr.size()-1) && !pick){
    //     q++;
    //     int result = 0;
    //     while(q<arr.size()){
    //         result+=arr[q++];
    //     }
    //     return result;
    // }
    else if(lookup.find(q)!=lookup.end())
        return lookup[q];
    else{
        lookup[q] = max(arr[q]+min(DP(q+2, arr), min(DP(q+3, arr), DP(q+4, arr))), 
                    max(arr[q]+arr[q+1]+min(DP(q+3, arr), min(DP(q+4, arr), DP(q+5, arr))),
                    arr[q]+arr[q+1]+arr[q+2]+min(DP(q+4, arr), min(DP(q+5, arr), DP(q+6, arr)))));
        // int pick_one_and_one_over = arr[q] + DP(q+2, arr);
        // int pick_one_and_two_over = arr[q] + DP(q+3, arr);
        // int pick_one_and_three_over = arr[q] + DP(q+4, arr);

        // int pick_two_and_one_over = arr[q]+arr[q+1] + DP(q+3, arr);
        // int pick_two_and_two_over = arr[q]+arr[q+1] + DP(q+4, arr);
        // int pick_two_and_three_over = arr[q]+arr[q+1] + DP(q+5, arr);

        // int pick_three_and_one_over = arr[q]+arr[q+1]+arr[q+2] + DP(q+4, arr);
        // int pick_three_and_two_over = arr[q]+arr[q+1]+arr[q+2] + DP(q+5, arr);
        // int pick_three_and_three_over = arr[q]+arr[q+1]+arr[q+2] + DP(q+6, arr);

        
        // return lookup[q] = max(pick_one_and_one_over, max(pick_one_and_two_over, 
        //                     max(pick_one_and_three_over, max(pick_two_and_one_over,
        //                       max(pick_two_and_two_over, max(pick_two_and_three_over,
        //                         max(pick_three_and_one_over, max(pick_three_and_two_over,                                           pick_three_and_three_over))))))));
        return lookup[q];
    }
}

long long int bricksGame(vector<int> arr) {
    /*
     * Write your code here.
     */
    return DP(0, arr);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        long long int result = bricksGame(arr);
        lookup.clear();
        fout << result << "\n";
    }

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
