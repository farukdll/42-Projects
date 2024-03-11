#pragma once

#include "ASpell.hpp"

class Polymorph : public ASpell {
    public:
        Polymorph();
        ASpell* clone() const;
};