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
    
    // Put in a slider that shows the values coming in from the modulators
    // Or maybe draw the JenOSC visualisers underneath the menu buttons in click down menu
    // That way you can see right there the data each one represents
    // Same for all the Mods so LFO's, Rordering... etc..
    
    void setup(int x, int y);
    void update();
    void draw();
    
    void initDestinations();
    void initModulators();
    
    /*-----ofxCDM objects----*/
//    void cmdEvent(ofxCDMEvent &ev);
    void cmdEvent(string &ev);
    //ofxCDMEvent cdmEvent;
    
    ofxClickDownMenu jenMenu;
    ofxClickDownMenu DestinationMenu;
    ofxClickDownMenu ModulatorMenu;
    
    ofxClickDownMenu playheads;
    ofxClickDownMenu instruments;

    ofxUICanvas *gui;
    void guiEvent(ofxUIEventArgs &e);
    
    // Desitnations
    vector<string> DestinationMenu_AVGS;
    vector<string> DestinationMenu_SHADER;
    vector<string> DestinationMenu_FM;
    
    // Modulators
    vector<string> ModulatorMenu_LFO;
    vector<string> instruments_JEN;
    vector<string> playheads_JEN;
    
    string destination;
    string modulator;
    
    // UI Menu
    UIMenu modMenu;
    UIMenu destMenu;
    
    //EVENTS
    void bModMenuPressed(bool & b);
    void bDestMenuPressed(bool & b);
    
    void bTest(string & b);
    
private:
    int xPos;
    int yPos;
    int padding;
    int menuWidth;
    
    float test;
};
