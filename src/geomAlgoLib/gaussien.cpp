#include "gaussien.hpp"
#include <iostream>

namespace geomAlgoLib
{
    Polyhedron gaussienFilter(const Polyhedron &P, float lambda) 
    {

        Polyhedron filtered(P);

        Vertex_unconst_iterator vert_iter_filtered = filtered.vertices_begin();
        // Parcours des faces du polyèdre
        for (Vertex_iterator vert_iter = P.vertices_begin(); vert_iter != P.vertices_end(); ++vert_iter)
        {
            Vector3 centroide(0,0,0);
            auto halfedge = vert_iter->vertex_begin();
            auto firstElt = vert_iter->vertex_begin();
            int i = 0;
            do
            {
                auto p = halfedge->opposite()->vertex()->point();
                centroide += Vector3(p.x(), p.y(), p.z());
                ++i;
                ++halfedge;
            }while(halfedge != firstElt);
            centroide /= i;

            auto pi = vert_iter->point();
            Vector3 dpi = centroide - Vector3(pi.x(), pi.y(), pi.z());
            dpi *= lambda;
            vert_iter_filtered->point() = vert_iter_filtered->point() + dpi;
            ++vert_iter_filtered;
        }

        return filtered;
    }

    Polyhedron gaussienMultipleFilter(const Polyhedron &P, float lambda, int nbIter)
    {
        Polyhedron mesh(P);
        for(int i = 0; i < nbIter; ++i)
        {
            mesh = gaussienFilter(mesh, lambda);
        }
        return mesh;
    }
}