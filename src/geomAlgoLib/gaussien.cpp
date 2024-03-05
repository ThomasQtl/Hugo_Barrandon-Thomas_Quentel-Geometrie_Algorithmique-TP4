#include "gaussien.hpp"
#include <iostream>

namespace geomAlgoLib
{
    Polyhedron gaussienFilter(const Polyhedron &P, float lambda) 
    {

        Polyhedron filtered(P);


        // Déplacement du sommet filtré selon la moyenne des positions des voisins
        /*auto vert_iter_filtered = filtered.vertices_begin();
        std::advance(vert_iter_filtered, std::distance(P.vertices_begin(), vert_iter));
        auto p1 = vert_iter_filtered->point();
        p1 = Point_3(p1.x() + sumVertex.x(), p1.y() + sumVertex.y(), p1.z() + sumVertex.z());
        */
        return filtered;
    }

    Polyhedron gaussienMultipleFilter(const Polyhedron &P, float lambda, int nbIter)
    {
        Polyhedron mesh(P);
        return mesh;
    }
}