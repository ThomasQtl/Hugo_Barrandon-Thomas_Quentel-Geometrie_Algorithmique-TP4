#include "lissage.hpp"

namespace geomAlgoLib
{
    Polyhedron lissage(const Polyhedron &P, float lambda, float mu) 
    {

        Polyhedron filtered(P);

        Vertex_unconst_iterator vert_iter_filtered = filtered.vertices_begin();

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

            vert_iter_filtered->point() = vert_iter_filtered->point() + dpi * lambda;
            vert_iter_filtered->point() = vert_iter_filtered->point() + dpi * mu;

            ++vert_iter_filtered;
        }

        return filtered;
    }

    Polyhedron laplacien(const Polyhedron &P, int nbIter)
    {
        Polyhedron mesh(P);
        for(int i = 0; i < nbIter; ++i)
        {
            mesh = lissage(mesh,1,0);
        }
        return mesh;
    }

    Polyhedron gaussien(const Polyhedron &P, int nbIter, float lambda)
    {
        Polyhedron mesh(P);
        for(int i = 0; i < nbIter; ++i)
        {
            mesh = lissage(mesh, lambda, 0);
        }
        return mesh;
    }


    Polyhedron taubin(const Polyhedron &P,  int nbIter, float lambda, float mu)
    {
        Polyhedron mesh(P);
        for(int i = 0; i < nbIter; ++i)
        {
            mesh = lissage(mesh, lambda, mu);
        }
        return mesh;
    }
}