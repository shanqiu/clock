#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    radius=200;
    center.x=ofGetWidth()/2;
    center.y=ofGetHeight()/2;
    ofSetFrameRate(30);
    secStep=sec;
}

//--------------------------------------------------------------
void testApp::update(){
 currentSec=ofGetSeconds();
    currentMin=ofGetMinutes();
    currentHour=ofGetHours();
    cout << currentSec<< endl;
    cout << currentMin <<endl;
    cout << currentHour<<endl;


    min = ofMap(currentMin,0,60,0,360);
    if(currentHour>12){
        hour = ofMap(currentHour-12,0,12,0,360);
    }
    if (currentHour<12) {
        hour= ofMap(currentHour,0,12,0,360);
    }

     path.clear();
    path.setCircleResolution(120);
    path.setFilled(true);
    path.setFillColor(ofColor(0,0,0));
     if(min<hour){
         path.arc(center.x,center.y,radius,radius,min,hour);

      }
    else{
        path.circle(center.x, center.y, radius);
        path.close();
        path.setFillColor(0);
       path.arc(center.x,center.y,radius,radius,hour,min);
     }

    path.close();
    secPath.clear();
    secPath.setCircleResolution(120);
    secPath.setFilled(false);
    secPath.setStrokeColor(ofColor(0));
    secPath.setStrokeWidth(3);
    sec=ofMap(currentSec, 0, 60, 0, 360);
    secPath.arc(center.x, center.y, radius*1.2, radius*1.2, sec, secStep);
    secStep=secStep+180/15;
    if(secStep-sec>360){
        secStep=sec-360;
    }
    secPath.close();

}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotate(-90,0, 0, 1);
    //ofPushMatrix();
     path.draw(-ofGetWidth()/2,-ofGetHeight()/2);
    secPath.draw(-ofGetWidth()/2,-ofGetHeight()/2);
    //ofPopMatrix();
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
