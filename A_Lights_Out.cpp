#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    vector<vector<int>> bulbs(3, vector<int>(3, 1));
    vector<vector<int>> grid(3, vector<int>(3, 0));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            grid[i][j] = x;
        }
    }

    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int c = grid[i][j];
      
            if (c == 0 || c % 2 == 0)
                continue;
            while (c > 0) {
                bulbs[i][j] = !(bulbs[i][j]);
                for (int k = 0; k < 4; k++) {
                    if(i+delRow[k]>=0 && i+delRow[k]<3 && j+delCol[k]>=0 && j+delCol[k]<3){

                    bulbs[i + delRow[k]][j + delCol[k]] = !(bulbs[i + delRow[k]][j + delCol[k]]);
                    } 
                }
                c--;
            }
        }
        
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << bulbs[i][j];
        }
        cout << endl;
    }
}
