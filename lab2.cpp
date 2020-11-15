#include <iostream>
class Wektor
{
public:
    Wektor(int n) : dlugosc{n}
    {
        pojemnosc = n;
        value     = new double[n];
        setAll(0);
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
    
    //

    int  pojemnosc;
    void setAll(double value_all)
    {
        for (int i = 0; i < this->dlugosc; ++i) {
            value[i] = value_all;
        }
    };

    int get_dlugosc() { return dlugosc; };

    int get_pojemnosc() { return pojemnosc; };

    void print()
    {
        for (int i = 0; i < this->dlugosc; i++) {
            std::cout << value[i] << "\n";
        }
    };
    void zmienDlugosc(int n)
    {
        if (n <= pojemnosc) {
            for (int i = n; i < this->pojemnosc; ++i) {
                value[i] = 0;
            }
        }
        else {
            double* temp = new double[n];
            *temp = {0.};
            for (int i = 0; i < this->dlugosc; ++i) {
                temp[i] = value[i];
            };
            delete[] value;
            value = new double[n];
            value = temp;
            delete[] temp;
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
    double* value;
private:
    int dlugosc;
    
};

int main()
{
    Wektor dupa(6);
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
}