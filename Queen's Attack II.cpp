#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    vector<pair<int, int>> obstacle_coordinates;
    for(const auto o : obstacles)
    {
        cout<<"in for(const auto o : obstacles) loop" <<endl;
        auto obstacle_coordinate = make_pair<int, int>((int)o[0], (int)o[1]);
        obstacle_coordinates.push_back(obstacle_coordinate);
    }
    for(auto r = 1; r<=n; r++)
    {
        cout<<"in for(auto r = 1; r<=n; r++) loop" <<endl;
        auto obstacle_coordinate_on_left_extreme = make_pair<int, int>((int)r,(int)0);
        auto obstacle_coordinate_on_right_extreme = make_pair<int, int>((int)r,(int)n+1);
        obstacle_coordinates.push_back(obstacle_coordinate_on_left_extreme);
        obstacle_coordinates.push_back(obstacle_coordinate_on_right_extreme);
    }
    for(auto c = 1; c<=n; c++)
    {
        cout<<"in for(auto c = 1; c<=n; c++) loop" <<endl;
        auto obstacle_coordinate_on_bottom_extreme = make_pair<int, int>((int)0,(int)c);
        auto obstacle_coordinate_on_top_extreme = make_pair<int, int>((int)n+1,(int)c);
        obstacle_coordinates.push_back(obstacle_coordinate_on_bottom_extreme);
        obstacle_coordinates.push_back(obstacle_coordinate_on_top_extreme);
    }
    obstacle_coordinates.push_back(make_pair<int, int>((int)0,(int)0));
    obstacle_coordinates.push_back(make_pair<int, int>((int)0,(int)n+1));
    obstacle_coordinates.push_back(make_pair<int, int>((int)n+1,(int)0));
    obstacle_coordinates.push_back(make_pair<int, int>((int)n+1,(int)n+1));
    auto squares = 0;
    auto hitByObstacleOn1 = false;
    auto r_q1 = r_q;
    auto c_q1 = c_q;
    while(!hitByObstacleOn1)
    {
        cout<<"in hitByObstacleOn1 loop" <<endl;
        if(find(begin(obstacle_coordinates),
                                    end(obstacle_coordinates),
                                    make_pair<int, int>((int)++r_q1, (int)--c_q1))
                                    != obstacle_coordinates.end())
            hitByObstacleOn1= true;
        else
            squares++;
    }
    auto hitByObstacleOn2 = false;
    auto r_q2 = r_q;
    auto c_q2 = c_q;
    while(!hitByObstacleOn2)
    {
        cout<<"in hitByObstacleOn2 loop" <<endl;
        if(find(begin(obstacle_coordinates),
                                    end(obstacle_coordinates),
                                    make_pair<int, int>((int)r_q2, (int)--c_q2))
                                    != obstacle_coordinates.end())
            hitByObstacleOn2= true;
        else
            squares++;
    }
    auto hitByObstacleOn3 = false;
    auto r_q3 = r_q;
    auto c_q3 = c_q;
    while(!hitByObstacleOn3)
    {
        cout<<"in hitByObstacleOn3 loop" <<endl;
        if(find(begin(obstacle_coordinates),
                                    end(obstacle_coordinates),
                                    make_pair<int, int>((int)--r_q3, (int)--c_q3))
                                    != obstacle_coordinates.end())
            hitByObstacleOn3= true;
        else
            squares++;
    }
    auto hitByObstacleOn4 = false;
    auto r_q4 = r_q;
    auto c_q4 = c_q;
    while(!hitByObstacleOn4)
    {
        cout<<"in hitByObstacleOn4 loop" <<endl;
        if(find(begin(obstacle_coordinates),
                                    end(obstacle_coordinates),
                                    make_pair<int, int>((int)--r_q4, (int)c_q4))
                                    != obstacle_coordinates.end())
            hitByObstacleOn4= true;
        else
            squares++;
    }
    auto hitByObstacleOn5 = false;
    auto r_q5 = r_q;
    auto c_q5 = c_q;
    while(!hitByObstacleOn5)
    {
        cout<<"in hitByObstacleOn5 loop" <<endl;
        if(find(begin(obstacle_coordinates),
                                    end(obstacle_coordinates),
                                    make_pair<int, int>((int)--r_q5, (int)++c_q5))
                                    != obstacle_coordinates.end())
            hitByObstacleOn5= true;
        else
            squares++;
    }
    auto hitByObstacleOn6 = false;
    auto r_q6 = r_q;
    auto c_q6 = c_q;
    while(!hitByObstacleOn6)
    {
        cout<<"in hitByObstacleOn6 loop" <<endl;
        if(find(begin(obstacle_coordinates),
                                    end(obstacle_coordinates),
                                    make_pair<int, int>((int)r_q6, (int)++c_q6))
                                    != obstacle_coordinates.end())
            hitByObstacleOn6= true;
        else
            squares++;
    }
    auto hitByObstacleOn7 = false;
    auto r_q7 = r_q;
    auto c_q7 = c_q;
    while(!hitByObstacleOn7)
    {
        cout<<"in hitByObstacleOn7 loop" <<endl;
        if(find(begin(obstacle_coordinates),
                                    end(obstacle_coordinates),
                                    make_pair<int, int>((int)++r_q7, (int)++c_q7))
                                    != obstacle_coordinates.end())
            hitByObstacleOn7= true;
        else
            squares++;
    }
    auto hitByObstacleOn8 = false;
    auto r_q8 = r_q;
    auto c_q8 = c_q;
    while(!hitByObstacleOn8)
    {
        cout<<"in hitByObstacleOn8 loop" <<endl;
        if(find(begin(obstacle_coordinates),
                                    end(obstacle_coordinates),
                                    make_pair<int, int>((int)++r_q8, (int)c_q8))
                                    != obstacle_coordinates.end())
            hitByObstacleOn8= true;
        else
            squares++;
    }
    return squares;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
