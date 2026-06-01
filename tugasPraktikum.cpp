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