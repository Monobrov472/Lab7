#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int countSimilarColumns(vector<vector<int>>& matrix) {
    int M = matrix.size();
    int N = matrix[0].size();

    unordered_set<string> columnSet; // ��� ���������� ��������� �����, �� ������������� ����� ��������

    // ������ �������� ���������� ������� �� columnSet
    for (int i = 0; i < M; ++i) {
        columnSet.insert(to_string(matrix[i][N - 1]));
    }

    int similarColumnsCount = 0;

    // ���������� ����� ��������, ��� ����������
    for (int j = 0; j < N - 1; ++j) {
        bool similar = true;
        for (int i = 0; i < M; ++i) {
            // ������������ �������� �������� � �����
            string columnString = "";
            for (int k = 0; k < M; ++k) {
                columnString += to_string(matrix[k][j]);
            }
            // ���� �������� �� � ���������, ������������ ���� similar � false � �������� � �����
            if (columnSet.find(columnString) == columnSet.end()) {
                similar = false;
                break;
            }
        }
        // ���� �������� ������ �� �������, �������� ��������
        if (similar) {
            ++similarColumnsCount;
        }
    }

    return similarColumnsCount;
}

int main() {
    int M, N;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    cout << "Enter the elements of the matrix with size " << M << " ? " << N << ":" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    int similarColumnsCount = countSimilarColumns(matrix);
    cout << "Number of columns similar to the last column: " << similarColumnsCount << endl;

    return 0;
}
