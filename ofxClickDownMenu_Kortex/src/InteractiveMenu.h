//
//  InteractiveMenu.h
//  ofxClickDownMenu_example
//
//  Created by Joshua Batty on 25/03/2015.
//
//

#pragma once

#include "ofMain.h"
#include "ofxClickDownMenu.h"
#include "UIMenu.h"
#include "ofxUI.h"

class InteractiveMenu{
    
public:
    
    void setup(int x, int y);
    void update();
    void draw();
    
    void initDestinations();
    void initModulators();
    
    /*-----ofxCDM objects----*/
    void cmdEvent(ofxCDMEvent &ev);
    ofxClickDownMenu DestinationMenu;
    ofxClickDownMenu ModulatorMenu;
    
    ofxUISuperCanvas *gui;
    void guiEvent(ofxUIEventArgs &e);
    
    // Desitnations
    vector<string> DestinationMenu_AVGS;
    vector<string> DestinationMenu_SHADER;
    vector<string> DestinationMenu_FM;
    
    // Modulators
    vector<string> ModulatorMenu_LFO;
    vector<string> ModulatorMenu_JEN;
    
    string destination;
    string modulator;
    
    // UI Menu
    UIMenu modMenu;
    UIMenu destMenu;
    
    //EVENTS
    void bModMenuPressed(bool & b);
    void bDestMenuPressed(bool & b);
    
private:
    int xPos;
    int yPos;
    int padding;
};
