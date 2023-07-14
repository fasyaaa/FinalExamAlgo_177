#include <iostream>
#include <string>

using namespace std;

class Node {
public:
//isi disini
    string nama;
    int jumlah;
    string tipe;
    Node* next;     

    Node(string nama, int jumlah, string tipe) {
        this->nama = nama;
        this->jumlah = jumlah;
        this->tipe = tipe;
        next = NULL;
    }
};

class ManajemenProduk {
private:
    Node* head;

public:
    ManajemenProduk() {
        head = NULL;
    }

    void tambahProduk() {
        string nama;
        int jumlah;
        string tipe;

        cin.ignore(); // Membersihkan buffer input
        cout << "========== TAMBAH PRODUK ==========" << endl;
        cout << "Nama Produk : ";
        getline(cin, nama);
        cout << "Jumlah Produk : ";
        cin >> jumlah;
        cin.ignore();
        cout << "Tipe Produk : ";
        getline(cin, tipe);

        //isi disini

        Node* newNode = new Node(nama, jumlah, tipe);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Produk berhasil ditambahkan!\n" << endl;
    }

    void tampilkanSemuaProduk() {
        cout << "========== SEMUA DATA PRODUK ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            Node* current = head;
            //isi disini
            int posisi = 1;
            while (current != NULL) {
                cout << "Produk " << posisi << ":" << endl;
                cout << "Nama: " << current->nama << endl;
                cout << "Jumlah: " << current->jumlah << endl;
                cout << "Tipe: " << current->tipe << endl;
                cout << endl;
                current = current->next;
                posisi++;
            }
        }
    }

    void cariProdukByNama() {
        cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
        if (head == NULL) {
            cout << "Belum ada data produk yang tersimpan." << endl;
        }
        else {
            string targetNama;
            cout << "Nama Produk yang dicari: ";
            getline(cin, targetNama);

            Node* current = head;
            int posisi = 1;
            bool ditemukan = false;

            while (current == NULL) {
                if (current->nama == targetNama) {
                    cout << "Produk ditemukan pada posisi " << posisi << ":" << endl;
                    cout << "Nama: " << current->nama << endl;
                    cout << "Jumlah: " << current->jumlah << endl;
                    cout << "Tipe: " << current->tipe << endl;
                    cout << endl;
                    ditemukan = true;
                }
                current = current->next;
                posisi++;
                //isi disini
            }

            if (!ditemukan) {
                cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
            }
        }
    }

    void algoritmaSortByJumlahProduk() {
        if (head == NULL || head->next == NULL) {
            return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
        }

        Node* current;
        Node* last = NULL;
        bool isSorted = false;

        while (!isSorted) {
            isSorted = true;
            current = head;

            while (current->next != last) {
                if (current->jumlah > current->next->jumlah) {
                    string tempNama = current->nama;
                    int tempJumlah = current->jumlah;
                    string tempTipe = current->tipe;

                    current->nama = current->next->nama;
                    current->jumlah = current->next->jumlah;
                    current->tipe = current->next->tipe;

                    current->next->nama = tempNama;
                    current->next->jumlah = tempJumlah;
                    current->next->tipe = tempTipe;

                    isSorted = false;
                }

                current = current->next;
            }

            last = current;
        }
    }
};

int main() {
    ManajemenProduk manajemenProduk;

    int pilihan;
    do {
        cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Cari Produk berdasarkan nama" << endl;
        cout << "4. Urutkan Produk berdasarkan jumlah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            manajemenProduk.tambahProduk();
            break;
        case 2:
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 3:
            manajemenProduk.cariProdukByNama();
            break;
        case 4:
            manajemenProduk.algoritmaSortByJumlahProduk();
            manajemenProduk.tampilkanSemuaProduk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            cout << endl;
        }
    } while (pilihan != 5);

    return 0;
}


//2. single linked list, linear search dan bubble sort
//3. circullar array -> pindah dari rear terus dilanjut ke front
// jadi data yang paling awal masuk akan menjadi paling awal di ambil

//4. ketika memanggil fungsi 
//5.  a. 5
    //b. Preorder -> perhitungan dari yang paling kiri dulu baru kekanan
