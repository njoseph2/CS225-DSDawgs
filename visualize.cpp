#include "visualize.h"

// Prototype - limited testing conducted for this function
cs225::PNG FDG::visualize()
 {
    int width = 100;
    int height = 100;
    cs225::PNG p(width,height);
    for(int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            p.getPixel(i,j) = HSLAPixel(0,0,100);
        }
    }

    for(unsigned i = 0; i < nodes.size(); i++){
        double dx = 10.0*nodes[i].x;
        double dy = 10.0*nodes[i].y;
        std::cout << dx << " and " << dy << std::endl;

        int initX = rand()%width;
        int initY = rand()%height;
        std::cout << initX << " and " << initY << std::endl;
        //plot node 
        updatePositions();
        int num = rand() % 255;
        HSLAPixel color(num,num,num);
        p.getPixel(initX, initY) = color;
        p.getPixel(initX+1, initY) = color;
        p.getPixel(initX-1, initY) = color;
        p.getPixel(initX+1, initY+1) = color;
        p.getPixel(initX-1, initY+1) = color;
        p.getPixel(initX-1, initY-1) = color;
        p.getPixel(initX+1, initY-1) = color;
        p.getPixel(initX, initY-1) = color;
        p.getPixel(initX, initY+1) = color;

        int iters = 0;
        for (unsigned j = 0; j < nodes[i].neighbors.size(); j++){
            double destX = 100.0*nodes[j].x;
            double destY = 100.0*nodes[j].y;

            int neighborX = int(destX);
            int neighborY = int(destY);

            int currX = initX;
            int currY = initY;
            while (currX != destX){
                int diffY = neighborY-initY;
                double diffX = neighborX-initX;
                double slope = 10.0 * diffY/diffX;

                currY += slope;
                currX = currY/slope;
                //color pixel at this position to black to represent edge;
                if (iters != 0){
                    p.getPixel(currX,currY) = HSLAPixel(0,0,0);
                }
                iters++;
            }
        }
    }
    p.writeToFile("out.png");
    return p;

 }
