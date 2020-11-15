#include <iostream>
class Wektor
{
private:
    int dlugosc;
    int  pojemnosc; 

public:
    double* value;   

    Wektor(int n) : dlugosc{n}
    {
        pojemnosc = n;
        value     = new double[n];
    };
    ~Wektor(){
        delete[] value;
    };
    // konstruktor kopiujacy
    Wektor(const Wektor& t){
        dlugosc = t.dlugosc;
        pojemnosc = t.pojemnosc;
        value = t.value;
    }

    void setAll(double value_all)
    {
        for (int i = 0; i < dlugosc; ++i) {
            value[i] = value_all;
        }
    };

    int get_dlugosc() { return dlugosc; };

    int get_pojemnosc() { return pojemnosc; };

    void print()
    {
        for (int i = 0; i < dlugosc; i++) {
            std::cout << value[i] << "\n";
        }
    };
    void zmienDlugosc(int n)
    {
        if (n <= pojemnosc) {
            for (int i = n; i < pojemnosc; ++i) {
                value[i] = 0;
            }
        }
        else {
            double* temp = new double[n];
            for (int i = 0; i < dlugosc; ++i) {
                temp[i] = value[i];
            };
            delete[] value;
            value = temp;
            pojemnosc = n;
        };
        dlugosc = n;
    };
    double& operator[](int ref)
    {
        if (ref>dlugosc)
        {
            zmienDlugosc(ref);
        };
        return value[ref];
    };

};


int main()
{
    Wektor dupa(6);
//    dupa.print();
//    std::cout << "nowy\n";
    dupa.setAll(2.);
    dupa.print();
    dupa.zmienDlugosc(10);
    std::cout << "nowy1\n";
    dupa.print();
    std::cout << "nowy\n";
    double& a = dupa[4];
    a=12;
    dupa.print();
    std::cout << dupa.get_dlugosc();
    std::cout << "nowy\n";
    double& b = dupa[8];
    b=12;
    dupa.print();

    int g = 6;
    int& h = g;
    h= 9;
    std::cout<<g;

}