#ifndef KLUB_H_INCLUDED
#define KLUB_H_INCLUDED

#include <iostream>
using namespace std;

#define info(p) (p)->info
#define child(p) (p)->child
#define next(p) (p)->next
#define head(p) (p).head
#define nil NULL

struct Tim{
    string nama;
};
struct Anggota{
    string nama;
    string nim;
};

typedef Tim infoTim;
typedef Anggota infoAnggota;

typedef struct elmTim *adrTim;
typedef struct elmAnggota *adrAnggota;

struct elmTim{
    infoTim info;
    adrAnggota child;
    adrTim next;
};

struct elmAnggota{
    infoAnggota info;
    adrAnggota next;
};

struct Klub{
    adrTim head;
};

void createKlub(Klub &K);
adrTim newTim(string nama);
adrAnggota newAnggota(string nama, string nim);
void tambahTim(Klub &K, adrTim a);
void tambahAnggotaTim(Klub &K, string namaTim, string namaAnggota, string nimAnggota);
adrTim cariTim(Klub K, string nama);
void print(Klub K);

adrAnggota cariAnggota(Klub K, string nama, string nim);
void printTim(Klub K);
void printAnggota(Klub K);
void deleteTim(Klub &K, adrTim delTim);
void deleteAnggota(Klub &K, adrAnggota delAnggota);
void timTerbanyak(Klub K);
void timPalingSedikit(Klub K);
void listOpsi();



#endif // KLUB_H_INCLUDED
