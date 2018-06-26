//
//  PFractals.hpp
//  ofxFractalGeometry
//
//  Created by Pierluigi Dalla Rosa on 12/29/17.
//  www.pierdr.com
//

#ifndef ofxFractalGeometry_hpp
#define ofxFractalGeometry_hpp

#include <stdio.h>
#include "ofMain.h"

class ofxFractalGeometry{
public:
    ofxFractalGeometry();
    
    static ofPoint pointOnLine(ofPoint p0, ofPoint p1, float distance);
    static ofPoint pointAtAbsoluteAngle(ofPoint p0,float distance, float angle);
    static ofPoint pointAtRelativeAngle(ofPoint p0, ofPoint p1, float distance, float angle);
    static void    perpendicularPoints(ofPoint p0, ofPoint p1, ofPoint* endPoints, float distance);
    static ofPoint perpendicularPoint(ofPoint p0, ofPoint p1, ofPoint planePoint, float distance);
    static Boolean pointOnPlane(ofPoint p0, ofPoint p1, ofPoint planePoint, ofPoint targetPoint);
    static ofPoint closestPointOnLineFromPoint(ofPoint p0, ofPoint p1, ofPoint pT);
    static ofPoint middlePoint(ofPoint p0,ofPoint p1);
    static float distanceBetweenTwoPoints(ofPoint p0,ofPoint p1);
    //------
    static bool isRightTurn(ofPoint a, ofPoint b, ofPoint c);
    static vector<ofPoint> getConvexHull(vector<ofPoint> points);
    static ofPoint findEqualDetourPoint(ofPoint a, ofPoint b, ofPoint c);
    static ofPoint convertPoint3DtoFake2D(float x1, float y1, float z1);
    
    
    static void hello(){
        printf("\nhello\n");
    }
private:
    static bool lexicalComparison(const ofPoint& v1, const ofPoint& v2);
};
class gLine
{
public:
    ofPoint p0;
    ofPoint p1;
    ofColor c;
    
    gLine(ofPoint p0, ofPoint p1){
        this->p0 = p0;
        this->p1 = p1;
        this->c=ofColor(0,0,0);
    }
    gLine(ofPoint p0, ofPoint p1, ofColor c)
    {
        
        this->p0 = p0;
        this->p1 = p1;
        this->c=c;
    }
    gLine()
    {
        this->p0 = ofPoint(0,0);
        this->p1 = ofPoint(0,0);
        this->c  = ofColor(0,0,0);
    }
    void draw()
    {
        ofSetColor(this->c);
        ofDrawLine(this->p0,this->p1);
    }
};
class gCircle
{
public:
    float x;
    float y;
    float r;
    ofPoint c;
    ofColor color;
    
    gCircle(float x, float y, float r)
    {
        this->x = x;
        this->y = y;
        this->r = r;
        this->c.x = x;
        this->c.y = y;
    }
    gCircle(ofPoint c, float r)
    {
        this->x = c.x;
        this->y = c.y;
        this->r = r;
        this->c = c;
        
    }
    
    void draw(){
        
        ofDrawCircle(this->x, this->y, this->r);
    }
    vector<gLine>  drawWithResolution(int res)
    {
       // gLine l[res];
        vector<gLine> lines;
        for(int i = 0;i<res;i++)
        {
            
            lines.push_back( gLine(ofPoint((cos((TWO_PI/res)*(float)i)*this->r)+this->x,(sin((TWO_PI/(float)res)*(float)i)*this->r)+this->y),ofPoint((cos((TWO_PI/(float)res)*(float)((i<res-1)?i+1:0))*this->r)+this->x,(sin((TWO_PI/(float)res)*(float)((i<res-1)?i+1:0))*this->r)+this->y)));
            
//            l[i].draw();
            
        }
        
        return lines;
    }
};
#endif /* ofxFractalGeometry_hpp */
