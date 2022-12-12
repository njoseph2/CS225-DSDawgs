#include <visualize.h>

 cs225::PNG FDG::visualize()
 {
    cs225::PNG p;
    
    for(unsigned i = 0; i < nodes.size(); i++){
        double initX = nodes[i].x;
        double initY = nodes[i].y;
        //plot node 
        for (unsigned j = 0; j < neighbors.size(); j++){
            double destX = nodes[j].x;
            double destY = nodes[j].y;

            double currX = initX;
            double currY = initY;
            while (currX != destX){
                double diffY = destY-initY;
                double diffX = destX-initX;
                double slope = diffY/diffX;

                currY += slope;
                currX = currY/slope;
                //color pixel at this position to black to represent edge;
            }
        }
    }

    return p;

 }