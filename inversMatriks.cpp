#include <iostream>
#include <iomanip>
using namespace std;

//Menghitung determinan matriks 3x3
double determinant(double mat[3][3]) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
        mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
        mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// Menghitung matriks kofaktor
void cofactorMatrix(double mat[3][3], double cof[3][3]) {
    cof[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);
    cof[0][1] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]);
    cof[0][2] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

    cof[1][0] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]);
    cof[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]);
    cof[1][2] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]);

    cof[2][0] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]);
    cof[2][1] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]);
    cof[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]);
}

// Mentranspos matriks
void transposeMatrix(double mat[3][3], double trans[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            trans[i][j] = mat[j][i];
        }
    }
}

// Menampilkan matriks dengan tabel full border
void displayMatrix(double mat[3][3]) {
    cout << "+---------+---------+---------+" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << setw(7) << fixed << setprecision(2) << mat[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "+---------+---------+---------+" << endl;
    }
    cout << endl;
}

int main() {
    double A[3][3] = {
        {4, 2, 8},
        {2, 1, 5},
        {3, 2, 4}
    };

    cout << "Matriks awal adalah:" << endl;
    displayMatrix(A);

    double det = determinant(A);

    if (det == 0) {
        cout << "Matriks tidak memiliki invers karena determinan = 0" << endl;
        return 0;
    }

    double cof[3][3], adj[3][3], inv[3][3];

    // Hitung matriks kofaktor
    cofactorMatrix(A, cof);

    // Hitung matriks adjoin (transpose dari kofaktor)
    transposeMatrix(cof, adj);

    // Hitung matriks invers
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inv[i][j] = adj[i][j] / det;
        }
    }

    // Matriks invers
    cout << "Matriks invers adalah:" << endl;
    displayMatrix(inv);

    return 0;
}
