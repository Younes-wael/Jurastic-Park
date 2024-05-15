#include "dinosaur.h"

/**
 * @brief Dinosar constructor
 *
 * Assigning all the attributes of the Dinosaur depending on his race
 *
 * @param[in] race race of the first Dinosaur
 */
Dinosaur::Dinosaur(const Race race): m_Race(race), DinosaurAlive(true) {
    switch (race) {
    case Race::Brachiosaurus:
        GrowthRate = 20;
        BreedChance = 70;
        m_MaxWeight = 30000;
        m_ActualWeight = (m_MaxWeight * 5) / 100;
        break;
    case Race::Parasaurolophus:
        GrowthRate = 40;
        BreedChance = 90;
        m_MaxWeight = 1500;
        m_ActualWeight = (m_MaxWeight * 5) / 100;
        break;
    case Race::Raptor:
        GrowthRate = 30;
        BreedChance = 60;
        m_MaxWeight = 500;
        m_ActualWeight = (m_MaxWeight * 20) / 100;
        break;
    case Race::TyrannosaurusRex:
        GrowthRate = 20;
        BreedChance = 40;
        m_MaxWeight = 8000;
        m_ActualWeight = (m_MaxWeight * 20) / 100;
        break;
    default:
        break;
    }

}

Race Dinosaur::getRace() {
    return m_Race;
}

int Dinosaur::getActualWeight() {
    return m_ActualWeight;
}

void Dinosaur::Age() {
    m_ActualWeight += (m_ActualWeight * GrowthRate) / 100;
    if (m_ActualWeight > m_MaxWeight) {
        m_ActualWeight = m_MaxWeight;
        if (getRandom(1, 100) > GrowthRate) {
            DinosaurAlive = false;
        }
    }
}

void Dinosaur::kill() {
    DinosaurAlive = false;
}
bool Dinosaur::getLifeStatus() {
    return DinosaurAlive;
}
bool Dinosaur::breed() {

    if (getRandom(1, 100) <= BreedChance) {

        return true;
    }
    return false;
}
