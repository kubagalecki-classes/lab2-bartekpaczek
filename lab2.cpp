#include <iostream>
class Wektor
{   public:
    Wektor(int n)
    {
        double* value = new double[n];
        *value = {0.};
    };
  
    double* value;
};

int main()
{
    Wektor dupa(5);
    for(int i = 0;i++; 5)
    {
        std::cout<<dupa.value[i];
    };
};
