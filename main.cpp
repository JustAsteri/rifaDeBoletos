#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
  Error cuando ingresan dato no numerico

*/

//Function to know if a number is repeat it
bool checkrep(int n, int num[], int boletos_vendidos)
{
  for(int i=0; i<boletos_vendidos; i++)
  {
    if(n == num[i])
    {
      return true;
    }
  } 
  return false;
}
//***************************

int main()
{
  int n, numero[1000], boletos_vendidos, cant_ganadores;
  bool validarEntradas;
  string repetirRifa;
  int limiteBoletos = 1000;

  srand(time(0));

  //Repeat the raffle
  do
  {
    cout << endl;
    cout << "****************************************************************" << endl;
    cout << "| cuantos boletos fueron vendidos? (Valores validos: 1 - 1000) |" << endl;
    cout << "****************************************************************"<< endl;
    cout << "--------------> ";
    cin>>boletos_vendidos;
      //Restrictions
      while (boletos_vendidos < 1 || boletos_vendidos > 1000)
      {
        cout << endl;
        cout << "Ingrese numeros validos" << endl;
        cout << endl;
        cout << "****************************************************************" << endl;
        cout << "| cuantos boletos fueron vendidos? (Valores validos: 1 - 1000) |" << endl;
        cout << "****************************************************************"<< endl;
        cout << "--------------> ";
        cin>>boletos_vendidos;
      }
    cout << endl;
    cout << "******************************************************"<< endl;
    cout << "| cuantos ganadores hay? (Valores validos: 1 - 1000) |" << endl;
    cout << "******************************************************"<< endl;
    cout << "--------------> ";
    cin>>cant_ganadores;
      //Restrictions
      while (cant_ganadores < 1 || cant_ganadores > boletos_vendidos)
      {
        cout << endl;
        cout << "Ingrese numeros validos" << endl;
        cout << endl;
        cout << "******************************************************"<< endl;
        cout << "| cuantos ganadores hay? (Valores validos: 1 - 1000) |" << endl;
        cout << "******************************************************"<< endl;
        cout << "--------------> ";
        cin>>boletos_vendidos;
      }
    cout << endl;
    cout << endl;

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
      cout << "*************************************************"<< endl;
      cout << "| El ganador numero " << x << " es el boleto numero: " << n << endl;
      cout << "*************************************************"<< endl;
    }
    cout << endl;
    cout << "Desea realizar otra rifa? \n 1 = Si\n Cualquier otra tecla = No" << endl;
    cout << "--------------> ";
    cin >> repetirRifa;
  }
  while (repetirRifa == "1");

  //Exit the game
  cout << endl;
  cout << "Gracias por usar el programa numero uno de rifas" << endl;
  //***************************
  return 0;
}