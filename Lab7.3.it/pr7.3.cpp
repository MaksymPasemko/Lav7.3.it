#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int sumOfRowsWithoutNegatives(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        bool hasNegative = false;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }

        if (!hasNegative) {
            for (int j = 0; j < n; j++) {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}

int findMinOfParallelDiagonalSums(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int minSum = 0;

    for (int i = 1; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < n - i; j++) {
            sum += matrix[i + j][j];
        }

        if (i == 1 || sum < minSum) {
            minSum = sum;
        }
    }

    for (int j = 1; j < n; j++) {
        int sum = 0;

        for (int i = 0; i < n - j; i++) {
            sum += matrix[i][j + i];
        }

        if (j == 1 || sum < minSum) {
            minSum = sum;
        }
    }

    return minSum;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix (n): ";
    cin >> n;

    int matrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> matrix[i][j];
        }
    }

    cout << "Your matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sum = sumOfRowsWithoutNegatives(matrix, n);
    cout << "Sum of rows without negatives: " << sum << endl;

    int minDiagonalSum = findMinOfParallelDiagonalSums(matrix, n);
    cout << "Minimum sum of parallel diagonal elements: " << minDiagonalSum << endl;

    return 0;
}
