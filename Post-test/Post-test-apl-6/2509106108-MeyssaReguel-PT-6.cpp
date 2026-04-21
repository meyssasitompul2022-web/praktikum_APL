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
    cout << "6. urut Data\n";
    cout << "7. cari Data\n";
    cout << "8. Keluar\n";
    cout << "Pilih menu : ";
}


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

    for(int i=0;i<jumlah;i++){
        if((data+i)->id==id){
            cout << "Input Nama Baru : ";
            cin >> (data+i)->nama;

            cout << "Input Jenis Foto Baru : ";
            cin >> (data+i)->jenisFoto;

            cout << "Data berhasil diubah.\n";
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

void hapusData(Photobox *data, int *jumlah){
    int id;
    cout << "Masukkan ID yang ingin dihapus : ";
    cin >> id;

    for(int i=0;i<*jumlah;i++){
        if((data+i)->id==id){
            for(int j=i;j<*jumlah-1;j++){
                *(data+j)=*(data+j+1);
            }
            (*jumlah)--;
            cout << "Data berhasil dihapus.\n";
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

int hitungData(int jumlah){
    if(jumlah==0) return 0;
    return 1 + hitungData(jumlah-1);
}

bool login(User *user){
    string inputNama,inputNim;
    int percobaan=0;

    while(percobaan<3){
        cout<<"===== LOGIN =====\n";
        cout<<"Masukkan Nama : "; cin>>inputNama;
        cout<<"Masukkan NIM  : "; cin>>inputNim;

        if(inputNama==user->nama && inputNim==user->nim){
            cout<<"Login berhasil!\n";
            return true;
        }
        cout<<"Login gagal!\n";
        percobaan++;
    }
    return false;
}


void sortNamaDesc(Photobox *data, int jumlah){
    for(int i=0;i<jumlah-1;i++){
        for(int j=0;j<jumlah-i-1;j++){
            if((data+j)->nama < (data+j+1)->nama){
                swap(*(data+j), *(data+j+1));
            }
        }
    }
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
    cout<<"1. Nama\n";
    cout<<"2. ID\n";
    cout<<"3. Jenis Foto\n";
    cout<<"Pilih : ";
    cin>>pilih;

    if(pilih==1) sortNamaDesc(data,jumlah);
    else if(pilih==2) sortIdAsc(data,jumlah);
    else if(pilih==3) sortJenisAsc(data,jumlah);
    else cout<<"Pilihan tidak valid.\n";

    lihatData(data,jumlah);
}


void searchIdJump(Photobox *data, int jumlah){
    int id;
    cout<<"Masukkan ID yang dicari : ";
    cin>>id;

    sortIdAsc(data,jumlah);

    int step = sqrt(jumlah);
    int prev = 0;

    while((data + min(step, jumlah) - 1)->id < id){
        prev = step;
        step += sqrt(jumlah);
        if(prev >= jumlah){
            cout<<"Data tidak ditemukan.\n";
            return;
        }
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

    cout<<"Data tidak ditemukan.\n";
}

void searchNamaBinary(Photobox *data, int jumlah){
    string nama;
    cout<<"Masukkan Nama yang dicari : ";
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

    cout<<"Data tidak ditemukan.\n";
}

void menuSearching(Photobox *data, int jumlah){
    int pilih;
    cout<<"\n===== MENU SEARCHING =====\n";
    cout<<"1. Cari ID\n";
    cout<<"2. Cari Nama\n";
    cout<<"Pilih : ";
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

        if(pilihan==1) tambahData(data,&jumlah);
        else if(pilihan==2) lihatData(data,jumlah);
        else if(pilihan==3) ubahData(data,jumlah);
        else if(pilihan==4) hapusData(data,&jumlah);
        else if(pilihan==5) cout<<"Total: "<<hitungData(jumlah)<<endl;
        else if(pilihan==6) menuSorting(data,jumlah);
        else if(pilihan==7) menuSearching(data,jumlah);

    }while(pilihan!=8);

    cout<<"Terima kasih.\n";
}