#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    freopen("A1Chapter1in.txt", "r", stdin);
    freopen("A1Chapter1out.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        bool works = true;
        int N, K;
        cin >> N >> K;
        int initial_order[N*2];
        for (int i = 0; i < N; i++) {
            cin >> initial_order[i];
            initial_order[i+N] = initial_order[i];
        }
        int firstNumber, startIndex;
        cin >> firstNumber;
        for (int i = 0; i < N; i++) {
            if (initial_order[i] == firstNumber) {
                startIndex = i;
                break;
            }
        }
        int currentIndex = startIndex;
        for (int i = 1; i < N; i++) {
            currentIndex ++;
            int nextNumber;
            cin >> nextNumber;
            if (initial_order[currentIndex] != nextNumber) {
                works = false;
            }
        }
        if (works && K >= 1 && !(K == 1 && startIndex == 0)) {
            cout << "Case #" << t << ": YES"<< endl;
        }
        else {
            cout << "Case #" << t << ": NO"<< endl;

        }

    }
}