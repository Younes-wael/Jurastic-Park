#include <iostream>

#include "herbivor.h"

#include "carnivor.h"
#include "trexe.h"
#include "raptoren.h"
#include <vector>

#include <array>

using namespace std;

/**
 * @brief takes the dead Carnivors out of the vector.
 *@param[in] vector of carnivors
 *
 * This shall put the Carnivors that are still alive in a new vector and then clear off the old vector.
 * Finally it pushes back all the Carnivors that are Alive again in the cleared list
 */
void takeOutTheDeadCarnivoren(vector < Carnivor > & Dinosaurs) {
    vector < Carnivor > DinosaursAlive;
    for (auto & Dino: Dinosaurs) {
        if (Dino.getLifeStatus()) DinosaursAlive.push_back(Dino);
    }
    Dinosaurs.clear();
    for (auto Dino: DinosaursAlive)
        Dinosaurs.push_back(Dino);}

void takeOutTheDeadRaptoren(vector < Raptoren > & Dinosaurs) {
    vector < Raptoren > DinosaursAlive;
    for (auto & Dino: Dinosaurs) {
        if (Dino.getLifeStatus()) DinosaursAlive.push_back(Dino);
    }
    Dinosaurs.clear();
    for (auto Dino: DinosaursAlive)
        Dinosaurs.push_back(Dino);
}

void takeOutTheDeadTrexe(vector < TRexe > & Dinosaurs) {
    vector < TRexe > DinosaursAlive;
    for (auto & Dino: Dinosaurs) {
        if (Dino.getLifeStatus()) DinosaursAlive.push_back(Dino);
    }
    Dinosaurs.clear();
    for (auto Dino: DinosaursAlive)
        Dinosaurs.push_back(Dino);
}
/**
 * @brief takes the dead Herbivors out of the vector.
 *@param[in] vector of Herbivors
 *
 * This shall put the Herbivors that are still alive in a new vector and then clear off the old vector.
 * Finally it pushes back all the Herbivors that are Alive again in the cleared list
 */
void takeOutTheDeadHerbivoren(vector < Herbivor > & Dinosaurs) {
    vector < Herbivor > DinosaursAlive;
    for (auto & Dino: Dinosaurs) {
        if (Dino.getLifeStatus()) DinosaursAlive.push_back(Dino);
    }
    Dinosaurs.clear();
    for (auto Dino: DinosaursAlive)
        Dinosaurs.push_back(Dino);
}

/**
 * @brief ages the Dinosaurs, does the breeding and
 *@param[in] vector of Herbivors
 *@param[in] vector of Carnivors
 *@param[in] total number of Dinosaurs
 *
 *
 * @return an array representing the Population of dinosaurs in the park
 */
array < int, 4 > PassingTime(vector < Herbivor > & Herbivoren, vector < Carnivor > & Carnivoren,
                          int & NumberOfDinos) {

    const int Carni = Carnivoren.size();
    //for loop that makes breeding for each Carnivor by pushing back a new Dinosaur in the vector and than calls method age
    for (int i = 0; i < Carni; ++i) {
        if (Carnivoren[i].getLifeStatus() and Carnivoren[i].breed() and NumberOfDinos < 100) {
            Carnivoren.push_back(Carnivor((Dinosaur(Carnivoren[i].getRace()))));
            NumberOfDinos++;
        }
        Carnivoren[i].Age();
    }

    const int Herbi = Herbivoren.size();

    //for loop that makes breeding for each Herbivor by pushing back a new Dinosaur in the vector and than calls method age
    for (int i = 0; i < Herbi; ++i) {
        if (Herbivoren[i].getLifeStatus() and Herbivoren[i].breed() and NumberOfDinos < 100) {
            // if the Herbivor is a Parasaurolophus he gets three babys at once
            if (Herbivoren[i].getRace() == Parasaurolophus) {
                if (NumberOfDinos < 98)
                    for (int j = 0; j < 3; ++j) {
                        Herbivoren.push_back(Herbivor((Dinosaur(Herbivoren[i].getRace()))));
                        NumberOfDinos++;

                    }
            } else {
                Herbivoren.push_back(Herbivor((Dinosaur(Herbivoren[i].getRace()))));
                NumberOfDinos++;

            }
        }

        Herbivoren[i].Age();
    }

    takeOutTheDeadCarnivoren(Carnivoren);
    takeOutTheDeadHerbivoren(Herbivoren);

    vector< TRexe > Trexe;
    vector< Raptoren> raptor;
    int PackHuntingChance=0;

    for (auto & Carni: Carnivoren) {
        if(Carni.getRace()==TyrannosaurusRex) Trexe.push_back(Carni);
        else {
            raptor.push_back(Carni);
            PackHuntingChance++;
        }
    }

    for (auto& Herbis : Herbivoren) {
        //just to readjust the changements of hiding chance made by the death of raptors
        Herbis.reinitialiseHidingChance();
        Herbis.decreaseHidingChance(PackHuntingChance);
    }

    for (auto & rapto: raptor) {
        bool raptorfed = false;
        for (int chase = 0; chase < 2; chase++) {
            for (auto & Herbi: Herbivoren) {
                if (Herbi.getLifeStatus() && rapto.hunt(Herbi, rapto)) {
                    Herbi.kill();
                    raptorfed = true;
                    break;
                }
            }

            if (raptorfed) {
                takeOutTheDeadHerbivoren(Herbivoren);
                break;
            }
        }
        if (!raptorfed) {
            rapto.kill();
        }
    }
    takeOutTheDeadHerbivoren(Herbivoren);
    takeOutTheDeadRaptoren(raptor);

    // for loop in which every carnivor makes his hunt on every Herbivor and if his hunt fails 2 times then he dies
    for (auto & Tr: Trexe) {
        bool Trexefed = false;
        for (int chase = 0; chase < 2; chase++) {
            for (auto & Herbi: Herbivoren) {
                if (Herbi.getLifeStatus() and  Tr.huntHerbi(Herbi, Tr)) {
                    Herbi.kill();
                    Trexefed = true;
                    break;
                }
            }

            if (Trexefed) {
                takeOutTheDeadHerbivoren(Herbivoren);
                break;
            }
        // if no herbivor was hunted then we chase the raptors
        if (!Trexefed) {
                for (auto & rapto: raptor) {
                    if (rapto.getLifeStatus() and  Tr.huntRapto(rapto, Tr)) {
                        rapto.kill();
                        Trexefed = true;
                        break;
                    }
                }

                if (Trexefed) {
                    takeOutTheDeadRaptoren(raptor);
                    break;
                }
            }
        }
       //if  no herbivor or raptor was hunted twice then Trexe dies
        if (!Trexefed) {
            Tr.kill();
        }
    }
    takeOutTheDeadHerbivoren(Herbivoren);
    takeOutTheDeadRaptoren(raptor);
    takeOutTheDeadTrexe(Trexe);

    // reinitialise the carnivor vector
    Carnivoren.clear();
    for (auto& Tr: Trexe){
        Carnivoren.push_back(Tr);
    }
    for (auto& rapto: raptor) {
        Carnivoren.push_back(rapto);
    }

    int BrachiosaurusPopulation = 0;
    int ParasaurolophusPopulation = 0;
    int RaptorPopulation = raptor.size();
    int TyrannosaurusRexPopulation = Trexe.size();

    // Two for loops counting the population of each race of the Dinosaurs
    for (auto Herbi: Herbivoren) {
        if (Herbi.getRace() == Brachiosaurus)
            BrachiosaurusPopulation++;
        else ParasaurolophusPopulation++;
    }


    // total number of dinosaurs
    NumberOfDinos = BrachiosaurusPopulation + ParasaurolophusPopulation + RaptorPopulation + TyrannosaurusRexPopulation;

    cout << "Brachiosaurus Population: " << BrachiosaurusPopulation << endl;
    cout << "Parasaurolophus Population: " << ParasaurolophusPopulation << endl;
    cout << "Raptor Population: " << RaptorPopulation << endl;
    cout << "TyrannosaurusRex Population: " << TyrannosaurusRexPopulation << endl << endl;
 //   cout << endl << " Number Of Dinos: " << NumberOfDinos << endl << endl;

    //initialising the array that would be returned
    array < int, 4 > Population;
    Population = {
        BrachiosaurusPopulation,
        ParasaurolophusPopulation,
        RaptorPopulation,
        TyrannosaurusRexPopulation
    };
    return Population;
}

int main() {
    // Initialising the vector of HerbivorsI
    vector < Herbivor > Herbivoren;

        for (int i = 0; i < 4; ++i) {
        Herbivoren.push_back(Herbivor((Dinosaur(Race::Brachiosaurus))));
    }
    for (int i = 0; i < 5; ++i) {
        Herbivoren.push_back(Herbivor((Dinosaur(Race::Parasaurolophus))));
    }

    // Initialising the vector of Carnivors
    vector < Carnivor > Carnivoren;
    for (int i = 0; i < 4; ++i) {
        Carnivoren.push_back(Carnivor((Dinosaur(Race::Raptor))));
    }
    for (int i = 0; i < 2; ++i) {
        Carnivoren.push_back(Carnivor((Dinosaur(Race::TyrannosaurusRex))));
    }
    int BrachiosaurusPopulation = 4;
    int ParasaurolophusPopulation = 5;
    int RaptorPopulation = 4;
    int TyrannosaurusRexPopulation = 2;
    int NumberOfHerbivors = 9;
    int NumberOfCarnivors = 6;
    int NumberOfDinos = 15;
    cout << "Brachiosaurus Population: " << BrachiosaurusPopulation << endl;
    cout << "Parasaurolophus Population: " << ParasaurolophusPopulation << endl;
    cout << "Raptor Population: " << RaptorPopulation << endl;
    cout << "TyrannosaurusRex Population: " << TyrannosaurusRexPopulation << endl << endl;

    string inp;

    //initialising the array containing the integer variables representing the population of each race of the Dinosaurs
    array < int, 4 > Population;
    Population = {
        BrachiosaurusPopulation,
        ParasaurolophusPopulation,
        RaptorPopulation,
        TyrannosaurusRexPopulation
    };

    //do while loop that calls the method of Passing Time and stops when the Carnivors extinct
    do {

        Population = PassingTime(Herbivoren, Carnivoren, NumberOfDinos);

        if (Population[2] == 0 and Population[3] == 0)
            inp = "end";

    } while (inp != "end");

    return 0;
}
