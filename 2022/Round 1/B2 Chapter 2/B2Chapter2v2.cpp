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
        //cout << "p1" << endl;
        cin >> N;
        int *Xtrees = new int[N + 1];
        int *Ytrees = new int[N + 1];
        //Trees
        for (int i = 0; i < N; i++) {
            cin >> Xtrees[i] >> Ytrees[i];
        }
        
        //cout << "p2" << endl;

        //Wells
        cin >> Q;
        int *XWells = new int[Q + 1];
        int *YWells = new int[Q + 1];
        //Trees
        double inconvenience = 0, total = 0;
        for (int i = 0; i < Q; i++) {
            cin >> A >> B;
            inconvenience = fmod(Xtrees[i] - A, p);
            //cout << inconvenience << endl;
            inconvenience = fmod(inconvenience * inconvenience, p);
            total = fmod(total + inconvenience, p);
            //cout << "t" << total << endl;
            
            inconvenience = fmod(Ytrees[i] - B, p);
            //cout << inconvenience << endl;
            inconvenience = fmod(inconvenience * inconvenience, p);
            total = fmod(total + inconvenience, p);

        }
        
        cout << fixed << "Case #" << t << ": " << (int)total << endl;
    }

}