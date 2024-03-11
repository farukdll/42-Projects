#pragma once

#include <iostream>
using namespace std;

class ATarget;
#include "ATarget.hpp"

class ASpell {
    protected:
        string name;
        string effects;

    public:
        ASpell(const string& name, const string& effects);
        virtual ~ASpell() {};
        const string& getName() const;
        const string& getEffects() const;
        virtual ASpell* clone() const = 0;
        void launch(const ATarget& target) const;
};