#ifndef CARNIVOR_H
#define CARNIVOR_H
#include "dinosaur.h"
#include "herbivor.h"

class Carnivor: public Dinosaur
{
public:
    /**
   * @brief Carnivor constructor
   * @param[in] dino an object dinosaur
   */
    Carnivor(Dinosaur dino);
    /**
   * @brief Returns wether or not the Carnivor will be able to hunt.
   * @return True if the Carnivor hunted his prey succesfully.
   *
   * the hunt is successfull when the prey's actual weight is less then the Carnivor's, and the prey should have been unable to hide
   *
   * \see hide
   */
    bool hunt(Herbivor prey, Carnivor hunter);
};

#endif // CARNIVOR_H

