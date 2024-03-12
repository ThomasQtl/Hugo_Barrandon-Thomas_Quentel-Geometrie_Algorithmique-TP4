#include <io.hpp>
#include <lissage.hpp>
#include <example.hpp>
#include <freeForm.hpp>


#include <map>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using DistoMap = std::map<int, geomAlgoLib::Vector3>;

const DistoMap readDistoMap()
{
    std::ifstream infile("../disto.txt");
    DistoMap m;
    int edge;
    float x, y, z;

    for(int i = 0; i < 8;  ++i)
    {
        m.insert(std::make_pair(i, geomAlgoLib::Vector3(0,0,0)));
    } 

    while (infile >> edge >> x >> y >> z)
    {
        m[edge] += geomAlgoLib::Vector3(x,y,z);
    }

    return m;
}



int main(int argc, char *argv[]){

    std::cout << "Hello !" << std::endl;

    if(argc < 2){
        throw std::invalid_argument("Missing path as argument 1\n");
    }

    if(argc < 3){
        throw std::invalid_argument("Missing command as argument 2 : \n 0 : laplacien \n 1 : gaussien \n 2 : taubin \n 3 : BoundingBox + distortion\n");
    }

    const std::string meshPath = std::string{argv[1]};
    
    geomAlgoLib::Polyhedron myMesh;

    geomAlgoLib::readOFF(meshPath, myMesh);

    int choice = atoi(argv[2]);

    geomAlgoLib::Polyhedron result;

    if(choice < 3)
    {
        int nbIter = 1;
        float lambda = 0.33;
        float mu = -0.34;
        if(argc > 3)
        {
            nbIter = atoi(argv[3]);
        }
        if(argc > 4)
        {
            lambda = atof(argv[4]);
        }
        if(argc > 5)
        {
            mu = atof(argv[5]);
        }
        
        switch ( choice )
        {
            case 0:
                std::cout << "Choix : Laplacien" << std::endl;
                result = geomAlgoLib::laplacien(myMesh, nbIter);
                break;
            case 1:
                std::cout << "Choix : Gaussien" << std::endl;
                result = geomAlgoLib::gaussien(myMesh, nbIter, lambda);
                break;
            case 2:
                std::cout << "Choix : Taubin" << std::endl;
                result = geomAlgoLib::taubin(myMesh, nbIter, lambda, mu);
                break;
        }
    }
    if(choice == 3)
    {
        std::cout << "Choix : BoundingBox" << std::endl;
        geomAlgoLib::BoundingBox bb(myMesh);

        DistoMap distoMap = readDistoMap();

        for (const auto& [key, value] : distoMap)
        {
            if(value != geomAlgoLib::Vector3(0,0,0))
                bb.distortion(key, value);
        }

        result = bb.getPolyhedron();
    }

    geomAlgoLib::writeOFF(result,"../output.off");

    const char* command = "meshlab ../output.off";

    int cmdResult = system(command);

    return 0;
}