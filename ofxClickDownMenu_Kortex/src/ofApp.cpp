#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(40);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    brightness	= 0.8;
    size		= 0.8;
    shape		= SHAPE_RECT;
    
    destination = "";
    modulator   = "";

    initModulators();
    initDestinations();

    //Add Event Listener
    ofAddListener(ofxCDMEvent::MenuPressed, this, &ofApp::cmdEvent);
    
    // UI Menu
    uiMenu.init("test", 100, 30, 0 , 0, 0);
    ofAddListener(uiMenu.variablePressed, this, &ofApp::bMenuPressed);

}

//--------------------------------------------------------------
void ofApp::bMenuPressed(bool & b){
    cout << "CUUUUNNNTT" << endl;
    DestinationMenu.openMenu(uiMenu.getPosition().x,uiMenu.getPosition().y);

}

//--------------------------------------------------------------
void ofApp::initModulators(){
    /*-------------Define Menu Property-------------*/
    DestinationMenu.OnlyRightClick = false;
    DestinationMenu.menu_name = "modulatorMenu";
    
    //LFO Modulator Buttons Menu
    ModulatorMenu_LFO.push_back("LFO1");
    ModulatorMenu_LFO.push_back("LFO2");
    ModulatorMenu_LFO.push_back("LFO3");
    ModulatorMenu_LFO.push_back("LFO4");
    ModulatorMenu_LFO.push_back("LFO5");
    ModulatorMenu_LFO.push_back("REORDER1");
    ModulatorMenu_LFO.push_back("REORDER2");
    ModulatorMenu_LFO.push_back("REORDER3");
    ModulatorMenu.RegisterBranch("LFO", &ModulatorMenu_LFO);
    
    //JENIFER MAX Modulator Buttons Menu
    ModulatorMenu_JEN.push_back("Kick Vol");
    ModulatorMenu_JEN.push_back("Snare Vol");
    ModulatorMenu.RegisterBranch("SHADER", &ModulatorMenu_JEN);
}

//--------------------------------------------------------------
void ofApp::initDestinations(){
    /*-------------Define Menu Property-------------*/
    DestinationMenu.OnlyRightClick = false;
    DestinationMenu.menu_name = "destinationMenu";
    
    //AVGS Destination Buttons Menu
    DestinationMenu_AVGS.push_back("PlayPosition");
    DestinationMenu_AVGS.push_back("Speed");
    DestinationMenu_AVGS.push_back("Pitch");
    DestinationMenu_AVGS.push_back("GrainSize");
    DestinationMenu_AVGS.push_back("Overlaps");
    DestinationMenu.RegisterBranch("AVGS", &DestinationMenu_AVGS);
    
    //SHADER Destination Buttons Menu
    DestinationMenu_SHADER.push_back("Speed");
    DestinationMenu_SHADER.push_back("Width");
    DestinationMenu_SHADER.push_back("Division");
    DestinationMenu_SHADER.push_back("Alpha");
    DestinationMenu_SHADER.push_back("Glow");
    DestinationMenu.RegisterBranch("SHADER", &DestinationMenu_SHADER);
    
    //FM Destination Buttons Menu
    DestinationMenu_FM.push_back("CarrierFreq");
    DestinationMenu_FM.push_back("ModFreq");
    DestinationMenu_FM.push_back("ModIndex");
    DestinationMenu_FM.push_back("Cutoff");
    DestinationMenu_FM.push_back("Resonace");
    DestinationMenu_FM.push_back("Lfo1Speed");
    DestinationMenu_FM.push_back("Lfo1Amp");
    DestinationMenu_FM.push_back("Lfo2Speed");
    DestinationMenu_FM.push_back("Lfo2Amp");
    DestinationMenu_FM.push_back("Lfo3Speed");
    DestinationMenu_FM.push_back("Lfo3Amp");
    DestinationMenu.RegisterBranch("FM", &DestinationMenu_FM);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    ofSetHexColor(0xFFFFFF);
    ofDrawBitmapString("Click & open Menu Dialog.", 30,30);
    
    /*-------------Draw Menu-------------*/

    ofSetColor(255, 0, 25);
    ofNoFill();
    ofRect(300,300,100,30);
    ofFill();
    
    ofSetHexColor(0xFFFFFF);
    ofDrawBitmapString(destination, 308,320);
    
    DestinationMenu.draw();
    ModulatorMenu.draw();
    
    uiMenu.draw(300, 300);
    
}

//--------------------------------------------------------------
void ofApp::cmdEvent(ofxCDMEvent &ev){
    /*-------------Catch menu messages-------------*/
    for(int i = 0; i < DestinationMenu_AVGS.size(); i++){
        if(ev.message == "destinationMenu::AVGS::" + DestinationMenu_AVGS[i]) destination = DestinationMenu_AVGS[i];
    }
    for(int i = 0; i < DestinationMenu_SHADER.size(); i++){
        if(ev.message == "destinationMenu::SHADER::" + DestinationMenu_SHADER[i]) destination = DestinationMenu_SHADER[i];
    }
    for(int i = 0; i < DestinationMenu_FM.size(); i++){
        if(ev.message == "destinationMenu::FM::" + DestinationMenu_FM[i]) destination = DestinationMenu_FM[i];
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if( key == '1'){
        ModulatorMenu.openMenu(100, 100);
    } else if( key == '2'){
        DestinationMenu.openMenu(400, 100);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}