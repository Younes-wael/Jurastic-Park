#ifndef DINOSAUR_H
#define DINOSAUR_H
#include <iostream>
#include "random.h"

using namespace std;


enum Race{
    Brachiosaurus,
    Parasaurolophus,
    Raptor,
    TyrannosaurusRex
};
class Dinosaur
{
public:
    /**
   * @brief Dinosar constructor
   * @param[in] race race of the first Dinosaur
   */
    Dinosaur(const Race race);
    /**
   * @brief Ages the Dinosaur.
   *
   * This shall increase  the ActualWeight of the Dinosaur if he did'nt reach his max weight.
   * Once the Dinosaur reaches his max Weigth he may Die. That means the Atribute DinosaurAlive may change.
   */
    void Age();
    /**
   * @brief Returns wether or not the Dinosaur will procruate.
   * @return True if the Dinosaur will procruate.
   *
   * The Dinosaur will procruate depending on the BreedChance attribute
   *
   */
    bool breed();
    /**
   * @brief Kills the Dinosaur.
   *
   * This shall change the life status of the Dinosaur to dead
   */
    void kill();
    /**
   * @brief Get the Dinosaurs's life status
   * @return true if the Dinosaur is still alive and false if he's dead
   */
    bool getLifeStatus();
    /**
   * @brief Get the Dinosaurs's ActualWeight
   * @return The Dinosaurs's ActualWeight
   */
    int getActualWeight();
    /**
   * @brief Get the Dinosaurs's Race
   * @return The Dinosaurs's Race
   */
    Race getRace();
private:

    /**
   * @brief Actual weight of the Dinosaur.
   */
    double m_ActualWeight;
    /**
   * @brief the maximal weight of the Dinosaur.
   */
    double m_MaxWeight;
    /**
   * @brief the race of the Dinosaur.
   */
   const Race m_Race;
    /**
   * @brief the breeding chance of the Dinosaur.
   */
    int BreedChance;
   /**
   * @brief the life status of the Dinosaur.
   */
    bool DinosaurAlive;
    /**
   * @brief the growrth rate of the Dinosaur.
   */
    double GrowthRate;
};

#endif // DINOSAUR_H
