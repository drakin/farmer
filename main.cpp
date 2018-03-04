#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int N, M;
    ifstream in("input.txt");
    in >> N;
    in >> M;
    in.get();
    auto **horizontalMaxArea = new unsigned int *[N];
    char currentChar;
    unsigned int i, j;
    for (i = 0; i < N; i++) {
        horizontalMaxArea[i] = new unsigned int[M];
        for (j = 0; j < M; j++) {
            in.get(currentChar);
            horizontalMaxArea[i][j] = currentChar - '0';
        }
        in.get();
    }
    in.close();

    for (i = 0; i < N; i++) {
        for (j = 1; j < M; j++) {
            if (horizontalMaxArea[i][j] != 0) {
                horizontalMaxArea[i][j] = horizontalMaxArea[i][j - 1] + 1;
            }
        }
    }

    unsigned int maxValue = 0;
    unsigned int upLimit = 0;
    unsigned int downLimit = 0;
    unsigned int cellResult = 0;
    unsigned int iMax = 0, jMax = 0;
    unsigned int upLimitMax = 0, downLimitMax = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            upLimit = i;
            downLimit = i;
            if (upLimit != 0) {
                while (horizontalMaxArea[upLimit - 1][j] >= horizontalMaxArea[i][j]) {
                    upLimit--;
                    if (upLimit == 0) break;
                }
            }
            if (downLimit != N - 1) {
                while (horizontalMaxArea[downLimit + 1][j] >= horizontalMaxArea[i][j]) {
                    downLimit++;
                    if (downLimit == N - 1) break;
                }
            }
            cellResult = (downLimit - upLimit + 1) * horizontalMaxArea[i][j];
            if (cellResult > maxValue) {
                iMax = i;
                jMax = j;
                downLimitMax = downLimit;
                upLimitMax = upLimit;
                maxValue = cellResult;
            }
        }
    }
    cout << endl;
    cout << "Max Area: " << maxValue << endl;
    cout << "Coordinates:" << endl;
    cout << upLimitMax << " " << jMax - horizontalMaxArea[iMax][jMax] + 1 << endl;
    cout << upLimitMax << " " << jMax << endl;
    cout << downLimitMax << " " << jMax << endl;
    cout << downLimitMax << " " << jMax - horizontalMaxArea[iMax][jMax] + 1 << endl;

    return 0;
}