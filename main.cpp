#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  int numero, boletos_vendidos, cant_ganadores, repetirRifa = 1;
  int limiteBoletos = 1000;

  srand(time(0));

  //Repeat the raffle
  while (repetirRifa == 1) 
  {
    cout << "cuantos boletos fueron vendidos? (Valores validos: 1 - 1000)"<< endl;
    cout << "--------------> ";
    cin>>boletos_vendidos;
    cout << "cuantos ganadores hay? (Valores validos: 1 - 1000)"<< endl;
    cout << "--------------> ";
    cin>>cant_ganadores;
    cout << endl;

    //Restrictions--
    if
    ((boletos_vendidos <= limiteBoletos && boletos_vendidos > 1) && (cant_ganadores < boletos_vendidos && cant_ganadores > 0))
    {
      for(int x = 1; x <= cant_ganadores; x++)  
      {
        numero = rand() % boletos_vendidos + 1; //Creating random numbers
        cout << "El " << x << " lugar es el boleto numero: " << numero << endl;
      }
    }
    else 
    {
      cout << endl;
      cout << "Ingresa valores validos"<< endl;
    }
    //--Restrictions 

    //Loop for repeat the raffle --
    cout << endl;
    cout << "Desea realizar otra rifa? \n 1 = Si\n 0 = No" << endl;
    cout << "--------------> ";
    cin >> repetirRifa;
    
    while (repetirRifa != 1 && repetirRifa != 0)
    {
        cout << "Ingresa un valor valido (1 o 0): " << endl;
        cout << "--------------> ";
        cin >> repetirRifa;
    }
    //--Loop for repeat the raffle

    //Exit the game
    if (repetirRifa == 0)
    {
      cout << endl;
     cout << "Gracias por usar el programa numero uno de rifas" << endl;
    }
  }
  
  return 0;
}