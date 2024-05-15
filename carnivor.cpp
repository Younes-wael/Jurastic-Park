#include "carnivor.h"

Carnivor::Carnivor(Dinosaur dino): Dinosaur(dino) {

}

bool Carnivor::hunt(Herbivor prey, Carnivor hunter) {
    if (!prey.hide() && prey.getActualWeight() <= hunter.getActualWeight()) {
        return true;

    }
    return false;
}
