

#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

class UIObject : public ofxMSAInteractiveObject {
	
public:
    UIObject(){};

    virtual void init(string name, float w, float h, float padleft, float padright, float padbottom);
    virtual void onPress(int x, int y, int button);
    virtual void update();
    virtual void draw(int x, int y);

    ofImage icon;
   
    string name;
    float width;
    float height;
    float padleft;
    float padright;
    float padbottom;
    float scale;
};


