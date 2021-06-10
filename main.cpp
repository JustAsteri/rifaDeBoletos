#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int numero, boletos_vendidos, cant_ganadores;
    srand(time(0));

    cout << "cuantos boletos fueron vendidos?"<< endl;
    cin>>boletos_vendidos;
    cout << "cuantos primeros lugares?"<< endl;
    cin>>cant_ganadores;

    for(int x=1; x<=cant_ganadores; x++)
    {
        numero=rand()%boletos_vendidos+1;
        cout << "el "<<x<<" lugar es el boleto numero: "<<numero<< endl;
    }

    return 0;
}