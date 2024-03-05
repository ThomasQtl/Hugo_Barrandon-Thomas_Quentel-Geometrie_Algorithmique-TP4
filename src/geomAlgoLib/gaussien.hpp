#pragma once

#include "types.hpp"

namespace geomAlgoLib
{
    Polyhedron gaussienFilter(const Polyhedron &P, float lambda);
    Polyhedron gaussienMultipleFilter(const Polyhedron &P, float lambda, int nbIter);
}