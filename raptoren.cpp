#include "raptoren.h"

Raptoren::Raptoren(Carnivor carni): Carnivor(carni)
{

}

bool Raptoren::hunt(Herbivor prey,Carnivor Rapto) {

    if (!prey.hideFromRaptor() && prey.getActualWeight() <= Rapto.getActualWeight()) {
        return true;
    }
    return false;
}
