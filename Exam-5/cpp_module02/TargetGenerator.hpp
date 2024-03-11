#pragma once

#include <map>
#include <utility>
#include "ATarget.hpp"

class TargetGenerator {
    private:
        map<string,ATarget*> targets;
        TargetGenerator(const TargetGenerator&);
        TargetGenerator& operator=(const TargetGenerator&) {return *this;}

    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget* target);
        void forgetTargetType(const string& target);
        ATarget* createTarget(const string& target);

};