//
//  UIMenu.h
//  ofxClickDownMenu_example
//
//  Created by Joshua Batty on 23/03/2015.
//
//

#pragma once

#include "ofMain.h"
#include "UIObject.h"

class UIMenu : public UIObject {
public:
    
    UIMenu(){};
    void init(string name, float w, float h, float padleft, float padright, float padbottom);
    void onPress(int x, int y, int button);
    void update();
    void draw(int x, int y);
    
    bool bPressed;

    ofEvent<bool> variablePressed;
    bool isSliderOpen();
    bool bSliderOpen;
    int xPos;

};