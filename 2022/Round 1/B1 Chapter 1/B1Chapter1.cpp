#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int T, N, Q;
int A, B, X1, Y1;
int p = 1000000007;
double X[3001];
double Y[3001];
int sizeOfGrid = 3001;


int main() {
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

        

        //Wells
        cin >> Q;
        double total = 0;
        for (int i = 0; i < Q; i++) {
            cin >> X1 >> Y1;
            total = fmod(total + X[X1] + Y[Y1], p);
            //cout << "incon: " << t << " " << X[X1] + Y[Y1] << endl;
        }
        cout << fixed << "Case #" << t << ": " << (int)total << endl;
    }

}