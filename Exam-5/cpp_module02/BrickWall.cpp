#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {

}

ATarget* BrickWall::clone() const {
    return new BrickWall();
}