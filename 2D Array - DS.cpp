#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    auto hg1 = arr[0][0] + arr[0][1] + arr[0][2] +
                        arr[1][1] +
               arr[2][0] + arr[2][1] + arr[2][2];
    auto res = hg1;
    auto hg2 = arr[0][1] + arr[0][2] + arr[0][3] +
                        arr[1][2] +
               arr[2][1] + arr[2][2] + arr[2][3];
    res = max(res, hg2);
    auto hg3 = arr[0][2] + arr[0][3] + arr[0][4] +
                        arr[1][3] +
               arr[2][2] + arr[2][3] + arr[2][4];
               res = max(res, hg3);
    auto hg4 = arr[0][3] + arr[0][4] + arr[0][5] +
                        arr[1][4] +
               arr[2][3] + arr[2][4] + arr[2][5];
res = max(res, hg4);
    auto hg5 = arr[1][0] + arr[1][1] + arr[1][2] +
                        arr[2][1] +
               arr[3][0] + arr[3][1] + arr[3][2];
               res = max(res, hg5);
    auto hg6 = arr[1][1] + arr[1][2] + arr[1][3] +
                        arr[2][2] +
               arr[3][1] + arr[3][2] + arr[3][3];
               res = max(res, hg6);
    auto hg7 = arr[1][2] + arr[1][3] + arr[1][4] +
                        arr[2][3] +
               arr[3][2] + arr[3][3] + arr[3][4];
               res = max(res, hg7);
    auto hg8 = arr[1][3] + arr[1][4] + arr[1][5] +
                        arr[2][4] +
               arr[3][3] + arr[3][4] + arr[3][5];
res = max(res, hg8);
    auto hg9 = arr[2][0] + arr[2][1] + arr[2][2] +
                        arr[3][1] +
               arr[4][0] + arr[4][1] + arr[4][2];
               res = max(res, hg9);
    auto hg10 = arr[2][1] + arr[2][2] + arr[2][3] +
                        arr[3][2] +
               arr[4][1] + arr[4][2] + arr[4][3];     
              res = max(res, hg10); 
    auto hg11 = arr[2][2] + arr[2][3] + arr[2][4] +
                        arr[3][3] +
               arr[4][2] + arr[4][3] + arr[4][4];     
               res = max(res, hg11);
    auto hg12 = arr[2][3] + arr[2][4] + arr[2][5] +
                        arr[3][4] +
               arr[4][3] + arr[4][4] + arr[4][5];
res = max(res, hg12);
    auto hg13 = arr[3][0] + arr[3][1] + arr[3][2] +
                        arr[4][1] +
                arr[5][0] + arr[5][1] + arr[5][2];     
                res = max(res, hg13);
    auto hg14 = arr[3][1] + arr[3][2] + arr[3][3] +
                        arr[4][2] +
                arr[5][1] + arr[5][2] + arr[5][3];
                res = max(res, hg14);
    auto hg15 = arr[3][2] + arr[3][3] + arr[3][4] +
                        arr[4][3] +
                arr[5][2] + arr[5][3] + arr[5][4];
                res = max(res, hg15);
    auto hg16 = arr[3][3] + arr[3][4] + arr[3][5] + 
                            arr[4][4] + 
                arr[5][3] + arr[5][4] + arr[5][5];
    res = max(res, hg16);
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
