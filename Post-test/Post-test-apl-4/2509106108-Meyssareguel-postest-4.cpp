#include <iostream>
#include <iomanip>
using namespace std;

struct User{
    string nama;
    string nim;
};

struct Photobox{
    int id;
    string nama;
    string jenisFoto;
};

void tampilMenu(){
    cout << "\n===== MENU PHOTOBOX MEY =====\n";
    cout << "1. Tambah Data\n";
    cout << "2. Lihat Data\n";
    cout << "3. Ubah Data\n";
    cout << "4. Hapus Data\n";
    cout << "5. Hitung Total Data (Rekursif)\n";
    cout << "6. Keluar\n";
    cout << "Pilih menu : ";
}

// ✅ Pointer digunakan (*data, *jumlah)
void tambahData(Photobox *data, int *jumlah){

    cout << "Input ID            : ";
    cin >> (data + *jumlah)->id;

    cout << "Input Nama Customer : ";
    cin >> (data + *jumlah)->nama;

    cout << "Input Jenis Foto    : ";
    cin >> (data + *jumlah)->jenisFoto;

    (*jumlah)++;

    cout << "Data berhasil ditambahkan.\n";
}

void lihatData(Photobox *data, int jumlah){

    cout << "\n===== DATA PHOTOBOX =====\n";

    cout << left << setw(10) << "ID"
         << setw(20) << "Nama"
         << setw(20) << "Jenis Foto" << endl;

    cout << "--------------------------------------\n";

    for(int i=0;i<jumlah;i++){
        cout << left << setw(10) << (data+i)->id
             << setw(20) << (data+i)->nama
             << setw(20) << (data+i)->jenisFoto << endl;
    }
}

void ubahData(Photobox *data, int jumlah){

    int id;
    cout << "Masukkan ID yang ingin diubah : ";
    cin >> id;

    bool ditemukan=false;

    for(int i=0;i<jumlah;i++){

        if((data+i)->id==id){

            cout << "Input Nama Baru : ";
            cin >> (data+i)->nama;

            cout << "Input Jenis Foto Baru : ";
            cin >> (data+i)->jenisFoto;

            cout << "Data berhasil diubah.\n";

            ditemukan=true;
            break;
        }
    }

    if(!ditemukan){
        cout << "Data tidak ditemukan.\n";
    }
}

void hapusData(Photobox *data, int *jumlah){

    int id;
    cout << "Masukkan ID yang ingin dihapus : ";
    cin >> id;

    bool ditemukan=false;

    for(int i=0;i<*jumlah;i++){

        if((data+i)->id==id){

            for(int j=i;j<*jumlah-1;j++){
                *(data+j)=*(data+j+1);
            }

            (*jumlah)--;

            cout << "Data berhasil dihapus.\n";

            ditemukan=true;
            break;
        }
    }

    if(!ditemukan){
        cout << "Data tidak ditemukan.\n";
    }
}

int hitungData(int jumlah){

    if(jumlah==0)
        return 0;
    else
        return 1 + hitungData(jumlah-1);
}

// ✅ Pointer pada struct User
bool login(User *user){

    string inputNama,inputNim;
    int percobaan=0;

    while(percobaan<3){

        cout<<"===== LOGIN =====\n";

        cout<<"Masukkan Nama : ";
        cin>>inputNama;

        cout<<"Masukkan NIM  : ";
        cin>>inputNim;

        if(inputNama==user->nama && inputNim==user->nim){

            cout<<"Login berhasil!\n";
            return true;
        }
        else{
            cout<<"Login gagal!\n";
            percobaan++;
        }
    }

    return false;
}

int main(){

    User user={"Mey","108"};

    // ✅ address-of operator (&)
    if(!login(&user)){
        cout<<"Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    Photobox data[100];
    int jumlah=0;
    int pilihan;

    do{

        tampilMenu();
        cin>>pilihan;

        if(pilihan==1)
            tambahData(data, &jumlah); // & digunakan

        else if(pilihan==2)
            lihatData(data, jumlah);

        else if(pilihan==3)
            ubahData(data, jumlah);

        else if(pilihan==4)
            hapusData(data, &jumlah);

        else if(pilihan==5)
            cout<<"Total data (rekursif): "<<hitungData(jumlah)<<endl;

    }while(pilihan!=6);

    cout<<"Terima kasih telah menggunakan sistem.\n";
}