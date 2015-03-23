

#include "UIObject.h"


void UIObject::init(string _name, float _w, float _h, float _padleft, float _padright, float _padbottom)
{
    enableMouseEvents();
    
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
    
    scale = 0.75f;
    
}

void UIObject::update(){

}

void UIObject::draw(int x, int y) {
    set(x,y, width*scale, height*scale);
    icon.draw(x,y,width * scale,height * scale);
}

void UIObject::onPress(int x, int y, int button)
{
    
    cout << "pressed " << name << " at " << x << " " << y << endl;
}
