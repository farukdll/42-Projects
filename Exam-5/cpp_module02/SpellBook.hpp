#pragma once

#include <map>
#include <utility>
#include "ASpell.hpp"

using namespace std;

class SpellBook {
    private:
        map<string,ASpell*> spells;
        SpellBook(const SpellBook&);
        SpellBook& operator=(const SpellBook&) {return *this;}

    public:
        SpellBook();
        ~SpellBook();
        void learnSpell(ASpell* spell);
        void forgetSpell(const string& spell);
        ASpell* createSpell(const string&);

};