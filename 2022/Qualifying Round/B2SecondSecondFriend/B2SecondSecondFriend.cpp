#include <iostream>
#include <cstdio>
#include <string>
#include <queue>


using namespace std;

const int TREE = 0, STONE = 1, OPEN = 2;

int T, R, C;
bool treesFound;
bool trees[3001][3001];
bool rocks[3001][3001];
int originalGrid[3001][3001];
int newGrid[3001][3001];
int neighbors[3001][3001];
queue<pair<int, int>> oneNeighbor;


void printGrid() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (newGrid[r][c] == TREE && treesFound) {
                cout << "^";
            }
            else if (newGrid[r][c] == STONE) {
                cout << "#";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    } 
}

void printNeighbors() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << neighbors[r][c] << " ";
        }
        cout << endl;
    } 
}


void countNeighbors() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (!rocks[r][c]) {
                neighbors[r][c] = 0;
                if (r > 0) {
                    if (!rocks[r-1][c]) {
                        neighbors[r][c] += 1;
                    }
                }
                if (c > 0) {
                    if (!rocks[r][c-1]) {
                        neighbors[r][c] += 1;
                    }
                }
                if (r < R - 1) {
                    if (!rocks[r+1][c]) {
                        neighbors[r][c] += 1;
                    }
                }
                if (c < C - 1) {
                    if (!rocks[r][c+1]) {
                        neighbors[r][c] += 1;
                    }
                }
            }

        }
    }
}

void findLonelyTrees() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (neighbors[r][c] == 1) {
                oneNeighbor.push({r, c});
            }
       }
    }
}

bool removeTrees() {
    while (!oneNeighbor.empty()) {
        int r = oneNeighbor.front().first;
        int c = oneNeighbor.front().second;
        
        //printGrid();
        //printNeighbors();
        oneNeighbor.pop();
        if (trees[r][c]) {
            return false;
        }
        newGrid[r][c] = OPEN;
        if (r > 0) {
            if (newGrid[r-1][c] == TREE) {
                neighbors[r - 1][c] -= 1;
                if (neighbors[r-1][c] <= 1) {
                    oneNeighbor.push({r-1, c});
                }
            }
        }
        if (c > 0) {
            if (newGrid[r][c-1] == TREE) {
                neighbors[r][c-1] -= 1;
                if (neighbors[r][c-1] <= 1) {
                    oneNeighbor.push({r, c-1});
                }
            }
        }
        if (r < R - 1) {
            if (newGrid[r+1][c] == TREE) {
                neighbors[r+1][c] -= 1;
                if (neighbors[r+1][c] <= 1) {
                    oneNeighbor.push({r+1, c});
                }
            }
        }
        if (c < C - 1) {
            if (newGrid[r][c+1] == TREE) {
                neighbors[r][c+1] -= 1;
                if (neighbors[r][c+1] <= 1) {
                    oneNeighbor.push({r, c+1});

                }
            }
        }

    }
    return true;
}

int main() {
    freopen("B2Finalin.txt", "r", stdin);
    freopen("B2FinaloutToSubmit.txt", "w", stdout);

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> R >> C;
        treesFound = false;

        //Gets input
        for (int r = 0; r < R; r++) {
            string rowValues;
            cin >> rowValues;
            //cin.ignore();
            //getline(cin, rowValues);
            //cout << "RV: " << rowValues << endl;
            //printGrid();
            for (int c = 0; c < rowValues.length(); c++) {
                if (rowValues[c] == '^') {
                    //cout << "TREE" << endl;
                    //Tree
                    treesFound = true;
                    trees[r][c] = true;
                    rocks[r][c] = false;
                    originalGrid[r][c] = TREE;
                    newGrid[r][c] = TREE;

                }
                else if (rowValues[c] == '#') {
                    //cout << "STONE" << endl;
                    //Stone
                    trees[r][c] = false;
                    rocks[r][c] = true;
                    originalGrid[r][c] = STONE;
                    newGrid[r][c] = STONE;
                }
                else {
                    //cout << "EMPTY" << endl;
                    //Empty
                    trees[r][c] = false;
                    rocks[r][c] = false;
                    originalGrid[r][c] = OPEN;
                    newGrid[r][c] = TREE;
                }
            }
            //printGrid();
        }

        //printGrid();

        //Counts neighbors
        countNeighbors();

        findLonelyTrees();

        if (removeTrees() || !treesFound) {
            cout << "Case #" << t << ": Possible" << endl;
            printGrid();
        }
        else {
            cout << "Case #" << t << ": Impossible" << endl;
        }

    }

}


/*
    for (int i = 1; i <= T; i++) {
        int R, C;
        cin >> R >> C;
        int grid[R][C];
        int treeCount = 0;
        bool possible = true;

        for (int r = 0; r < R; r++) {
            string rowValues;
            getline(cin, rowValues);
            for (int c = 0; c < rowValues.length(); c++) {
                if (rowValues[c] == '.') {
                    grid[r][c] = 0;
                }
                else {
                    grid[r][c] = 1;
                    treeCount++;
                }
            }
        }
        if ((R == 1 || C == 1) && treeCount > 0) {
            possible = false;
        }
        

    }

}*/