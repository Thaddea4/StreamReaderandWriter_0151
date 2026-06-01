#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

using namespace std;

class TokoElektronik
{
private:
    array<string, 3> rak;

public:
    TokoElektronik()
    {
        rak[0] = "Laptop";
        rak[1] = "Mouse";
        rak[2] = "Printer";
    }
    
    string ambilProduk(size_t nomorRak)
    {
        try
        {
            return rak.at(nomorRak);
        }
        catch (out_of_range&)
        {
            throw string("Gagal Mengambil Barang : Rak nomor " +
                         to_string(nomorRak) +
                         " kosong atau tidak tersedia!");
        }
    }
};

void tampilData()
{
    ifstream file("gudang.txt");
    string barang;
    int no = 1;

    cout << "\n===== DATA GUDANG =====\n";

    while (getline(file, barang))
    {
        cout << no++ << ". " << barang << endl;
    }

    file.close();
}

int main()
{
    TokoElektronik toko;
    int pilih;

    do
    {
        tampilData();

        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Update Barang\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Simulasi Etalase\n";
        cout << "5. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1)
        {
            ofstream file("gudang.txt", ios::app);
            string barang;

            cout << "Nama barang : ";
            getline(cin, barang);

            file << barang << endl;
            file.close();

            cout << "Data berhasil ditambah.\n";
        }

        else if (pilih == 2)
        {
            ifstream file("gudang.txt");
            vector<string> data;
            string barang;

            while (getline(file, barang))
            {
                data.push_back(barang);
            }
            file.close();

            int no;
            cout << "Nomor barang yang diubah : ";
            cin >> no;
            cin.ignore();

            if (no >= 1 && no <= data.size())
            {
                cout << "Nama baru : ";
                getline(cin, data[no - 1]);

                ofstream tulis("gudang.txt");

                for (int i = 0; i < data.size(); i++)
                {
                    tulis << data[i] << endl;
                }

                tulis.close();
                cout << "Data berhasil diubah.\n";
            }
        }

        else if (pilih == 3)
        {
            ifstream file("gudang.txt");
            vector<string> data;
            string barang;

            while (getline(file, barang))
            {
                data.push_back(barang);
            }
            file.close();

            int no;
            cout << "Nomor barang yang dihapus : ";
            cin >> no;

            if (no >= 1 && no <= data.size())
            {
                data.erase(data.begin() + (no - 1));

                ofstream tulis("gudang.txt");

                for (int i = 0; i < data.size(); i++)
                {
                    tulis << data[i] << endl;
                }

                tulis.close();
                cout << "Data berhasil dihapus.\n";
            }
        }

        else if (pilih == 4)
        {
            cout << "\nSkenario 1 (Rak 1)\n";

            try
            {
                cout << toko.ambilProduk(1) << endl;
            }
            catch (string pesan)
            {
                cout << pesan << endl;
            }

            cout << "\nSkenario 2 (Rak 5)\n";

            try
            {
                cout << toko.ambilProduk(5) << endl;
            }
            catch (string pesan)
            {
                cout << pesan << endl;
            }
        }

    } while (pilih != 5);

    return 0;
}