#include "laplacien.hpp"
#include <iostream>
#include <CGAL/Polyhedron_3.h>

namespace geomAlgoLib
{
    Polyhedron laplacienFilter(const Polyhedron &P) 
    {

        Polyhedron filtered(P);

        Vertex_unconst_iterator vert_iter_filtered = filtered.vertices_begin();
        // Parcours des faces du polyèdre
        for (Vertex_iterator vert_iter = P.vertices_begin(); vert_iter != P.vertices_end(); ++vert_iter)
        {
            Vector3 sumVertex(0,0,0);
            auto halfedge = vert_iter->vertex_begin();
            auto firstElt = vert_iter->vertex_begin();
            int i = 0;
            do
            {
                auto p = halfedge->opposite()->vertex()->point();
                sumVertex += Vector3(p.x(), p.y(), p.z());
                ++i;
                ++halfedge;
            }while(halfedge != firstElt);
            sumVertex /= i;
            vert_iter_filtered->point() = Point3(sumVertex.x(), sumVertex.y(), sumVertex.z());
            ++vert_iter_filtered;
        }

        return filtered;
    }

    Polyhedron laplacienMultipleFilter(const Polyhedron &P, int nbIter)
    {
        Polyhedron mesh(P);
        for(int i = 0; i < nbIter; ++i)
        {
            mesh = laplacienFilter(mesh);
        }
        return mesh;
    }
}