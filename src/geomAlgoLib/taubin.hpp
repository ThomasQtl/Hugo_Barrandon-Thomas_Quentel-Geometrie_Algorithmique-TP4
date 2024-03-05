#pragma once

#include "types.hpp"
#include "gaussien.hpp"

namespace geomAlgoLib
{
    Polyhedron taubinFilter(const Polyhedron &P, float lambda, float mu);
    Polyhedron taubinMultipleFilter(const Polyhedron &P, float lambda, float mu, int nbIter);
}