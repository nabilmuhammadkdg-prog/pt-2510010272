# P04 Percabangan: if, if-else, switch, dan Operator Logika

Folder kode Pertemuan 4 Pemrograman Terstruktur. Setiap program di sini punya flowchart pasangannya
di modul (Gambar 2 sampai 7); baca gambarnya dulu, baru kodenya.

## Isi

| Berkas | Kegunaan |
|---|---|
| `if_dasar.cpp` | if satu cabang: peringatan bila nilai di bawah 60 |
| `if_else.cpp` | if-else: lulus atau belum lulus |
| `bertingkat.cpp` | if-else bertingkat tiga syarat; coba tukar urutannya |
| `logika.cpp` | `&&`, `||`, `!` dengan bool bernama; syarat ikut UAS |
| `switch_menu.cpp` | switch dengan break dan default; coba hapus break-nya |
| `sinilai_v03_awal.cpp` | Starter SiNilai v0.3: bagian v0.2 sudah jadi, lengkapi huruf mutu, status, keterangan |
| `contoh_masukan.txt` | Masukan uji yang sama dengan pertemuan sebelumnya |
| `.vscode/`, `.gitignore` | Sama dengan pertemuan sebelumnya |

## Kasus uji SiNilai v0.3

| Empat komponen | Nilai akhir | Huruf | Keterangan | Status |
|---|---|---|---|---|
| contoh_masukan.txt | 83.975 | A | Sangat baik | Lulus |
| 80 x4 | 80 | A | Sangat baik | Lulus |
| 79.9 x4 | 79.9 | B+ | Baik | Lulus |
| 60 x4 | 60 | C | Cukup | Lulus |
| 59.9 x4 | 59.9 | D | Kurang | Belum lulus |
| 30 x4 | 30 | E | Sangat kurang | Belum lulus |

## Yang dikumpulkan mahasiswa

Folder `p04` di repository `pt-NPM` berisi `sinilai_v03.cpp` dan  `README.md`. Lihat Modul Pertemuan 4 bagian E.

## Deklarasi AI
saya menggunakan gemini ai dengan promt

// SiNilai v0.3: nilai akhir diubah menjadi huruf mutu dan keterangan kelulusan.
// Dibangun di atas v0.2. Tabel konversi mengikuti peraturan akademik (lihat kontrak kuliah):
//   80-100 A | 75-79,9 B+ | 70-74,9 B | 65-69,9 C+ | 60-64,9 C | 40-59,9 D | 0-39,9 E
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
    cout << "Nama      : ";
    getline(cin, nama);

    cout << "NPM       : ";
    cin >> npm;
    cout << "Kehadiran : ";
    cin >> kehadiran;
    cout << "Mingguan  : ";
    cin >> mingguan;
    cout << "UTS       : ";
    cin >> uts;
    cout << "UAS       : ";
    cin >> uas;

    nilai_akhir = (BOBOT_KEHADIRAN * kehadiran)
                + (BOBOT_MINGGUAN * mingguan)
                + (BOBOT_UTS * uts)
                + (BOBOT_UAS * uas);

    // TODO 1: deklarasikan string huruf_mutu, lalu isi dengan if-else bertingkat sesuai tabel di atas.
    //         Mulai dari batas tertinggi (80) turun ke bawah. Pikirkan kasus batas: 79.9, 80, 59.9, 60.
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
    //         (dengan kata lain, nilai_akhir >= 60).
    if (huruf_mutu == "A" || huruf_mutu == "B+" ||
        huruf_mutu == "B" || huruf_mutu == "C+" ||
        huruf_mutu == "C") {
        lulus = true;
    } else {
        lulus = false;
    }

    // TODO 3: deklarasikan string keterangan. Isi dengan switch pada huruf pertama huruf_mutu
    //         (huruf_mutu[0] bertipe char): 'A' Sangat baik, 'B' Baik, 'C' Cukup,
    //         'D' Kurang, 'E' Sangat kurang. Ingat break.
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
    cout << "Nama        : " << nama << endl;
    cout << "NPM         : " << npm << endl;
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
apakah codingan sesuai todo

respons=
Ya, **kode yang kamu tulis sudah sesuai dan benar** berdasarkan instruksi dari setiap TODO yang ada.

Berikut adalah rincian pengecekan pada setiap bagian TODO:

* **TODO 1 (If-Else Bertingkat untuk Huruf Mutu):**
Sudah tepat. Penggunaan `if-else` dimulai dari batas tertinggi (`>= 80.0`) turun ke bawah secara berurutan. Logika ini sudah benar menangani batasan nilai sesuai tabel konversi.
* **TODO 2 (Status Kelulusan `bool lulus`):**
Sudah tepat. Pengecekan huruf mutu minimal C (`A`, `B+`, `B`, `C+`, `C`) sudah sesuai dengan aturan bahwa nilai minimal lulus adalah C.
* **TODO 3 (Switch-Case untuk Keterangan):**
Sudah tepat. Penggunaan `switch (huruf_mutu[0])` dengan mengambil karakter pertama dari `huruf_mutu` serta menyertakan `break` di setiap `case` sudah benar dan aman.
* **TODO 4 (Tampilan Sejajar):**
Sudah tepat. Penggunaan manipulator `left` dan `setw` dari library `<iomanip>` berhasil merapikan dan menysejajarkan kolom Huruf Mutu, Keterangan, serta Status.

Secara keseluruhan, program **SiNilai v0.3** ini sudah siap untuk dikompilasi dan dijalankan tanpa ada kesalahan logika pada TODO-nya!