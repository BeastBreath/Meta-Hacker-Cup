#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    freopen("A1Chapter1in.txt", "r", stdin);
    freopen("A1Chapter1out.txt", "w", stdout);

    int T; cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, K; cin >> N >> K;
        bool possible = true;

        int* originalCards = new int[N];
        for (int i = 0; i < N; i++) {
            cin >> originalCards[i];
        }
        int firstCard = originalCards[0];
        int matched = -1;
        int* newCards = new int[N];

        for (int i = 0; i < N; i++) {
            cin >> newCards[i];
            if (firstCard == newCards[i]) {
                matched = i;
            }
        }
        for (int i = 0; i < N; i++) {
            if (newCards[(i + matched) % N] != originalCards[i]) {
                possible = false;
                break;
            }
        }
        //cout << matched << endl;
        if (!possible || (K==0 && matched != 0) || (K==1 && matched == 0) || (N==2 && K%2 != matched)){
            cout << "Case #" << t << ": NO"<< endl;
        }
        else {
            cout << "Case #" << t << ": YES"<< endl;
        }
    }

}