#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    vector<int> total_balls_in_container;
    for(auto c : container){
        int sum = 0;
        for(auto t : c){
            sum+=t;
        }
        total_balls_in_container.push_back(sum);
    }
    vector<int> type_of_balls;
    for(int c = 0; c<container.size(); c++){
        int sum =0;
        for(int r = 0; r<container.size(); r++){
            sum+=container[r][c];
        }
        type_of_balls.push_back(sum);
    }
    sort(total_balls_in_container.begin(), total_balls_in_container.end());
    sort(type_of_balls.begin(), type_of_balls.end());
    return (total_balls_in_container == type_of_balls) ? "Possible" : "Impossible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
