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
};