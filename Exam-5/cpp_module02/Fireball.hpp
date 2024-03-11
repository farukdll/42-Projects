#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell {
    public:
        Fireball();
        ASpell* clone() const;
};