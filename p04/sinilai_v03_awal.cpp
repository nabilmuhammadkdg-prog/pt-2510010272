
// SiNilai v0.3: nilai akhir diubah menjadi huruf mutu dan keterangan kelulusan.
// Dibangun di atas v0.2. Tabel konversi mengikuti peraturan akademik (lihat kontrak kuliah):
//   80-100 A | 75-79,9 B+ | 70-74,9 B | 65-69,9 C+ | 60-64,9 C | 40-59,9 D | 0-39,9 E
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    string nama;
    string npm;
    string huruf_mutu, keterangan;

    double kehadiran = 0;
    double mingguan = 0;
    double uts = 0;
    double uas = 0;
    double nilai_akhir;

    bool lulus = false;

    cout << "=== SiNilai v0.3 ===" << endl;
    cout << "Nama      : ";
    getline(cin, nama);

    cout << "NPM       : ";
    cin >> npm;
    cout << "Kehadiran : ";
    cin >> kehadiran;
    cout << "Mingguan  : ";
    cin >> mingguan;
    cout << "UTS       : ";
    cin >> uts;
    cout << "UAS       : ";
    cin >> uas;

    nilai_akhir = (BOBOT_KEHADIRAN * kehadiran)
                + (BOBOT_MINGGUAN * mingguan)
                + (BOBOT_UTS * uts)
                + (BOBOT_UAS * uas);

    // TODO 1: deklarasikan string huruf_mutu, lalu isi dengan if-else bertingkat sesuai tabel di atas.
    //         Mulai dari batas tertinggi (80) turun ke bawah. Pikirkan kasus batas: 79.9, 80, 59.9, 60.
    if (nilai_akhir >= 80.0) {
        huruf_mutu = "A";
    } else if (nilai_akhir >= 75.0) {
        huruf_mutu = "B+";
    } else if (nilai_akhir >= 70.0) {
        huruf_mutu = "B";
    } else if (nilai_akhir >= 65.0) {
        huruf_mutu = "C+";
    } else if (nilai_akhir >= 60.0) {
        huruf_mutu = "C";
    } else if (nilai_akhir >= 40.0) {
        huruf_mutu = "D";
    } else {
        huruf_mutu = "E";
    }

    // TODO 2: deklarasikan bool lulus. Aturan SiNilai: lulus bila huruf mutu minimal C
    //         (dengan kata lain, nilai_akhir >= 60).
    if (huruf_mutu == "A" || huruf_mutu == "B+" ||
        huruf_mutu == "B" || huruf_mutu == "C+" ||
        huruf_mutu == "C") {
        lulus = true;
    } else {
        lulus = false;
    }

    // TODO 3: deklarasikan string keterangan. Isi dengan switch pada huruf pertama huruf_mutu
    //         (huruf_mutu[0] bertipe char): 'A' Sangat baik, 'B' Baik, 'C' Cukup,
    //         'D' Kurang, 'E' Sangat kurang. Ingat break.
    switch (huruf_mutu[0]) {
        case 'A':
            keterangan = "Sangat baik";
            break;
        case 'B':
            keterangan = "Baik";
            break;
        case 'C':
            keterangan = "Cukup";
            break;
        case 'D':
            keterangan = "Kurang";
            break;
        case 'E':
            keterangan = "Sangat kurang";
            break;
        default:
            keterangan = "-";
            break;
    }

    cout << "\n--- Kartu Nilai Mahasiswa ---" << endl;
    cout << "Nama        : " << nama << endl;
    cout << "NPM         : " << npm << endl;
    cout << fixed << setprecision(2);
    cout << "Nilai akhir : " << nilai_akhir << endl;

    // TODO 4: tampilkan Huruf mutu, Keterangan, dan Status (Lulus / Belum lulus) sejajar.
    cout << "\n";
    cout << left << setw(15) << "Huruf mutu"
         << setw(20) << "Keterangan"
         << "Status" << endl;

    cout << left << setw(15) << huruf_mutu
         << setw(20) << keterangan
         << (lulus ? "Lulus" : "Belum lulus") << endl;

    return 0;
}
