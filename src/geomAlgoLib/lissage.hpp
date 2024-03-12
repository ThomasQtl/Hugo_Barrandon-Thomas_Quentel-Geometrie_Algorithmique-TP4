#pragma once

#include "types.hpp"

namespace geomAlgoLib
{
    Polyhedron lissage(const Polyhedron &P, float lambda, float mu);
    Polyhedron laplacien(const Polyhedron &P, int nbIter);
    Polyhedron gaussien(const Polyhedron &P, int nbIter, float lambda);
    Polyhedron taubin(const Polyhedron &P,  int nbIter, float lambda, float mu);
}