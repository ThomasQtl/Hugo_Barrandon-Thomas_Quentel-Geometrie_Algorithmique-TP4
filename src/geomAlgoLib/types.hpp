#pragma once

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>

#include <map>
#include <typeinfo>

namespace geomAlgoLib
{
    using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
    using Polyhedron = CGAL::Polyhedron_3<Kernel>;

    using Facet_iterator = Polyhedron::Facet_const_iterator;
    using Vertex_iterator = Polyhedron::Vertex_const_iterator;
    using Vertex_unconst_iterator = Polyhedron::Vertex_iterator;
    using Halfedge_iterator = Polyhedron::Halfedge_const_iterator;
    using Halfedge_unconst_iterator = Polyhedron::Halfedge_iterator;
    using Halfedge_facet_circulator = Polyhedron::Halfedge_around_facet_const_circulator;
    using Vertex_handle = Polyhedron::Vertex_handle;

    using Facet_double_map = std::map<Polyhedron::Facet_const_handle, double>;
    using Facet_int_map = std::map<Polyhedron::Facet_const_handle, int>;

    using Vector3 = CGAL::Vector_3<Kernel>;
    using Point3 = CGAL::Point_3<Kernel>;

    using Influance_map = std::map<Vertex_handle, float>;
}