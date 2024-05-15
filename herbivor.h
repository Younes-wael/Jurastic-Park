#ifndef HERBIVOR_H
#define HERBIVOR_H
#include "dinosaur.h"
#include <vector>

class Herbivor : public Dinosaur
{
public:
    /**
   * @brief Herbivor constructor
   * @param[in] dino an object dinosaur
   */
    Herbivor(Dinosaur dino);
    /**
   * @brief Returns wether or not the Herbivor will be able to hunt.
   * @return True if the Herbivor hided succesfully.
   *
   * the hide is depending on the hiding chance of the dinosaur
   *
   * \see hide
   */
    void decreaseHidingChance(int PackHuntingChance);
    void reinitialiseHidingChance();
    bool hideFromRaptor();
    bool hide();
private:
    /**
   * @brief Hiding chance of the Herbivor.
   */
    int HidingChance;
    int HidingChanceRaptor;
};

#endif // HERBIVOR_H

