#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    // Data mahasiswa dan nilai
    string mahasiswa[] = { "Tono", "Ani", "Budi", "Cintia", "Lisa", "Senku", "Mariyadi" };
    double nilai[] = { 92, 65, 74, 80, 80, 70, 78 };
    int n = sizeof(nilai) / sizeof(nilai[0]);

    // Tampilkan tabel data
    cout << "-----------------------------------" << endl;
    cout << "| No.  | Nama       | Nilai       |" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "| " << setw(4) << (i + 1) << " | "
            << setw(10) << mahasiswa[i] << " | "
            << setw(10) << nilai[i] << " |" << endl;
    }
    cout << "-----------------------------------" << endl;

    // Hitung Mean
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nilai[i];
    }
    double mean = sum / n;

    // Hitung Median
    sort(nilai, nilai + n); // Urutkan nilai
    double median;
    if (n % 2 == 0) {
        median = (nilai[n / 2 - 1] + nilai[n / 2]) / 2.0;
    }
    else {
        median = nilai[n / 2];
    }

    // Hitung Standar Deviasi
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += pow(nilai[i] - mean, 2);
    }
    variance /= n;
    double std_dev = sqrt(variance);

    // Output hasil
    cout << "\nHasil Perhitungan:" << endl;
    cout << "Mean: " << fixed << setprecision(2) << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Standard Deviation: " << std_dev << endl;

    return 0;
}
