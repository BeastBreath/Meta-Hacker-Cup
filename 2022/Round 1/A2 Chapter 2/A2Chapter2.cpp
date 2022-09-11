#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define d 256

int T, N, K;

int searched(char original[], char newOrder[], int q) {
    // M = N, N = N * 2
    int m = N, n = 2 * N;
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++)
    {
        p = (d * p + newOrder[i]) % q;
        t = (d * t + original[i]) % q;
    }
    
    cout << p << " " << t << endl;

    for (i = 0; i <= n - m; i++) {
        cout << t << endl;
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (original[(i + j) % N] != newOrder[j])
                {
                    break;
                }
            }

            if (j == m)
                return i;
        }

        if (i < n - m) {
            t = (d*(t - original[i]*h) + original[(i + m) % N]%q);
            if (t < 0) {
                t += q;
            }
        }

    }
    return -1;
}


int main() {
    freopen("A2Chapter2in.txt", "r", stdin);
    freopen("A2Chapter2out.txt", "w", stdout);
    
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N >> K;
        //int* original = new int[N];
        //int* newStack = new int[N];
        string original;
        string newStack;
        for (int i = 0; i < N; i++) {
            getline(cin, original);
            //cin >> original[i];
        }
        for (int i = 0; i < N; i++) {
            getline(cin, newStack);
            //cin >> newStack[i];
        }
        
        int len = original.length();
        char originalChar[len + 1];
        strcpy(originalChar, original.c_str());

        len = newStack.length();
        char newStackChar[len + 1];
        strcpy(newStackChar, newStack.c_str());

        //int index = search(charOriginal, charNewStack, 97);
        int index = searched(originalChar, newStackChar, 97);
        

        bool possible = (index != -1);

        cout << index << endl;
        if (!possible || (K==0 && index != 0) || (K==1 && index == 0) || (N==2 && K%2 != index)){
            cout << "Case #" << t << ": NO"<< endl;
        }
        else {
            cout << "Case #" << t << ": YES"<< endl;
        }
        
    }
    
}