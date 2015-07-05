//
//  UIMenu.cpp
//  ofxClickDownMenu_example
//
//  Created by Joshua Batty on 23/03/2015.
//
//

#include "UIMenu.h"

void UIMenu::init(string _name, float _w, float _h, float _padleft, float _padright, float _padbottom)
{
    enableMouseEvents();
    bSliderOpen = false;
    bPressed = false;
    xPos = 0;
    
    name = _name;
    width = _w;
    height = _h;
    padleft = _padleft;
    padright = _padright;
    padbottom = _padbottom;
    
    if(icon.loadImage(name+".png")) {
        ofLogNotice("layout") << "loading " + name + ".png";
    } else {
        ofLogError("UIObject") << "Failed to load icon: " << name;
    }
    
    scale = 1.0;
    
}

void UIMenu::update(){
//    if(tween.isRunning()){
//        variableTweenPosition = (variableTweenOffset - sliderH)+tween.update();
//    } else if(tween.isCompleted()){
//        if(bTweenSwitch == true){
//            bPressed = false;
//            bTweenSwitch = false;
//        } else if(bPressed == true) {
//            bTweenSwitch = true;
//        }
//    }
//    
//    slider.setPosition(sliderX, ofGetHeight()-variableTweenPosition);//ofGetHeight()+variableTweenPosition);
//    
}

void UIMenu::draw(int x, int y) {
    xPos = x;
//    sliderX = xPos-(width*0.65);
    set(x,y, width*scale, height*scale);
   // icon.draw(x,y,width * scale,height * scale);
    
    ofNoFill();
    ofSetColor(255);
    ofRect(x,y,width * scale,height * scale);
    ofFill();
}

bool UIMenu::isSliderOpen(){
    return bSliderOpen;
}

void UIMenu::onPress(int x, int y, int button)
{
    bPressed = true;
    
    cout << "VARIABLE pressed " << name << " at " << x << " " << y << endl;
    
    ofNotifyEvent(variablePressed, bPressed, this);
}
