#include "taubin.hpp"
#include <iostream>

namespace geomAlgoLib
{
    Polyhedron taubinFilter(const Polyhedron &P, float lambda, float mu) 
    {

        Polyhedron filtered(P);

        Polyhedron shrunk = gaussienFilter(filtered, lambda);
        filtered = gaussienFilter(shrunk, mu);

        return filtered;
    }

    Polyhedron taubinMultipleFilter(const Polyhedron &P, float lambda, float mu, int nbIter)
    {
        Polyhedron mesh(P);
        for(int i = 0; i < nbIter; ++i)
        {
            mesh = taubinFilter(mesh, lambda, mu);
        }
        return mesh;
    }
}