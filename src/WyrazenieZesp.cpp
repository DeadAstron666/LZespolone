#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */


LZespolona Oblicz(WyrazenieZesp  WyrZ){
  
  switch(WyrZ.Op)
    {
    case Op_Dodaj:
      return WyrZ.Arg1 + WyrZ.Arg2;

    case Op_Odejmij:
      return WyrZ.Arg1 - WyrZ.Arg2;

    case Op_Mnoz:
      return WyrZ.Arg1 * WyrZ.Arg2;

    case Op_Dziel:
      return WyrZ.Arg1 / WyrZ.Arg2;
    
    }
}
