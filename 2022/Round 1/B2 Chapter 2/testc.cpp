#include <bits/stdc++.h>

using namespace std;

// Simple solution to calculate square without
// using * and pow()
#include <iostream>
using namespace std;

double customSquare(double n)
{
	// handle negative input
	if (n < 0)
		n = -n;

	// Initialize result
	double res = n;

	// Add n to res n-1 times
	for (double i = 1; i < n; i++)
		res += n;

	return res;
}



int main() {
    int X1[5] = {283746263, 987361523, 281936352, 143042069, 1000000000};
    int X2[5] = {0, 123456789, 192837465, 135792468, 703692581};
    int Y1[5] = {475619273, 361738847, 666152443, 482716253, 100000000};
    int Y2[5] = {0, 987654321, 918273645, 864209753, 185296307};



    int p = 1000000007;
    int m = 1, n = 2;
    /*for (int i = m; i <= m; i++) {
        for (int j = n; j <= n; j++) {
            cout << X1[i] << " " << X2[j] << endl;
            sum = (sum + ((X1[i] - X2[j]) * (X1[i] - X2[j])) % p) % p;
            //sum = (sum + ((Y1[i] - Y2[j]) * (Y1[i] - Y2[j])) % p) % p;
            
            sum1 = (sum1 + ((X1[i] - X2[j])^2) % p) % p;
            //sum1 = (sum1 + ((Y1[i] - Y2[j])^2) % p) % p;
        }
    }

    if (sum < 0)
        sum += p;
    if (sum1 < 1)
        sum += p;
    */
    double sum = 0, sum1 = 0, sum2 = 0;
    double a = 192837465 - 918273645;
    sum = a * a; //(192837465 - 918273645) * (192837465 - 918273645);
    //sum1 = a^2; //(192837465 - 918273645)^2;
    sum2 = customSquare(a);
    cout << a << endl;
    cout << sum << " " << sum1 << " " << sum2 << endl;

}