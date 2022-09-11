#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {

    int T, N, Q;
    int A, B, X1, Y1;
    int p = 1000000007;
    int X[3001];
    int Y[3001];
    int sizeOfGrid = 3001;

    freopen("B1Chapter1in.txt", "r", stdin);
    freopen("B1Chapter1out.txt", "w", stdout);
    
    cin >> T;

    for (int t = 1; t <= T; t++) {
        //Reset X and Y
        for (int i = 0; i < sizeOfGrid; i++) {
            X[i] = 0;
            Y[i] = 0;
        }
        cin >> N;
        //Trees
        for (int i = 0; i < N; i++) {
            cin >> A >> B;
            for (int j = 0; j < sizeOfGrid; j++) {
                X[j] = (X[j] + (A - j)*(A - j)) % p;
                Y[j] = (Y[j] + (B- j)*(B - j)) % p;
            }
        }

        for (int i = 0; i < sizeOfGrid; i++) {
            if (X[i] < 0) {
                X[i] += p;
            }
            if (Y[i] < 0) {
                Y[i] += p;
            }
        }

        //Wells
        cin >> Q;
        int total = 0;
        for (int i = 0; i < Q; i++) {
            cin >> X1 >> Y1;
            int newInconvenience = X[X1];
            newInconvenience += Y[Y1];
            newInconvenience %= p;
            total = (total + newInconvenience) % p;
        }
        cout << fixed << "Case #" << t << ": " << (int)total << endl;
    }

}