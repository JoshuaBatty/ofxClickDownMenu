#pragma once

#include "ofMain.h"
#include "ofxClickDownMenu.h"

#define SHAPE_RECT 0
#define SHAPE_CIRCLE 1
#define SHAPE_TRIANGLE 2

class ofApp : public ofBaseApp{

	public:

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
    
    /*-----ofxCDM objects----*/
    void cmdEvent(ofxCDMEvent &ev);
    ofxClickDownMenu DestinationMenu;
    ofxClickDownMenu ModulatorMenu;
    
    ofColor col;
    int shape;
    float brightness;
    float size;
    
    // Desitnations
    vector<string> DestinationMenu_AVGS;
    vector<string> DestinationMenu_SHADER;
    vector<string> DestinationMenu_FM;

    // Modulators
    vector<string> ModulatorMenu_LFO;
    vector<string> ModulatorMenu_JEN;
    
    string destination;
    string modulator;
};
