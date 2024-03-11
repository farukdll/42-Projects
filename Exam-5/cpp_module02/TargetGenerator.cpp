#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* target) {
    if(target)
        targets.insert(make_pair(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(const string& target) {
    map<string,ATarget*>::iterator it = targets.find(target);
    if(it != targets.end()) {
        delete it->second;
        targets.erase(target);
    }
}

ATarget* TargetGenerator::createTarget(const string& target) {
    map<string,ATarget*>::iterator it = targets.find(target);
    return it != targets.end() ? it->second : NULL;
}

TargetGenerator::~TargetGenerator() {
    for(map<string,ATarget*>::iterator it = targets.begin(); it != targets.end(); it++)
        delete it->second;
    targets.clear();
}