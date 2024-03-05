#include <io.hpp>
#include <laplacien.hpp>
#include <gaussien.hpp>
#include <taubin.hpp>
#include <example.hpp>

#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[]){

    std::cout << "Hello !" << std::endl;

    if(argc < 3){
        throw std::invalid_argument("This program expects at least 2 argument (path to a mesh and nb inter).");
    }

    const std::string meshPath = std::string{argv[1]};
    
    geomAlgoLib::Polyhedron myMesh;

    geomAlgoLib::readOFF(meshPath, myMesh);

/*
    auto genus = geomAlgoLib::computeGenus(myMesh);
    std::cout << "The Genus of [" << meshPath << "] is = " << std::to_string(genus) << std::endl;

    geomAlgoLib::writeOFF(myMesh,"output.off");

    std::cout << "The end..." << std::endl;
    */

    int nbIter = atoi(argv[2]);

    /*
    geomAlgoLib::Polyhedron other = geomAlgoLib::gaussienMultipleFilter(myMesh, 0.33, 1);
    geomAlgoLib::writeOFF(other,"output-g.off");*/

    //geomAlgoLib::Polyhedron other = geomAlgoLib::laplacienMultipleFilter(myMesh, 50);
    geomAlgoLib::Polyhedron other = geomAlgoLib::taubinMultipleFilter(myMesh, 0.33, -0.34, nbIter);
    geomAlgoLib::writeOFF(other,"output-t.off");

    return 0;
}