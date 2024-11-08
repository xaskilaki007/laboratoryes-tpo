#include <iostream>
#include <vector>

using namespace std;

// Функция для поворота на 90 градусов против часовой стрелки
void rotate90(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> temp = matrix;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[n - j - 1][i] = temp[i][j];
        }
    }
}

// Поворот матрицы на 270 * k градусов
void rotateMatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty() || matrix.size() != matrix[0].size()) {
        cout << "Матрица не является квадратной или пуста." << endl;
        return;
    }

    k = (k % 4 + 4) % 4;  // Приводим к диапазону от 0 до 3

    for (int i = 0; i < k; ++i) {
        rotate90(matrix);
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k;
    cout << "Введите значение k для поворота на 270*k градусов: ";
    cin >> k;

    rotateMatrix(matrix, k);

    cout << "Матрица после поворота:\n";
    printMatrix(matrix);

    return 0;
}
