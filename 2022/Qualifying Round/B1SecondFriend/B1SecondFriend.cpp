#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    freopen("B1finalin.txt", "r", stdin);
    freopen("B1finaloutTOSUBMIT.txt", "w", stdout);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int R, C;
        cin >> R >> C;
        bool trees = false;
        bool possible = true;

        

        for (int r = 0; r < R; r++) {
            string rowValues;
            //cin >> rowValues;
            cin >> rowValues;
            for (int c = 0; c < rowValues.length(); c++) {
                cout << ": " << rowValues[c] << endl;
                if (rowValues[c] == '^') {
                    trees = true;
                }
            }
        }

        if ((R == 1 || C == 1) && trees) {
            possible = false;
        }
        if (possible) {
            cout << "Case #" << i << ": Possible" << endl;
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (trees) {
                        cout << "^";
                    }
                    else {
                        cout << ".";
                    }
                }
                cout << endl;
            }
        }
        else {
            cout << "Case #" << i << ": Impossible" << endl;
        }
        

    }

}