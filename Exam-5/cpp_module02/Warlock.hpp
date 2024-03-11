#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "SpellBook.hpp"
#include <map>

using namespace std;

class Warlock {
    private:
        string name;
        string title;
        SpellBook spellBook;
        Warlock(const Warlock&);
        Warlock& operator=(const Warlock&) {return *this;}
    
    public:
        Warlock(const string& name, const string& title);
        ~Warlock();
        const string& getName() const;
        const string& getTitle() const;
        void setTitle(const string& str);
        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(const string& spell);
        void launchSpell(string spell, const ATarget& target);

};