#ifndef RAPTOREN_H
#define RAPTOREN_H
#include "carnivor.h"

class Raptoren : public Carnivor
{
public:
    Raptoren(Carnivor carni);
    bool hunt(Herbivor prey,Carnivor Rapto);
};

#endif // RAPTOREN_H
