#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph","turned into a critter") {

}

ASpell* Polymorph::clone() const {
    return new Polymorph();
}