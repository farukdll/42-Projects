#pragma once

class ASpell;
#include "ASpell.hpp"

class ATarget {
    protected:
        string type;

    public:
        ATarget(const string& type);
        virtual ~ATarget() {};
        const string& getType() const;
        virtual ATarget* clone() const = 0;
        void getHitBySpell(const ASpell& spell) const;
};