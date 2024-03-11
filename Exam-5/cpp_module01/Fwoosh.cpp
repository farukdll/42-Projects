#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh","fwooshed") {

}

ASpell* Fwoosh::clone() const {
    return new Fwoosh();
}