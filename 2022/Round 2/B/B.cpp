#include <bits/stdc++.h>

using namespace std;

struct client {
    int buyingPrice, buyingDate, sellingPrice, sellingDate;

};

vector<int> totalPrices;
int N, K;
client* clients[1000005];
set<int> dates;
map<int, int> compressedDates;
map<int, vector<int>> buyers;
int modNum = 1000000007;


int min(int a, int b) {
    if (a < b) return a;
    return b;
}

void startSearch() {
    for (int i = 0; i < N; i++) {
        search(clients[i]->sellingDate, 0, clients[i]->sellingPrice);
    }
}

void search(int d, int p, int s) {
    for (int i = 0; i < buyers[d].size(); i++) {
        if (clients[buyers[d][i]]->buyingPrice > s) {
            p += clients[buyers[d][i]]->buyingPrice - s;
            totalPrices.push_back(p);
            search(clients[buyers[d][i]]->sellingDate, p, clients[buyers[d][i]]->sellingPrice);
            p -= clients[buyers[d][i]]->buyingPrice - s;
        }
    }
}

double solve() {
    cin >> N >> K;


    for (int i = 0; i < N; i++) {
        clients[i] = new client();
        cin >> clients[i]->buyingDate >> clients[i]->sellingDate >> clients[i]->buyingPrice >> clients[i]->sellingPrice;
        dates.insert(clients[i]->buyingDate);
        dates.insert(clients[i]->sellingDate);
    }
    int j = 0;
    for(auto& date: dates)
    {
        compressedDates.insert(pair<int, int>(date, j));
        j++;
    }
    

    for (int i = 0; i < N; i++) {
        clients[i]->sellingDate = compressedDates.find(clients[i]->sellingDate)->second;
        clients[i]->buyingDate = compressedDates.find(clients[i]->buyingDate)->second;
        if (buyers.find(clients[i]->buyingDate) == buyers.end()) {
            buyers[clients[i]->buyingDate] = vector<int> {i};
        }
        else {
            buyers[clients[i]->buyingDate].push_back(i);
        }
    }
    startSearch();

    K = min(K, totalPrices.size());
    sort(totalPrices.begin(), totalPrices.end(), greater<int>());


    double sum = 0;
    for (int i = 0; i < K; i++) {
        sum += fmod(totalPrices[i], modNum);
        sum = fmod(sum, modNum);
    }
    return sum;


}

int main() {
    freopen("Bin.txt", "r", stdin);
    freopen("Bout.txt", "w", stdout);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}