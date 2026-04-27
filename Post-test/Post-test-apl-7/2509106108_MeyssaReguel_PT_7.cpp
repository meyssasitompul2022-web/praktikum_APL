#include <iostream>
#include <iomanip>
#include <cmath>
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
    cout << "5. Hitung Total Data\n";
    cout << "6. Sorting\n";
    cout << "7. Searching\n";
    cout << "8. Keluar\n";
    cout << "Pilih menu : ";
}

void tambahData(Photobox *data, int *jumlah){
    try{
        if(*jumlah >= 100){
            throw "Data penuh!";
        }

        cout << "Input ID            : ";
        cin >> (data + *jumlah)->id;
        if(cin.fail()) throw "ID harus angka!";

        cout << "Input Nama Customer : ";
        cin >> (data + *jumlah)->nama;

        cout << "Input Jenis Foto    : ";
        cin >> (data + *jumlah)->jenisFoto;

        (*jumlah)++;
        cout << "Data berhasil ditambahkan.\n";
    }
    catch(const char* msg){
        cout << "Error: " << msg << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void lihatData(Photobox *data, int jumlah){
    if(jumlah == 0){
        cout << "Data kosong.\n";
        return;
    }

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
    try{
        if(jumlah == 0) throw "Data kosong!";

        int id;
        cout << "Masukkan ID yang ingin diubah : ";
        cin >> id;

        bool ditemukan = false;

        for(int i=0;i<jumlah;i++){
            if((data+i)->id == id){
                cout << "Input Nama Baru : ";
                cin >> (data+i)->nama;

                cout << "Input Jenis Foto Baru : ";
                cin >> (data+i)->jenisFoto;

                cout << "Data berhasil diubah.\n";
                ditemukan = true;
                break;
            }
        }

        if(!ditemukan) throw "ID tidak ditemukan!";
    }
    catch(const char* msg){
        cout << "Error: " << msg << endl;
    }
}

void hapusData(Photobox *data, int *jumlah){
    try{
        if(*jumlah == 0) throw "Data kosong!";

        int id;
        cout << "Masukkan ID yang ingin dihapus : ";
        cin >> id;

        bool ditemukan = false;

        for(int i=0;i<*jumlah;i++){
            if((data+i)->id == id){
                for(int j=i;j<*jumlah-1;j++){
                    *(data+j)=*(data+j+1);
                }
                (*jumlah)--;
                cout << "Data berhasil dihapus.\n";
                ditemukan = true;
                break;
            }
        }

        if(!ditemukan) throw "ID tidak ditemukan!";
    }
    catch(const char* msg){
        cout << "Error: " << msg << endl;
    }
}

int hitungData(int jumlah){
    if(jumlah==0) return 0;
    return 1 + hitungData(jumlah-1);
}

bool login(User *user){
    string inputNama,inputNim;
    int percobaan=0;

    while(percobaan<3){
        try{
            cout<<"===== LOGIN =====\n";
            cout<<"Masukkan Nama : "; cin>>inputNama;
            cout<<"Masukkan NIM  : "; cin>>inputNim;

            if(inputNama==user->nama && inputNim==user->nim){
                cout<<"Login berhasil!\n";
                return true;
            }else{
                throw "Nama atau NIM salah!";
            }
        }
        catch(const char* msg){
            cout<<"Error: "<<msg<<endl;
            percobaan++;
        }
    }
    return false;
}

void sortNamaAsc(Photobox *data, int jumlah){
    for(int i=0;i<jumlah-1;i++){
        for(int j=0;j<jumlah-i-1;j++){
            if((data+j)->nama > (data+j+1)->nama){
                swap(*(data+j), *(data+j+1));
            }
        }
    }
}

void sortIdAsc(Photobox *data, int jumlah){
    for(int i=0;i<jumlah-1;i++){
        int minIndex=i;
        for(int j=i+1;j<jumlah;j++){
            if((data+j)->id < (data+minIndex)->id){
                minIndex=j;
            }
        }
        swap(*(data+i), *(data+minIndex));
    }
}

void sortJenisAsc(Photobox *data, int jumlah){
    for(int i=1;i<jumlah;i++){
        Photobox key = *(data+i);
        int j=i-1;

        while(j>=0 && (data+j)->jenisFoto > key.jenisFoto){
            *(data+j+1)=*(data+j);
            j--;
        }
        *(data+j+1)=key;
    }
}

void menuSorting(Photobox *data, int jumlah){
    int pilih;
    cout<<"\n===== MENU SORTING =====\n";
    cout<<"1. Nama\n2. ID\n3. Jenis Foto\nPilih : ";
    cin>>pilih;

    if(pilih==1) sortNamaAsc(data,jumlah);
    else if(pilih==2) sortIdAsc(data,jumlah);
    else if(pilih==3) sortJenisAsc(data,jumlah);
    else cout<<"Pilihan tidak valid.\n";

    lihatData(data,jumlah);
}

void searchIdJump(Photobox *data, int jumlah){
    try{
        if(jumlah == 0) throw "Data kosong!";

        int id;
        cout<<"Masukkan ID : ";
        cin>>id;

        sortIdAsc(data,jumlah);

        int step = sqrt(jumlah);
        int prev = 0;

        while((data + min(step,jumlah)-1)->id < id){
            prev = step;
            step += sqrt(jumlah);
            if(prev >= jumlah) throw "Data tidak ditemukan!";
        }

        for(int i=prev;i<min(step,jumlah);i++){
            if((data+i)->id == id){
                cout<<"\nData ditemukan:\n";
                cout<<"ID: "<<(data+i)->id<<endl;
                cout<<"Nama: "<<(data+i)->nama<<endl;
                cout<<"Jenis Foto: "<<(data+i)->jenisFoto<<endl;
                return;
            }
        }

        throw "Data tidak ditemukan!";
    }
    catch(const char* msg){
        cout<<"Error: "<<msg<<endl;
    }
}

void searchNamaBinary(Photobox *data, int jumlah){
    try{
        if(jumlah == 0) throw "Data kosong!";

        string nama;
        cout<<"Masukkan Nama : ";
        cin>>nama;

        sortNamaAsc(data,jumlah);

        int left=0,right=jumlah-1;

        while(left<=right){
            int mid=(left+right)/2;

            if((data+mid)->nama == nama){
                cout<<"\nData ditemukan:\n";
                cout<<"ID: "<<(data+mid)->id<<endl;
                cout<<"Nama: "<<(data+mid)->nama<<endl;
                cout<<"Jenis Foto: "<<(data+mid)->jenisFoto<<endl;
                return;
            }
            else if(nama < (data+mid)->nama)
                right=mid-1;
            else
                left=mid+1;
        }

        throw "Data tidak ditemukan!";
    }
    catch(const char* msg){
        cout<<"Error: "<<msg<<endl;
    }
}

void menuSearching(Photobox *data, int jumlah){
    int pilih;
    cout<<"\n===== MENU SEARCHING =====\n";
    cout<<"1. Cari ID\n2. Cari Nama\nPilih : ";
    cin>>pilih;

    if(pilih==1) searchIdJump(data,jumlah);
    else if(pilih==2) searchNamaBinary(data,jumlah);
    else cout<<"Pilihan tidak valid.\n";
}

int main(){
    User user={"Mey","108"};

    if(!login(&user)){
        cout<<"Gagal login.\n";
        return 0;
    }

    Photobox data[100];
    int jumlah=0, pilihan;

    do{
        tampilMenu();
        cin>>pilihan;

        switch(pilihan){
            case 1: tambahData(data,&jumlah); break;
            case 2: lihatData(data,jumlah); break;
            case 3: ubahData(data,jumlah); break;
            case 4: hapusData(data,&jumlah); break;
            case 5: cout<<"Total: "<<hitungData(jumlah)<<endl; break;
            case 6: menuSorting(data,jumlah); break;
            case 7: menuSearching(data,jumlah); break;
            case 8: cout<<"Terima kasih.\n"; break;
            default: cout<<"Menu tidak valid!\n";
        }

    }while(pilihan!=8);
}