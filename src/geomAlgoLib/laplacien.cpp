#include "laplacien.hpp"
#include <iostream>

namespace geomAlgoLib
{
    Polyhedron laplacienFilter(const Polyhedron &P) 
    {

        Polyhedron filtered(P);

        Vertex_iterator vert_iter_filtered = filtered.vertices_begin();
        // Parcours des faces du polyèdre
        for (Vertex_iterator vert_iter = P.vertices_begin(); vert_iter != P.vertices_end(); ++vert_iter)
        {
            Vector3 sumVertex(0,0,0);
            auto halfedge = vert_iter->vertex_begin();
            auto firstElt = vert_iter->vertex_begin();
            int i = 1;
            halfedge++;
            while(halfedge != firstElt)
            {
                auto p = halfedge->vertex()->point();
                sumVertex += Vector3(p.x(), p.y(), p.z());
                ++i;
                ++halfedge;
            }
            //std::cout << sumVertex.x() << " " << sumVertex.y() << " " << sumVertex.z() << std::endl;
            sumVertex /= i;
            auto p1 = vert_iter_filtered->point();
            p1 += sumVertex;
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