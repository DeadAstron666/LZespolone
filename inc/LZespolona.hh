#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH


struct  LZespolona {
  double   re;    //czesc rzeczywista
  double   im;    //czesc urojona
};


LZespolona utworzLZ(double _re, double _im); 
void wyswLZ(LZespolona z);


/*Op Wlasne*/
double modul(LZespolona z);
LZespolona sprzez(LZespolona z);


/*Op Arytmetyczne*/
LZespolona  operator + (LZespolona  z1,  LZespolona  z2);
LZespolona  operator - (LZespolona  z1,  LZespolona  z2);
LZespolona  operator * (LZespolona  z1,  LZespolona  z2);
LZespolona  operator / (LZespolona  z1,  double  dzielnik);
LZespolona  operator / (LZespolona  z1,  LZespolona  z2);


/*Op Logiczne*/
bool operator == (LZespolona  z1,  LZespolona  z2);
bool operator != (LZespolona  z1,  LZespolona  z2);


#endif
