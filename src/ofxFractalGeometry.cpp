//
//  
//  ofxFractalGeometry
//
//  Created by Pierluigi Dalla Rosa on 12/29/17.
//  www.pierdr.com
//

#include "ofxFractalGeometry.hpp"


ofPoint ofxFractalGeometry::pointOnLine(ofPoint p0, ofPoint p1, float distance){
    
    float oDist = sqrt(pow((p1.x-p0.x),2)+pow((p1.y-p0.y),2));
    float b1 = (p1.x-p0.x);
    float a1 = (p1.y-p0.y);
    
    float xN10 = p1.x + (b1*distance)/oDist;
    float yN10 = p1.y + (a1*distance)/oDist;
    return ofPoint(xN10,yN10);
}
ofPoint ofxFractalGeometry::pointAtAbsoluteAngle(ofPoint p0,float distance, float angle){
    return  ofPoint(p0.x+(sin(angle)*distance),p0.y+(cos(angle)*distance));
}
ofPoint ofxFractalGeometry::pointAtRelativeAngle(ofPoint p0, ofPoint p1, float distance, float angle){
    float xDiff = p0.x - p1.x;
    float yDiff = p0.y - p1.y;
    float angle1 =  (float)atan2(yDiff, xDiff);
    
    angle = angle-angle1+(PI/2);
    return ofxFractalGeometry::pointAtAbsoluteAngle(p1, distance, angle);

    
}
void ofxFractalGeometry::perpendicularPoints(ofPoint p0, ofPoint p1,ofPoint* endPoints, float distance){

    float oDist = sqrt(pow(p1.x-p0.x,2)+pow(p1.y-p0.y,2));
    float b1 = p1.x-p0.x;
    float a1 = p1.y-p0.y;
    
    float xN1 = p1.x - (a1*distance)/oDist;
    float yN1 = p1.y + (b1*distance)/oDist;
    
    endPoints[0] = ofPoint(xN1,yN1);
    float xN2 = p1.x + (a1*distance)/oDist;
    float yN2 = p1.y - (b1*distance)/oDist;
    endPoints[1] = ofPoint(xN2,yN2);
    
}
ofPoint ofxFractalGeometry::perpendicularPoint(ofPoint p0, ofPoint p1, ofPoint planePoint, float distance){
    ofPoint endPoints[2];
    ofxFractalGeometry::perpendicularPoints(p0,p1,endPoints,distance);
    if(ofxFractalGeometry::pointOnPlane(p0, p1, planePoint,endPoints[0]))
    {
        return endPoints[1];
    }
    else
    {
        return endPoints[0];
    }
}
bool ofxFractalGeometry::pointOnPlane(ofPoint p0, ofPoint p1, ofPoint planePoint, ofPoint targetPoint){
    ofPoint pPlaneOnLine = ofxFractalGeometry::closestPointOnLineFromPoint(p0, p1, planePoint);
    ofPoint pTargetOnLine= ofxFractalGeometry::closestPointOnLineFromPoint(p0, p1, targetPoint);
    float pPlaneX = pPlaneOnLine.x-planePoint.x;
    float pPlaneY = pPlaneOnLine.y-planePoint.y;
    float pTargetX = pTargetOnLine.x - targetPoint.x;
    float pTargetY = pTargetOnLine.y - targetPoint.y;
    
    if( ((pPlaneX*pTargetX)>=0 && (pPlaneY*pTargetY)>=0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
ofPoint ofxFractalGeometry::closestPointOnLineFromPoint(ofPoint p0, ofPoint p1, ofPoint pT){
  
        double m = (double)(p1.y - p0.y) / (p1.x - p0.x);
        double b = (double)p0.y - (m * p0.x);
        
        double x = (m * pT.y + pT.x - m * b) / (m * m + 1);
        double y = (m * m * pT.y + m * pT.x + b) / (m * m + 1);
        
        return ofPoint(x, y);
}

ofPoint ofxFractalGeometry::middlePoint(ofPoint p0,ofPoint p1){
    return ofPoint((p0.x+p1.x)/2,(p0.y+p1.y)/2);
}

float ofxFractalGeometry::distanceBetweenTwoPoints(ofPoint p0,ofPoint p1)
{
    return sqrt(pow(p1.x-p0.x,2)+pow(p1.y-p0.y,2));
}

bool ofxFractalGeometry::isRightTurn(ofPoint a, ofPoint b, ofPoint c) {
    // use the cross product to determin if we have a right turn
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) > 0;
}

bool ofxFractalGeometry::lexicalComparison(const ofPoint& v1, const ofPoint& v2) {
    if (v1.x > v2.x) return true;
    else if (v1.x < v2.x) return false;
    else if (v1.y > v2.y) return true;
    else return false;
}
ofPoint ofxFractalGeometry::findEqualDetourPoint(ofPoint a,ofPoint b, ofPoint c){

    float x = ((pow(a.x,2)*b.y)-(pow(a.x,2)*c.y)+(pow(a.y,2)*b.y)-(pow(a.y,2)*c.y)-(a.y*pow(b.x,2))-(a.y*pow(b.y,2))+(a.y*pow(c.x,2))+(a.y*pow(c.y,2))+(pow(b.x,2)*c.y)+(pow(b.y,2)*c.y)-(b.y*pow(c.x,2))-(b.y*pow(c.y,2)))/(2*(a.x-c.x)*(b.y-c.y));
   
    float a1S = -2 * (b.x - c.x);
    float b1S = -2 * (b.y - c.y);
    
    float y = (pow(a.x,2)*b.x-pow(a.x,2)*c.x-a.x*pow(b.x,2)-a.x*pow(b.y,2)+a.x*pow(c.x,2)+a.x*pow(c.y,2)+pow(a.y,2)*b.x-pow(a.y,2)*c.x+pow(b.x,2)*c.x-b.x*pow(c.x,2)-b.x*pow(c.y,2)+pow(b.y,2)*c.x)/(2*(-a.x*b.y+a.x*c.y+a.y*b.x-a.y*c.x-b.x*c.y+b.y*c.x));

    return ofPoint(x,y);
}
vector<ofPoint> ofxFractalGeometry::getConvexHull(vector<ofPoint> points) {
    sort(points.begin(), points.end(), ofxFractalGeometry::lexicalComparison);
    
    vector<ofPoint> hull;

    ofPoint h1,h2,h3;
    
    hull.push_back(points.at(0));
    hull.push_back(points.at(1));
    
    int currentPoint = 2;
    int direction = 1;
    
    for (int i=0; i<3000; i++) { //max 3000 tries
        
        hull.push_back(points.at(currentPoint));
        
        // look at the turn direction in the last three points
        h1 = hull.at(hull.size()-3);
        h2 = hull.at(hull.size()-2);
        h3 = hull.at(hull.size()-1);
        
        // while there are more than two points in the hull
        // and the last three points do not make a right turn
        while (!isRightTurn(h1, h2, h3) && hull.size() > 2) {
            
            // remove the middle of the last three points
            hull.erase(hull.end() - 2);
            
            if (hull.size() >= 3) {
                h1 = hull.at(hull.size()-3);
            }
            h2 = hull.at(hull.size()-2);
            h3 = hull.at(hull.size()-1);
        }
        
        // going through left-to-right calculates the top hull
        // when we get to the end, we reverse direction
        // and go back again right-to-left to calculate the bottom hull
        if (currentPoint == points.size() -1 || currentPoint == 0) {
            direction = direction * -1;
        }
        
        currentPoint+= direction;
        
        if (hull.front()==hull.back()) break;
    }
    
    return hull;
}
ofPoint ofxFractalGeometry::convertPoint3DtoFake2D(float x1, float y1, float z1)
{
    return pointAtAbsoluteAngle(ofPoint(x1,y1), - z1, PI/8);
}
ofPoint ofxFractalGeometrypointBetweenTwoPointsWithPercentage(ofPoint p0,ofPoint p1,float percentage){
    return ofPoint(((p0.x*(1-percentage))+(p1.x*(percentage)))/2,(p0.y*(1-percentage)+p1.y*percentage)/2);
}

