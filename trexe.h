#ifndef TREXE_H
#define TREXE_H
#include "carnivor.h"


class TRexe : public Carnivor
{
public:
    TRexe(Carnivor carni);
    bool huntHerbi(Herbivor prey,Carnivor TRexe) ;
    bool huntRapto(Carnivor Raptor,Carnivor TRexe);
};

#endif // TREXE_H
