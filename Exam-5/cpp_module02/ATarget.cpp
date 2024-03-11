#include "ATarget.hpp"

ATarget::ATarget(const string& type) {
    this->type = type;
}

const string& ATarget::getType() const {
    return this->type;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
    cout <<  type << " has been " << spell.getEffects() << "!" << endl;
}