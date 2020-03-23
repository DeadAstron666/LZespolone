#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Stats.hh"

#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
  
  if (argc < 2) //Sprawdzenie czy podano argument 
  {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu   BazaT = { nullptr, 0, 0 }; 

  if (InicjalizujTest(&BazaT,argv[1]) == false) //Inicjalizacja testu 
  {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
  
  cout << endl;  //INFO
  cout << "---- Start testu arytmetyki zespolonej ----" << endl << "#Format odp: (a+-bi)" << endl << "#Poziom: " << argv[1] << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Odpowiedz;
  Stats Statyskyka = stats_init();


  while ( PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe) ) {
    cout << endl << "-- Pytanie " << getWsz(Statyskyka)+1 <<  " --" << endl;
    cout << WyrZ_PytanieTestowe << endl;
    cout << "Odp.: ";

    cin >> Odpowiedz;

    while( cin.fail() )
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "!Zla forma, napisz jeszcze raz!\nOdp.: ";
      cin >> Odpowiedz;
    }    

    if( Odpowiedz == Oblicz(WyrZ_PytanieTestowe) )
    {
      cout << "***Odp. DOBRA***" << endl;
      dodaj_dobra(Statyskyka);
    }
    else
    {
      cout << "***Odp. ZLA*** Poprawna to:  " << Oblicz(WyrZ_PytanieTestowe) << endl;
      dodaj_zla(Statyskyka);
    }
  }

    
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

  cout << Statyskyka;

}
