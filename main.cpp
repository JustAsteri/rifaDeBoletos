#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdlib.h>
//#include <windows.h>

using namespace std;

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
  string letras_boletos_vendidos, letras_cant_ganadores;
  bool validarEntradas;
  string repetirRifa;
  int limiteBoletos = 1000;

  srand(time(0));

  //Repeat the raffle
  do //Loop if the user wants to do another raffle
  {
    cout << endl;
    cout << "****************************************************************" << endl;
    cout << "| Bienvenido al mejor programa de generacion de Rifas que hay! |" << endl;
    cout << "****************************************************************" << endl;
    do //Loop if the user gives out of range value
    {
      cout << endl;
      cout << "******************************************************************************" << endl;
      cout << "| cuantos boletos fueron vendidos? (Valores validos: Numeros entre 1 y 1000) |" << endl;
      cout << "******************************************************************************" << endl;
      cout << "--------------> ";
      do //Loop to check if the value is valid (numbers) 
      {
        try 
        {
          cin>>letras_boletos_vendidos;
          boletos_vendidos = stoi(letras_boletos_vendidos);
          if (boletos_vendidos == false)
          {
            cout << endl;
            cout << "Ingrese numeros validos" << endl;
            validarEntradas = false;
          }
          else
          {
            if (boletos_vendidos < 1 || boletos_vendidos > 1000)
            {
              cout << endl;
              cout << "Ingrese numeros validos" << endl;
              cout << endl;
            }
            validarEntradas = true;
          }
        }
        catch (exception e)
        {
          cout << endl;
          cout << "Ingrese numeros validos" << endl;
          cout << endl;
          validarEntradas = true;
        } 
      } while (validarEntradas == false);
    } while (boletos_vendidos < 1 || boletos_vendidos > 1000);

    do
    {
      cout << endl;
      cout << "*******************************************************************"<< endl;
      cout << "| cuantos ganadores hay? (Valores validos: Numeros entre 1 y " << boletos_vendidos << "" ") |" << endl;
      cout << "*******************************************************************"<< endl;
      cout << "--------------> ";
      do //Loop to check if the value is valid (numbers) 
      {
        try 
        {
          cin>>letras_cant_ganadores;
          cant_ganadores = stoi(letras_cant_ganadores);
          if (cant_ganadores == false)
          {
            cout << endl;
            cout << "Ingrese numeros validos" << endl;
            validarEntradas = false;
          }
          else
          {
            if ((cant_ganadores < 1 || cant_ganadores > boletos_vendidos))
            {
              cout << endl;
              cout << "Ingrese numeros validos" << endl;
              cout << endl;
            }
            validarEntradas = true;
          }
          cout << endl;
        }
        catch (exception e)
        {
          cout << endl;
          cout << "Ingrese numeros validos" << endl;
          cout << endl;
          validarEntradas = true;
        } 
      } while (validarEntradas == false);
    } while (cant_ganadores < 1 || cant_ganadores > boletos_vendidos);
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
    //system("clear"); //Linux
    system("cls"); //Windows
  }
  while (repetirRifa == "1");

  //Exit the game
  cout << endl;
  cout << "Gracias por usar el programa numero uno de rifas" << endl;
  //***************************
  return 0;
}