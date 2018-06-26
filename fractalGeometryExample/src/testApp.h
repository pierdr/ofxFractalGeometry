#pragma once

#include "ofMain.h"
#include "ofxFractalGeometry.hpp"
#define NUM_FUNCTIONS 12

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int exampleIndex = 0;
    string functionNames[NUM_FUNCTIONS] = {"pointOnLine","pointAtAbsoluteAngle","pointAtRelativeAngle","perpendicularPoints","pointOnPlane","closestPointOnLineFromPoint","middlePoint","distanceBetweenTwoPoints","isRightTurn","getConvexHull","findEqualDetourPoint","convertPoint3DtoFake2D"};
		
};
