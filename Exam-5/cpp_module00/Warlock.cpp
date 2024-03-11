#include "Warlock.hpp"

Warlock::Warlock(const string& name, const string& title) {
    this->name = name;
    this->title = title;
    cout << name << ": This looks like another boring day." << endl;
}

const string& Warlock::getName() const {
    return this->name;
}

const string& Warlock::getTitle() const {
    return this->title;
}

void Warlock::setTitle(const string& str) {
    this->title = str;
}

void Warlock::introduce() const {
    cout << name << ": I am " << name << ", " << title << "!" << endl;
}

Warlock::~Warlock() {
    cout << name << ": My job here is done!" << endl;
}

