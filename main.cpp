#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int numero, boletos_vendidos, cant_ganadores;
  int limiteBoletos = 1000;

  srand(time(0));

  cout << "cuantos boletos fueron vendidos? (Valores validos: 1 - 1000)"<< endl;
  cin>>boletos_vendidos;
  cout << "cuantos ganadores hay? (Valores validos: 1 - 1000)"<< endl;
  cin>>cant_ganadores;


  if //Restrictions 
  (
    (boletos_vendidos <= limiteBoletos && boletos_vendidos > 1) 
    && 
    (cant_ganadores < boletos_vendidos && cant_ganadores > 0)
  )
  {
    for(int x = 1; x <= cant_ganadores; x++)  
    {
      numero = rand() % boletos_vendidos + 1; //Creating random numbers
      cout << "El " << x << " lugar es el boleto numero: " << numero << endl;
    }
  }
  else 
  {
    cout << "Ingresa valores validos"<< endl;
  }  

  return 0;
}