#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int T, N, K;

#define d 256

/* 
    The following algorithm is the Rabin-Karp algorithm. This is based on the geeks for geeks implementation of it at this website:
    https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/. However, it is changed for this contest
*/
int search(char originalOrder[], char newOrder[], int q)
{
	int M = strlen(newOrder);
	//int n = strlen(originalOrder);
	int i, j;
	int newOrderHash = 0;
	int originalHash = 0;
	int h = 1;

	for (i = 0; i < M - 1; i++) {
		h = (h * d) % q;
    }


	for (i = 0; i < M; i++) {
		newOrderHash = (d * newOrderHash + newOrder[i]) % q;
		originalHash = (d * originalHash + originalOrder[i]) % q;
	}

	for (i = 0; i <= M + 1; i++) {
		if (newOrderHash == originalHash) {
			for (j = 0; j < M; j++)	{
				if (originalOrder[i+j] != newOrder[j]) {
    				break;
				}
			}
			
			if (j == M) {
                return i;
            }
		}

		if (i < M + 1) {
			originalHash = (d*(originalHash - originalOrder[i]*h) + originalOrder[i+M])%q;

			if (originalHash < 0)
			originalHash = (originalHash + q);
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
        string original;
        string newStack;
        for (int i = 0; i < N; i++) {
            while (original.length() == 0)
                getline(cin, original);
            
        }
        for (int i = 0; i < N; i++) {
            while (newStack.length() == 0)
                getline(cin, newStack);
        }
        
        original = original + " " + original;
        int len = original.length();
        char* originalChar = new char[len + 1];
        strcpy(originalChar, original.c_str());

        len = newStack.length();
        char* newStackChar = new char[len + 1];
        strcpy(newStackChar, newStack.c_str());

        int index = search(originalChar, newStackChar, 97);
        

        bool possible = (index != -1);

        if (!possible || (K==0 && index != 0) || (K==1 && index == 0) || (N==2 && K%2 != index)){
            cout << "Case #" << t << ": NO"<< endl;
        }
        else {
            cout << "Case #" << t << ": YES"<< endl;
        }
        
    }
    
}