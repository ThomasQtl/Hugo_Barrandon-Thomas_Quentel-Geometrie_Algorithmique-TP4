#pragma once

#include "types.hpp"


namespace geomAlgoLib
{
    class BoundingBox
    {
        private:
            Polyhedron _poly;
            Point3 _verteces[8];
            Influance_map _influances[8];

            void generateVertices();
            void generateInfluances();

        public:
            BoundingBox(const Polyhedron &P);
    };
}