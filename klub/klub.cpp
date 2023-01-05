#include "klub.h"

void createKlub(Klub &K){
    head(K) = nil;
}

adrTim newTim(string nama){
    adrTim new_tim = new elmTim;
    info(new_tim).nama = nama;
    next(new_tim) = nil;
    child(new_tim) = nil;
    return new_tim;
}

adrAnggota newAnggota(string nama, string nim){
    adrAnggota new_a = new elmAnggota;
    info(new_a).nama = nama;
    info(new_a).nim = nim;
    next(new_a) = nil;
    return new_a;
}

void tambahTim(Klub &K, adrTim a){
    if (head(K) == nil){
        head(K) = a; return;
    }
    next(a) = head(K);
    head(K) = a;
}

adrTim cariTim(Klub K, string nama){
    adrTim cari = head(K);
    while (cari != nil && info(cari).nama != nama){
        cari = next(cari);
    }
    return cari;
}

void tambahAnggotaTim(Klub &K, string namaTim, string namaAnggota, string nimAnggota){
    adrTim tim = cariTim(K, namaTim);
    adrAnggota angg = newAnggota(namaAnggota, nimAnggota);
    if (tim == nil){
        cout << "Tim tidak ada!" << endl;
        return;
    }
    if (child(tim) == nil){
        child(tim) = angg;
    } else {
        next(angg) = child(tim);
        child(tim) = angg;
    }
}

void print(Klub K){
    adrTim p = head(K);
    if (p == nil){
        cout << "Gak ada data" << endl;
    } else {
        while (p != nil){
            cout << "Tim     : " << info(p).nama << endl;
            cout << "anggota : ";
            adrAnggota q = child(p);
            while (q != nil){
                cout << info(q).nama << ", ";
                q = next(q);
            }
            cout << endl<< endl;
            p = next(p);
        }
    }
}

adrAnggota cariAnggota(Klub K, string nama, string nim){
    adrTim p = head(K);
    while (p != nil){
        adrAnggota childP = child(p);
        while (childP != nil){
            if (info(childP).nama == nama && info(childP).nim == nim){
                return childP;
            }
            childP = next(childP);
        }
        p = next(p);
    }
    return nil;
}

void printTim(Klub K){
    adrTim p = head(K);
    int i = 1;
    cout << "List nama tim: " << endl;
    while (p != nil){
        cout << i << ". " << info(p).nama << endl;
        i++;
        p = next(p);
    }
}

void printAnggota(Klub K){
    adrTim p = head(K);
    int i = 1;
    cout << "List anggota: " << endl;
    while (p != nil){
        adrAnggota childP = child(p);
        while (childP != nil){
            cout << i << ". " << info(childP).nama;
            cout << " (" << info(childP).nim << ")";
            cout << ", tim: " << info(p).nama << endl;
            childP = next(childP);
            i++;
        }
        p = next(p);
    }
}

void deleteTim(Klub &K, adrTim delTim){
    adrTim prevDel = nil;
    adrTim del = head(K);
    while (del != nil && del != delTim){
        prevDel = del;
        del = next(del);
    }
    if (del == head(K)){
        head(K) = next(del);
        next(del) = nil;
    } else {
        next(prevDel) = next(del);
        next(del) = nil;
    }
}

void deleteAnggota(Klub &K, adrAnggota delAnggota){
    adrTim p = head(K);
    while (p != nil){
        adrAnggota prevDel = nil;
        adrAnggota del = child(p);
        while (del != nil){
            if (del == delAnggota){
                if (del == child(p)){
                    child(p) = next(del);
                    next(del) = nil;
                } else {
                    next(prevDel) = next(del);
                    next(del) = nil;
                }
                return;
            }
            prevDel = del;
            del = next(del);
        }
        p = next(p);
    }
}

void timTerbanyak(Klub K){
    int anggotaTerbanyak = 0;
    adrTim terbanyak = nil;
    adrTim p = head(K);
    while (p != nil){
        int temp = 0;
        adrAnggota q = child(p);
        while (q != nil){
            temp++;
            q = next(q);
        }
        if (temp > anggotaTerbanyak && temp != 0){
            anggotaTerbanyak = temp;
            terbanyak = p;
        }
        p = next(p);
    }
    cout << "Tim dengan anggota terbanyak : " << info(terbanyak).nama;
    cout << " (jumlah anggota: " << anggotaTerbanyak << ") " << endl;
}

void timPalingSedikit(Klub K){
    int anggotaPalingSedikit;
    int lompat = true;
    adrTim palingSedikit = nil;
    adrTim p = head(K);
    while (p != nil){
        int temp = 0;
        adrAnggota q = child(p);
        while (q != nil){
            temp++;
            q = next(q);
        }
        if (lompat){
            anggotaPalingSedikit = temp;
            palingSedikit = p;
            lompat = false;
        } else {
            if (temp < anggotaPalingSedikit && temp != 0){
                anggotaPalingSedikit = temp;
                palingSedikit = p;
            }
            p = next(p);
        }
    }
    cout << "Tim dengan anggota paling sedikit : " << info(palingSedikit).nama;
    cout << " (" << anggotaPalingSedikit << ") " << endl;

}

void listOpsi(){
    cout << "Opsi: " << endl;
    cout << " 1. Tambah tim" << endl;
    cout << " 2. Tambah anggota tim" << endl;
    cout << " 3. Tampilkan list" << endl;
    cout << " 4. Tampilkan list tim dan pemain" << endl;
    cout << " 5. Cari tim" << endl;
    cout << " 6. Cari anggota tim" << endl;
    cout << " 7. Delete tim" << endl;
    cout << " 8. Delete pemain" << endl;
    cout << " 9. Tampilkan tim dengan anggota paling banyak" << endl;
    cout << "10. Tampilkan tim dengan anggota paling sedikit" << endl;
    cout << " 0. Keluar" << endl;
}
