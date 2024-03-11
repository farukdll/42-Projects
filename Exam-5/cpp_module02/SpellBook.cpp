#include "SpellBook.hpp"

SpellBook::SpellBook() {}

void SpellBook::learnSpell(ASpell* spell) {
    if(spell)
        spells.insert(make_pair(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(const string& spell) {
    map<string,ASpell*>::iterator it = spells.find(spell);
    if(it != spells.end()){
        delete it->second;
        spells.erase(spell);
    }
}

ASpell* SpellBook::createSpell(const string& spell) {
    map<string,ASpell*>::iterator it = spells.find(spell);
    return it != spells.end() ? it->second : NULL;
}

SpellBook::~SpellBook() {
    for(map<string,ASpell*>::iterator it = spells.begin(); it != spells.end(); it++)
        delete it->second;
    spells.clear();
}