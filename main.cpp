#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function to know if a number is repeat it
bool checkrep(int n, int num[], int boletos_vendidos)
{
    for(int i=0; i<boletos_vendidos; i++)
        if(n == num[i])
            return true;
    return false;
}
//***************************

int main()
{
  int n, numero[1000], boletos_vendidos, cant_ganadores, repetirRifa = 1;
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

    //Restrictions
    if
    ((boletos_vendidos <= limiteBoletos && boletos_vendidos > 1) && (cant_ganadores < boletos_vendidos && cant_ganadores > 0))
    {
      for(int x = 1; x <= cant_ganadores; x++)  
      {
        //Avoid repeat random numbers
        do
        {
          n = 1 + rand() % boletos_vendidos;
        }
        while (checkrep(n, numero, boletos_vendidos));
        numero[x] = n;
        //***************************
        cout << "El " << x << " lugar es el boleto numero: " << n << endl;
      }
    }
    else 
    {
      cout << endl;
      cout << "Ingresa valores validos"<< endl;
    }
    //*************************** 

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
    //***************************

    //Exit the game
    if (repetirRifa == 0)
    {
      cout << endl;
     cout << "Gracias por usar el programa numero uno de rifas" << endl;
    }
    //***************************
  }
  //***************************
  
  return 0;
}