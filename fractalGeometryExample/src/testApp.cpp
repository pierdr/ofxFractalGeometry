#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetBackgroundColor(0, 0, 0);
    ofNoFill();
    ofSetLineWidth(2);
    ofSetColor(255, 255, 255);
    
    switch (exampleIndex) {
        case 0://pointOnLine
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(0,0);
            ofPoint p1 = ofPoint(100,0);
            float distance = mouseX/2;
            
            
            ofPoint pointOnLine = ofxFractalGeometry::pointOnLine(p0, p1, distance);
            ofDrawEllipse(p0,10,10);
            ofDrawEllipse(p1, 10, 10);
            ofDrawLine(p0, p1);
            ofSetColor(255, 255, 0);
            ofDrawEllipse(pointOnLine, 12, 12);
            ofDrawLine(p1,pointOnLine);
            ofPopMatrix();
            break;
        }
        case 1://pointAtAbsoluteAngle
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(0,0);
            float distance = 100;
            float angle = ofMap(mouseX/2,0,ofGetWidth()/2,0,TWO_PI);
            
            ofPoint pointAtAbsoluteAngle = ofxFractalGeometry::pointAtAbsoluteAngle(p0, distance,angle);
            ofDrawEllipse(p0,10,10);
            ofSetColor(255, 255, 0);
            ofDrawEllipse(pointAtAbsoluteAngle, 12, 12);
            ofDrawLine(p0,pointAtAbsoluteAngle);
            ofPopMatrix();
            break;
        }
        case 2://pointAtRelativeAngle
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(0,0);
            ofPoint p1 = ofPoint(100,50);
            float distance = 100;
            float angle = ofMap(mouseX/2,0,ofGetWidth()/2,0,TWO_PI);
            
            ofPoint pointAtRelativeAngle = ofxFractalGeometry::pointAtRelativeAngle(p0, p1, distance,angle);
            ofDrawEllipse(p0,10,10);
            ofDrawEllipse(p1, 10, 10);
            ofDrawLine(p0, p1);
            ofSetColor(255, 255, 0);
            ofDrawEllipse(pointAtRelativeAngle, 12, 12);
            ofDrawLine(p1,pointAtRelativeAngle);
            ofPopMatrix();
            break;
        }
        case 3://perpendicularPoints
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(0,0);
            ofPoint p1 = ofPoint(100,mouseX/4);
            ofPoint perpendicularPoints[2];
            float distance = 100;
            
            ofxFractalGeometry::perpendicularPoints(p0, p1, perpendicularPoints, distance);
            
            ofDrawEllipse(p0,10,10);
            ofDrawEllipse(p1, 10, 10);
            ofDrawLine(p0, p1);
            ofSetColor(255, 255, 0);
            ofDrawEllipse( (ofPoint)perpendicularPoints[0], 12, 12);
            ofDrawEllipse( (ofPoint)perpendicularPoints[1], 12, 12);
            ofDrawLine(p1, perpendicularPoints[0]);
            ofDrawLine(p1, perpendicularPoints[1]);
            ofPopMatrix();
            break;
        }
        case 4://pointOnPlane
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(-ofGetWidth()/2,-ofGetHeight()/2);
            ofPoint p1 = ofPoint(ofGetWidth()/2,mouseX/2);
            ofPoint targetPoint = ofPoint(200,0);
            ofPoint planePoint = ofPoint(50,50);
            
            Boolean b = ofxFractalGeometry::pointOnPlane(p0, p1, planePoint, targetPoint);
            ofSetBackgroundColor((b)?128:0);
                
            
            ofDrawEllipse(p0,10,10);
            ofDrawEllipse(p1, 10, 10);
            ofDrawLine(p0, p1);
            ofSetColor(0, 255, 255);
            ofDrawEllipse( planePoint , 12, 12);
            ofSetColor(255, 255, 0);
            ofDrawEllipse( targetPoint, 12, 12);
            
            ofPopMatrix();
            break;
        }
        case 5://closestPointOnLineFromPoint
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(-ofGetWidth()/4,-ofGetHeight()/4);
            ofPoint p1 = ofPoint(ofGetWidth()/4,mouseX/2);
            ofPoint pT = ofPoint(200,0);
            ofPoint closestPointOnLineFromPoint = ofxFractalGeometry::closestPointOnLineFromPoint(p0, p1, pT);
            ofDrawEllipse(p0,10,10);
            ofDrawEllipse(p1, 10, 10);
            ofDrawLine(p0, p1);
            ofDrawEllipse( pT , 12, 12);
            ofSetColor(255, 255, 0);
            ofDrawLine(pT, closestPointOnLineFromPoint);
            ofDrawEllipse( closestPointOnLineFromPoint, 12, 12);
            
            ofPopMatrix();
            break;
        }
        case 6://middlePoint
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(-ofGetWidth()/4,-mouseX/4);
            ofPoint p1 = ofPoint(ofGetWidth()/4,mouseX/2);
            
            ofPoint middlePoint = ofxFractalGeometry::middlePoint(p0, p1);
            ofDrawEllipse(p0,10,10);
            ofDrawEllipse(p1, 10, 10);
            
            
            ofSetColor(255, 255, 0);
            ofDrawLine(p0, middlePoint);
            ofDrawLine(p1,middlePoint);
            ofDrawEllipse( middlePoint, 12, 12);
            
            ofPopMatrix();
            break;
        }
        case 7://distanceBetweenTwoPoints
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(-ofGetWidth()/4,-mouseX/4);
            ofPoint p1 = ofPoint(ofGetWidth()/4,mouseX/2);
            
            float distance = ofxFractalGeometry::distanceBetweenTwoPoints(p0, p1);
            ofDrawEllipse(p0,10,10);
            ofDrawEllipse(p1, 10, 10);
            ofDrawLine(p0, p1);
            
            ofDrawBitmapString(ofToString(distance),ofxFractalGeometry::middlePoint(p0, p1));
            
            
            ofPopMatrix();
            break;
        }
        case 8://isRightTurn
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint a = ofPoint(-ofGetWidth()/4,0);
            ofPoint b = ofPoint(ofGetWidth()/4,0);
            ofPoint c = ofPoint((mouseX*0.75)-ofGetWidth()/4,(mouseX*0.75)-(ofGetHeight()/2));
            
            
            
            bool isRightTurn= ofxFractalGeometry::isRightTurn(a, b,c);
            
            ofSetBackgroundColor((isRightTurn)?128:0);
            ofDrawEllipse(a,10,10);
            ofDrawEllipse(b, 10, 10);
            ofDrawLine(a, b);
            
            ofSetColor(255, 255, 0);
            ofDrawLine(b, c);
        
            ofDrawEllipse( c, 12, 12);
        
            ofPopMatrix();
            break;
        }
        case 9://getConvexHull
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(-ofGetWidth()/8,mouseX/4);
            ofPoint p1 = ofPoint(-ofGetWidth()/4,mouseX/2);
            ofPoint p2 = ofPoint(10,100);
            ofPoint p3 = ofPoint(ofGetWidth()/4,mouseX/2);
            ofPoint p4 = ofPoint(ofGetWidth()/4,-mouseX/2);
            ofPoint p5 = ofPoint(0,mouseX/4);
            
            vector<ofPoint> points;
            points.push_back(p0);
            points.push_back(p1);
            points.push_back(p2);
            points.push_back(p3);
            points.push_back(p4);
            points.push_back(p5);
            
            for(int i =0; i<points.size();i++)
            {
                ofDrawEllipse(points[i],10,10);
            }
            
            vector<ofPoint> convexHull = ofxFractalGeometry::getConvexHull(points);
             ofSetColor(255, 255, 0);
            ofBeginShape();
            for(int i =0; i<convexHull.size();i++)
            {
                ofVertex(convexHull[i]);
            }
            ofEndShape();
            ofPopMatrix();
            break;
        }
        case 10://findEqualDetourPoint
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint a = ofPoint(-ofGetWidth()/4,0);
            ofPoint b = ofPoint(ofGetWidth()/4,0);
            ofPoint c = ofPoint(0,-50-mouseX/5);
            
            ofPoint findEqualDetourPoint = ofxFractalGeometry::findEqualDetourPoint(a, b, c);
            ofSetPolyMode(OF_POLY_WINDING_NONZERO);
            ofBeginShape();
            ofVertex(a);
            ofVertex(b);
            ofVertex(c);
            ofEndShape();
            
            ofSetColor(255, 255, 0);
            ofDrawEllipse( findEqualDetourPoint, 12, 12);
            
            ofPopMatrix();
            break;
        }
        case 11://convertPoint3DtoFake2D
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofPoint p0 = ofPoint(-100,0);
            ofPoint p1 = ofPoint(100,0);
            
            ofPoint p2 = ofPoint(100,200);
            ofPoint p3 = ofPoint(-100,200);
            
            ofPoint fake3dPoint0 = ofxFractalGeometry::convertPoint3DtoFake2D(p0.x,p0.y,mouseX/5);
             ofPoint fake3dPoint1 = ofxFractalGeometry::convertPoint3DtoFake2D(p1.x,p1.y,mouseX/5);
            
            ofPoint fake3dPoint2 = ofxFractalGeometry::convertPoint3DtoFake2D(p2.x,p2.y,mouseX/5);
            ofPoint fake3dPoint3 = ofxFractalGeometry::convertPoint3DtoFake2D(p3.x,p3.y,mouseX/5);
            
            ofDrawEllipse(p0,10,10);
            ofDrawEllipse(p1, 10, 10);
            ofDrawEllipse(p2,10,10);
            ofDrawEllipse(p3, 10, 10);
            
            ofDrawLine(p0,p1);
            ofDrawLine(p1,p2);
            ofDrawLine(p2,p3);
            ofDrawLine(p3,p0);
            
            ofSetColor(255, 255, 0,128);
            ofDrawEllipse( fake3dPoint0, 12, 12);
            ofDrawEllipse( fake3dPoint1, 12, 12);
            ofDrawEllipse( fake3dPoint2, 12, 12);
            ofDrawEllipse( fake3dPoint3, 12, 12);
            
            ofDrawLine(p0, fake3dPoint0);
            ofDrawLine(p1, fake3dPoint1);
            ofDrawLine(p2, fake3dPoint2);
            ofDrawLine(p3, fake3dPoint3);
            
            ofDrawLine(fake3dPoint0,fake3dPoint1);
            ofDrawLine(fake3dPoint1,fake3dPoint2);
            ofDrawLine(fake3dPoint2,fake3dPoint3);
            ofDrawLine(fake3dPoint3,fake3dPoint0);
            
            ofPopMatrix();
            break;
        }
        default:
            break;
    }
    
    ofSetColor(255);
    ofDrawBitmapString("Use the arrow keys left and right to explore the functions", 10, 20);
    ofDrawBitmapString("The current function is "+functionNames[exampleIndex], 10, 40);
    ofDrawBitmapString("ofxFractalGeometry example", 10, ofGetHeight()-20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == OF_KEY_RIGHT)
    {
        exampleIndex += (exampleIndex>NUM_FUNCTIONS-2)?0:1;
    }
    else if(key==OF_KEY_LEFT){
        exampleIndex -= (exampleIndex<=0)?0:1;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
