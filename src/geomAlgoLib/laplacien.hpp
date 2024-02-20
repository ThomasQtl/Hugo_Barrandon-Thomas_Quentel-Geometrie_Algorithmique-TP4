#pragma once

#include "types.hpp"

namespace geomAlgoLib
{
    Polyhedron laplacienFilter(const Polyhedron &P);
    Polyhedron laplacienMultipleFilter(const Polyhedron &P, int nbIter);
}