#include "herbivor.h"

Herbivor::Herbivor(Dinosaur dino): Dinosaur(dino) {
    if (dino.getRace() == Race::Brachiosaurus) HidingChance = 50;
    else HidingChance = 40;
    HidingChanceRaptor=HidingChance;
}

void Herbivor::decreaseHidingChance(int PackHuntingChance){
    HidingChanceRaptor-=PackHuntingChance;
}
void Herbivor::reinitialiseHidingChance(){
    HidingChanceRaptor=HidingChance;
}

bool Herbivor::hideFromRaptor() {
    if (getRandom(1, 100) <= HidingChanceRaptor)
        return true;

    return false;
}

bool Herbivor::hide() {
    if (getRandom(1, 100) <= HidingChance)
        return true;

    return false;
}
