#pragma once

#include "ofMain.h"
//#include "InteractiveMenu.h"

#include "ofxMenu.h"

class ofApp : public ofBaseApp{

	public:

    ofApp(): modulatorMenu("ModMenu") {}

    void setup();
    void update();
    void draw();
    
    void initDestinations();
    void initModulators();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //vector<InteractiveMenu*> menus;
    
    ofxMenu modulatorMenu;
};
