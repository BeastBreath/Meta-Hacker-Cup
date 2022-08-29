#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//char* inputFile = "test";
//char* outputFile = "test2";

int main() {
    freopen("Atestin.txt", "r", stdin);
    freopen("Atestout.txt", "w", stdout);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int N, K;
        cin >> N >> K;
        
        //cout << "H" << endl;
        
        int styles[101];

        bool possible = true;
        int copiesCount = 0;

        //cout << "A" << endl;

        for (int j = 0; j < 101; j++) {
            //cout << "J: " << j << endl;
            styles[j] = 0;
        }

        //cout << "B" << endl;

        for (int j = 0; j < N; j++) {
            int s;
            cin >> s;
            styles[s]++;
            if (styles[s] > 2) {
                possible = false;
            }
        }
        if (N > K * 2) {
            possible = false;
        }
        if (possible) {
            cout << "Case #" << i << ": YES" << endl;
        }
        else {
            cout << "Case #" << i << ": NO" << endl;
        }

    }


}