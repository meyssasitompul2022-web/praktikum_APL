#include <iostream>
#include <iomanip>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct Photobox {
    int id;
    string nama;
    string jenisFoto;
};

int main() {

    User user = {"mey", "108"};
    string inputNama, inputNim;
    int percobaan = 0;

    while (percobaan < 3) {

        cout << "===== LOGIN =====\n";
        cout << "Masukkan Nama : ";
        cin >> inputNama;
        cout << "Masukkan NIM  : ";
        cin >> inputNim;

        if (inputNama == user.nama && inputNim == user.nim) {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Login gagal!\n";
            percobaan++;
        }
    }

    if (percobaan == 3) {
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    Photobox data[100];
    int jumlah = 0;
    int pilihan;

    do {

        cout << "\n===== MENU PHOTOBOX MEY =====\n";
        cout << "1. Tambah Data\n";
        cout << "2. Lihat Data\n";
        cout << "3. Ubah Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        if (pilihan == 1) {

            cout << "Input ID           : ";
            cin >> data[jumlah].id;

            cout << "Input Nama Customer: ";
            cin >> data[jumlah].nama;

            cout << "Input Jenis Foto   : ";
            cin >> data[jumlah].jenisFoto;

            jumlah++;

            cout << "Data berhasil ditambahkan.\n";
        }

        else if (pilihan == 2) {

            cout << "\n===== DATA PHOTOBOX =====\n";

            cout << left << setw(10) << "ID"
                 << setw(20) << "Nama"
                 << setw(20) << "Jenis Foto" << endl;

            cout << "--------------------------------------\n";

            for (int i = 0; i < jumlah; i++) {

                cout << left << setw(10) << data[i].id
                     << setw(20) << data[i].nama
                     << setw(20) << data[i].jenisFoto << endl;
            }
        }

        else if (pilihan == 3) {

            int id;
            cout << "Masukkan ID yang ingin diubah: ";
            cin >> id;

            bool ditemukan = false;

            for (int i = 0; i < jumlah; i++) {

                if (data[i].id == id) {

                    cout << "Input nama baru : ";
                    cin >> data[i].nama;

                    cout << "Input jenis foto baru : ";
                    cin >> data[i].jenisFoto;

                    cout << "Data berhasil diubah.\n";

                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Data tidak ditemukan.\n";
            }
        }

        else if (pilihan == 4) {

            int id;
            cout << "Masukkan ID yang ingin dihapus: ";
            cin >> id;

            bool ditemukan = false;

            for (int i = 0; i < jumlah; i++) {

                if (data[i].id == id) {

                    for (int j = i; j < jumlah - 1; j++) {
                        data[j] = data[j + 1];
                    }

                    jumlah--;

                    cout << "Data berhasil dihapus.\n";

                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Data tidak ditemukan.\n";
            }
        }

    } while (pilihan != 5);

    cout << "Terima kasih telah menggunakan sistem.\n";

    return 0;
}