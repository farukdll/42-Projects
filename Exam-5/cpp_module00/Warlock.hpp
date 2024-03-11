#pragma once

#include <iostream>

using namespace std;

class Warlock {
    private:
        string name;
        string title;
        Warlock(const Warlock&);
        Warlock& operator=(const Warlock&);

    public:
        Warlock(const string& name, const string& str);
        ~Warlock();
        const string& getName() const;
        const string& getTitle() const;
        void setTitle(const string& name);
        void introduce() const;

};