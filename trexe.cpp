#include "trexe.h"

TRexe::TRexe(Carnivor carni): Carnivor(carni)
{

}

bool TRexe::huntHerbi(Herbivor prey,Carnivor TRexe) {
    if (!prey.hide() && prey.getActualWeight() <= TRexe.getActualWeight()) {
        return true;
    }
    return false;
}

bool TRexe::huntRapto(Carnivor Raptor,Carnivor TRexe) {
    if(Raptor.getActualWeight() <= TRexe.getActualWeight()) return true;
    return false;

}
