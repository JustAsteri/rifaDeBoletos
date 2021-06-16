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
  string letras_boletos_vendidos, letras_cant_ganadores, menu;
  bool validarEntradas;
  string repetirRifa;
  int limiteBoletos = 1000;

  srand(time(0));

  //Repeat the raffle
  do
  {
    cout << endl;
    system("Color 17");
    cout << "****************************************************************" << endl;
    cout << "| Bienvenido al mejor programa de generacion de Rifas que hay! |" << endl;
    cout << "****************************************************************" << endl;
    
    //Loop if the user gives out of range value
    do 
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
            cout << "***********************"<< endl;
              cout << "Ingrese numeros validos" << endl;
              cout << "***********************"<< endl;
            validarEntradas = false;
          }
          else
          {
            if (boletos_vendidos < 1 || boletos_vendidos > 1000)
            {
              cout << endl;
              cout << "***********************"<< endl;
              cout << "Ingrese numeros validos" << endl;
              cout << "***********************"<< endl;
              cout << endl;
            }
            validarEntradas = true;
          }
        }
        catch (exception e)
        {
          cout << endl;
          cout << "***********************"<< endl;
          cout << "Ingrese numeros validos" << endl;
          cout << "***********************"<< endl;
          cout << endl;
          validarEntradas = true;
        }
      } while (validarEntradas == false);
    } while (boletos_vendidos < 1 || boletos_vendidos > 1000);

    //Loop if the user gives out of range value
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
            cout << "***********************"<< endl;
            cout << "Ingrese numeros validos" << endl;
            cout << "***********************"<< endl;
            validarEntradas = false;
          }
          else
          {
            if ((cant_ganadores < 1 || cant_ganadores > boletos_vendidos))
            {
              cout << endl;
              cout << "***********************"<< endl;
              cout << "Ingrese numeros validos" << endl;
              cout << "***********************"<< endl;
              cout << endl;
            }
            validarEntradas = true;
          }
          cout << endl;
        }
        catch (exception e)
        {
          cout << endl;
          cout << "***********************"<< endl;
          cout << "Ingrese numeros validos" << endl;
          cout << "***********************"<< endl;
          cout << endl;
          validarEntradas = true;
        }
      } while (validarEntradas == false);
    } while (cant_ganadores < 1 || cant_ganadores > boletos_vendidos);
    cout << endl;
    cout << endl;

    //Loop through the winners of the raffle
    for(int x = 1; x <= cant_ganadores; x++)
    {
      system("Color 27");
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

    //Exit menu
    do
    {
      cout << endl;
      cout << "+------------------------------------------------+" << endl;
      menu = "| Que desea hacer?                               |\n|  Presione 1 para: Realizar otra rifa           |\n|  Presione 2 para: Ver los ganadores otra vez   |\n|  Presione culquier otra tecla para: Salir      |";
      cout << menu << endl;
      cout << "+------------------------------------------------+" << endl;
      cout << endl;
      cout << "--------------> ";
      cin >> repetirRifa;
      //system("clear"); //Linux
      system("cls"); //Windows

      //Condition of the menu
      if (repetirRifa == "1")
      {
        validarEntradas = true;
      }
      else if (repetirRifa == "2")
      {
        for(int x = 1; x <= cant_ganadores; x++)
        {
          system("Color 27");
          cout << "*************************************************"<< endl;
          cout << "| El ganador numero " << x << " es el boleto numero: " << numero[x] << endl;
          cout << "*************************************************"<< endl;
        }
        validarEntradas = false;
      }
      else
      {
        validarEntradas = true;
      }
    }
    while (validarEntradas == false);
  }
  while (repetirRifa == "1");

  //end of the game
  cout << endl;
  cout << "+--------------------------------------------------+" << endl;
  cout << "| Gracias por usar el programa numero uno de rifas |" << endl;
  cout << "+--------------------------------------------------+" << endl;
  cout << endl;
  //***************************
  return 0;
}