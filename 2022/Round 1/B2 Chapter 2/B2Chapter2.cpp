#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;




int main() {

    int T, N, Q;
    double A, B, X1, Y1;
    double p = 1000000007;
    double* X = new double[1000000001];
    double* Y = new double[1000000001];
    int sizeOfGrid = 1000000001;

    freopen("B2Chapter2in.txt", "r", stdin);
    freopen("B2Chapter2out.txt", "w", stdout);
    
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
                X[j] = fmod(X[j] + (A - j)*(A - j), p);
                Y[j] = fmod(Y[j] + (B- j)*(B - j), p);
            }
            /*
            for (int m = 0; m < 10; m++) {
                cout << X[m] << " ";
            }
            cout << endl;
            for (int n = 0; n < 10; n++) {
                cout << Y[n] << " ";
            }
            cout << endl;*/
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
            int newInconvenience = fmod(X[(int)X1]+ Y[(int)Y1], p);
            total = fmod(total + newInconvenience, p);
            //cout << "incon: " << t << " " << X[X1] + Y[Y1] << endl;
        }
        cout << fixed << "Case #" << t << ": " << (int)total << endl;
    }

}