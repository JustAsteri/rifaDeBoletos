#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  srand(time(0));
  int rangoAzar = 50;
  
  for (int i = 1; i <= 3; i++)
  {
    int numero = rand() % rangoAzar + 1;
    cout << "El " << i << " lugar es el boleto numero: " << numero << endl; 
  }
}