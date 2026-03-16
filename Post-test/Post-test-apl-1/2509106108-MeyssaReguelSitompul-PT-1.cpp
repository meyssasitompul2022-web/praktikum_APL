#include <iostream>
using namespace std;

int main() {
    string nama, password;
    int percobaan = 0;
    bool login = false;

    while (percobaan < 3) {
        cout << "===== LOGIN =====" << endl;
        cout << "Masukkan Nama Anda : ";
        cin >> nama;
        cout << "Masukkan Password ";
        cin >> password;

        if (nama == "Meyssa" && password == "108") {
            login = true;
            break;
        } else {
            cout << "Login salah!\n";
            percobaan++;
            cout << "Sisa percobaan: " << 3 - percobaan << endl << endl;
        }
    }

    if (!login) {
        cout << "Anda gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    cout << "\nLogin berhasil!\n";

    int pilihan;
    double waktu;

    do {
        cout << "\n===== MENU UTAMA =====" << endl;
        cout << "1. Jam -> Menit dan Detik" << endl;
        cout << "2. Menit -> Jam dan Detik" << endl;
        cout << "3. Detik -> Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Jam: ";
                cin >> waktu;
                cout << "Hasil: " << waktu * 60 << " Menit" << endl;
                cout << "       " << waktu * 3600 << " Detik" << endl;
                break;

            case 2:
                cout << "Masukkan Menit: ";
                cin >> waktu;
                cout << "Hasil: " << waktu / 60 << " Jam" << endl;
                cout << "       " << waktu * 60 << " Detik" << endl;
                break;

            case 3:
                cout << "Masukkan Detik: ";
                cin >> waktu;
                cout << "Hasil: " << waktu / 3600 << " Jam" << endl;
                cout << "       " << waktu / 60 << " Menit" << endl;
                break;

            case 4:
                cout << "Terima kasih, program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}