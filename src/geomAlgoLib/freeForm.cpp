#include "freeForm.hpp"
#include <iostream>

namespace geomAlgoLib
{
    BoundingBox::BoundingBox(const Polyhedron &P)
    {
        _poly = P;
        generateVertices();
        generateInfluances();
    }

    void BoundingBox::generateVertices()
    {
        Vertex_iterator vInit = _poly.vertices_begin();
        auto pInit = vInit->point();

        double mini[3] = {pInit.x(), pInit.y(), pInit.z()};
        double maxi[3] = {pInit.x(), pInit.y(), pInit.z()};


        for (Vertex_iterator vert_iter = _poly.vertices_begin(); vert_iter != _poly.vertices_end(); ++vert_iter)
        {            
            auto p = vert_iter->point();
            if(p.x() < mini[0]) mini[0] = p.x();
            if(p.y() < mini[1]) mini[1] = p.y();
            if(p.z() < mini[2]) mini[2] = p.z();

            if(maxi[0] < p.x()) maxi[0] = p.x();
            if(maxi[1] < p.y()) maxi[1] = p.y();
            if(maxi[2] < p.z()) maxi[2] = p.z();
        }

        _verteces[0] = Point3(mini[0], mini[1], mini[2]);
        _verteces[1] = Point3(mini[0], mini[1], maxi[2]);
        _verteces[2] = Point3(mini[0], maxi[1], mini[2]);
        _verteces[3] = Point3(mini[0], maxi[1], maxi[2]);
        _verteces[4] = Point3(maxi[0], mini[1], mini[2]);
        _verteces[5] = Point3(maxi[0], mini[1], maxi[2]);
        _verteces[6] = Point3(maxi[0], maxi[1], mini[2]);
        _verteces[7] = Point3(maxi[0], maxi[1], maxi[2]);
    }

    void BoundingBox::generateInfluances()
    {
        double dists[8];
        for (Vertex_iterator vert_iter = _poly.vertices_begin(); vert_iter != _poly.vertices_end(); ++vert_iter)
        {
            auto p = vert_iter->point();
            double sumDists = 0;
            for(int i = 0; i < 8; ++i)
            {
                dists[i] = CGAL::sqrt(CGAL::squared_distance(_verteces[i], p));
                sumDists += dists[i];
            }
            for(int i = 0; i < 8; ++i)
            {
                _influances[i].insert(*vert_iter, dists[i]/sumDists);
            }
        }
    }
}