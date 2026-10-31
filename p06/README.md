# P06 Perulangan Lanjutan dan Penyajian Laporan

Pertemuan keenam memperluas praktik loop melalui perulangan bersarang, `break`, `continue`, debugger, dan pemformatan keluaran dengan `iomanip`. Ikuti flowchart pada modul: loop bersarang memiliki beberapa jalur kembali, sedangkan `break` dan `continue` mengubah alur normal.

## Isi folder

| Berkas                                              | Keterangan                                                                                                      |
| --------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- |
| `bersarang_tabel.cpp`                               | Loop di dalam loop untuk membuat tabel perkalian yang kolomnya dirapikan memakai `setw`                         |
| `break_tebak.cpp`                                   | Mengakhiri permainan lebih cepat saat tebakan tepat, dengan maksimal lima kesempatan                            |
| `continue_remediasi.cpp`                            | Melewati mahasiswa yang sudah memenuhi syarat dan menampilkan yang perlu remediasi                              |
| `rapi_iomanip.cpp`                                  | Contoh `fixed`, `setprecision`, `setw`, `left`, dan `right` untuk merapikan keluaran                            |
| `debug_rerata.cpp`                                  | Latihan menelusuri kesalahan logika dengan debugger                                                             |
| `masukan_debug.txt`                                 | Data untuk `debug_rerata`: 80, 70, 90; rerata acuannya 80                                                       |
| `sinilai_v05_awal.cpp`                              | Starter v0.5 untuk memperluas laporan dengan format kolom, statistik huruf, nilai tertinggi, dan diagram batang |
| `contoh_masukan.txt`                                | Enam mahasiswa sebagai data uji v0.5                                                                            |
| `.vscode/launch.json`                               | Konfigurasi debugger VS Code; tekan F5 ketika berkas C++ aktif                                                  |
| `.vscode/settings.json`, `tasks.json`, `.gitignore` | Pengaturan editor dan build dari pertemuan sebelumnya                                                           |

## Hasil acuan SiNilai v0.5

| Nama          | Komponen nilai    | Nilai akhir (2 desimal) | Huruf | Status      |
| ------------- | ----------------- | ----------------------: | ----- | ----------- |
| Siti Aminah   | 100, 85.5, 78, 80 |                   83.97 | A     | Lulus       |
| Budi Santoso  | 80, 70, 65, 60    |                   67.75 | C+    | Lulus       |
| Rina Wati     | 60, 50, 40, 55    |                   49.50 | D     | Belum lulus |
| Dewi Lestari  | 90, 90, 90, 90    |                   90.00 | A     | Lulus       |
| Eko Prasetyo  | 75, 72, 70, 68    |                   71.00 | B     | Lulus       |
| Fajar Nugroho | 30, 20, 35, 25    |                   25.75 | E     | Belum lulus |

Ringkasan kelas: 6 mahasiswa; 4 lulus dan 2 belum lulus; rata-rata 64.66; nilai tertinggi Dewi Lestari dengan 90.00. Sebaran kategori: A 2, B 1, C 1, D 1, E 1. Nilai B+ digabung ke kelompok B, sedangkan C+ masuk kelompok C.

Catatan tampilan: nilai 83.975 dapat muncul sebagai 83.97, bukan 83.98, karena nilai pecahan tersebut tidak selalu dapat direpresentasikan persis dalam biner dan pembulatan memakai nilai yang tersimpan.

## Menyiapkan debugger

Konfigurasi awal `launch.json` menunjuk ke `C:/msys64/ucrt64/bin/gdb.exe` dan hasil build berekstensi `.exe`. Pada Linux, ubah `miDebuggerPath` menjadi `/usr/bin/gdb` dan hapus akhiran `.exe`; pada macOS, gunakan `lldb` sebagai `MIMode` dan hilangkan `miDebuggerPath`. Panduan tambahan ada di `03_Modul/Panduan_Debugger_VS_Code.docx`.

## Pengumpulan

Simpan tugas dengan nama `sinilai_v05.cpp` pada folder `p06` di repositori `pt-NPM`. Lihat Modul Pertemuan 6 bagian E.

## Deklarasi AI

AI yang digunakan: GitHub Copilot.

Prompt: "Bagaimana cara memakai `setw`, `left`, dan `right` untuk membuat satu baris laporan v0.5 dengan kolom nama, nilai, dan huruf mutu yang sejajar?"

Umpan balik AI: `setw` mengatur lebar untuk keluaran berikutnya, sementara `left` dan `right` menentukan arah perataan. Atur ulang arah perataan sebelum mencetak kolom berikutnya agar setiap bidang memiliki tampilan yang diinginkan. Saya memeriksa hasilnya pada nama yang panjang dan pendek.
