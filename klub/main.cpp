#include <iostream>
#include "klub.h"

using namespace std;

int main()
{
    Klub K;
    createKlub(K);
    adrAnggota a;
    adrTim t;

//    t = newTim("Tim_Yesika");
//    tambahTim(K, t);
//    t = newTim("Tim_Key");
//    tambahTim(K, t);
//    t = newTim("Biawac");
//    tambahTim(K, t);
//    t = newTim("SlenicNicNicNicNiccc");
//    tambahTim(K, t);
//    t = newTim("Roti_Awan");
//    tambahTim(K, t);
//
//    tambahAnggotaTim(K, "Tim_Yesika", "Yeyes", "123123");
//    tambahAnggotaTim(K, "Tim_Yesika", "Yesika", "321321");
//    tambahAnggotaTim(K, "Tim_Yesika", "Eci", "654654");
//    tambahAnggotaTim(K, "Tim_Key", "Kaisa", "987465");
//    tambahAnggotaTim(K, "Tim_Key", "Zahra", "654987");
//    tambahAnggotaTim(K, "Biawac", "ButterCup", "321987");
//    tambahAnggotaTim(K, "Biawac", "XenS", "987123");
//    tambahAnggotaTim(K, "Biawac", "Hadouken", "741852");
//    tambahAnggotaTim(K, "Biawac", "sonyx99", "963852");
//    tambahAnggotaTim(K, "Biawac", "BimaPL", "846153");
//    tambahAnggotaTim(K, "SlenicNicNicNicNiccc", "Ecino1", "684351");
//    tambahAnggotaTim(K, "SlenicNicNicNicNiccc", "Ecino2", "3516874");
//    tambahAnggotaTim(K, "SlenicNicNicNicNiccc", "Ecino3", "957624");
//    tambahAnggotaTim(K, "Roti_Awan", "Zeks", "741963");
//    tambahAnggotaTim(K, "Roti_Awan", "doang", "963745");


    int opsi;
    string inputString1;
    string inputString2;
    string inputString3;
    char sudah;

    listOpsi();
    cout << "Masukkan opsi: ";
    cin >> opsi;
    while (opsi != 0){

        if (opsi == 1){
            cout << "Masukkan nama tim: ";
            cin >> inputString1;
            t = newTim(inputString1);
            tambahTim(K, t);
        } else if (opsi == 2){
            cout << "Masukkan nama tim        : ";
            cin >> inputString3;
            cout << "Masukkan nama anggota tim: ";
            cin >> inputString1;
            cout << "Masukkan nim anggota tim : ";
            cin >> inputString2;
            tambahAnggotaTim(K, inputString3, inputString1, inputString2);
        } else if (opsi == 3){
            sudah = 'n';
            while (sudah != 'y'){
                cout << endl;
                print(K);
                cout << "Apakah ingin kembali?(y/n) ";
                cin >> sudah;
            }
        } else if (opsi == 4){
            sudah = 'n';
            while (sudah != 'y'){
                cout << endl;
                printTim(K);
                cout << endl;
                printAnggota(K);
                cout << "\nApakah ingin kembali?(y/n) ";
                cin >> sudah;
            }
        } else if (opsi == 5){
            cout << "Masukkan nama tim yang akan dicari: ";
            cin >> inputString1;
            t = cariTim(K, inputString1);
            if (t != nil){
                cout << "Data ditemukan! " << endl;
            } else {
                cout << "Tim tidak ada! " << endl;
            }
        } else if (opsi == 6){
            cout << "Masukkan nama anggota yang akan dicari: ";
            cin >> inputString1;
            cout << "Masukkan nim anggota yang akan dicari : ";
            cin >> inputString2;
            a = cariAnggota(K, inputString1, inputString2);
            if (a != nil){
                cout << "Data ditemukan! " << endl;
            } else {
                cout << "Anggota tidak ada! " << endl;
            }
        } else if (opsi == 7){
            cout << "Masukkan nama tim yang akan dihapus: ";
            cin >> inputString1;
            t = cariTim(K, inputString1);
            deleteTim(K, t);
        } else if (opsi == 8){
            cout << "Masukkan nama pemain yang akan dihapus: ";
            cin >> inputString1;
            cout << "Masukkan nim pemain yang akan dihapus : ";
            cin >> inputString2;
            a = cariAnggota(K, inputString1, inputString2);
            deleteAnggota(K, a);
        } else if (opsi == 9){
            sudah = 'n';
            while (sudah != 'y'){
                cout << endl;
                timTerbanyak(K);
                cout << "\nApakah ingin kembali?(y/n) ";
                cin >> sudah;
            }
        } else if (opsi == 10){
            sudah = 'n';
            while (sudah != 'y'){
                cout << endl;
                timPalingSedikit(K);
                cout << "\nApakah ingin kembali?(y/n) ";
                cin >> sudah;
            }
        }
        cout << endl;
        listOpsi();
        cout << "Masukkan opsi: ";
        cin >> opsi;
    }

    cout << "\nPROGRAM SELESAI\n" << endl;

    return 0;
}
