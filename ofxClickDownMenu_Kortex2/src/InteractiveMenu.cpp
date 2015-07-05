//
//  InteractiveMenu.cpp
//  ofxClickDownMenu_example
//
//  Created by Joshua Batty on 25/03/2015.
//
//

#include "InteractiveMenu.h"

//--------------------------------------------------------------
void InteractiveMenu::setup(int x, int y){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(40);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    xPos = x;
    yPos = y;
    padding = 200;
    menuWidth = 100;
    
    destination = "";
    modulator   = "";
    
    initDestinations();
    
    //Add Event Listener
    //ofAddListener(ofxCDMEvent::MenuPressed, this, &InteractiveMenu::cmdEvent);
   
   // ofAddListener(DestinationMenu.MenuPressed, this, &InteractiveMenu::cmdEvent);
   // ofAddListener(ModulatorMenu.MenuPressed, this, &InteractiveMenu::cmdEvent);

   
    // UI Menu
    modMenu.init("mod test", menuWidth, 30, 0 , 0, 0);
    destMenu.init("dest test", menuWidth, 30, 0 , 0, 0);

    ofAddListener(modMenu.variablePressed, this, &InteractiveMenu::bModMenuPressed);
    ofAddListener(destMenu.variablePressed, this, &InteractiveMenu::bDestMenuPressed);
    
    // LFOS
    ofxMenu lfos("LFOS");
    lfos.addButton("LFO1");
    lfos.addButton("LFO2");
    lfos.addButton("LFO3");
    lfos.addButton("LFO4");
    lfos.addButton("LFO5");
    lfos.addButton("REORDER1");
    lfos.addButton("REORDER2");
    lfos.addButton("REORDER3");
    
    // Jen Instruments
    ofxMenu instruments("Instruments");
    instruments.addButton("Kick Amp");
    instruments.addButton("Kick Pan");
    instruments.addButton("Snare Amp");
    instruments.addButton("Snare Pan");
    instruments.addButton("Ride Amp");
    instruments.addButton("Ride Pan");
    instruments.addButton("Ghost Amp");
    instruments.addButton("Ghost Pan");
    
    // Jen Playheads
    ofxMenu playheads("Playheads");
    playheads.addButton("Song");
    playheads.addButton("Part");
    playheads.addButton("Segment");
    playheads.addButton("Bar");
    playheads.addButton("Minim");
    playheads.addButton("Beat");
    playheads.addButton("Quaver");
    playheads.addButton("SemiQuaver");

    // Jen Type
    ofxMenu jen("JEN");
    jen.addMenu(instruments);
    jen.addMenu(playheads);
    
    modulatorMenu.addMenu(jen);
    modulatorMenu.addMenu(lfos);

    // ofxUI
    gui = new ofxUICanvas();
    gui->init(xPos+menuWidth, yPos, padding/2, 30);

    gui->addRangeSlider("Range", 0.0, 1.0, 0.0, 1.0, menuWidth-10, 30-8);

//    gui->setAutoDraw(false);
    gui->disableAppDrawCallback();

    gui->setVisible(true);
    

}

//--------------------------------------------------------------
void InteractiveMenu::bTest(string & b){
    cout << "SLUT BAG " << endl;
}

//--------------------------------------------------------------
void InteractiveMenu::bModMenuPressed(bool & b){
  //  if(ModulatorMenu.getIsActive() == false){
  //      ModulatorMenu.openMenu(modMenu.getBottomLeft().x,modMenu.getBottomLeft().y);
  //  }
    modulatorMenu.openByClick(modMenu.getBottomLeft().x, modMenu.getBottomLeft().y);
    cout << "im in mod " << endl;
}

//--------------------------------------------------------------
void InteractiveMenu::bDestMenuPressed(bool & b){
 //   if(DestinationMenu.getIsActive() == false){
 //       DestinationMenu.openMenu(destMenu.getBottomLeft().x,destMenu.getBottomLeft().y);
 //   }
    cout << "im in dest " << endl;
}


//--------------------------------------------------------------
void InteractiveMenu::initDestinations(){
//    /*-------------Define Menu Property-------------*/
//    DestinationMenu.OnlyRightClick = false;
//    DestinationMenu.menu_name = "destinationMenu";
//    
//    //AVGS Destination Buttons Menu
//    DestinationMenu_AVGS.push_back("PlayPosition");
//    DestinationMenu_AVGS.push_back("Speed");
//    DestinationMenu_AVGS.push_back("Pitch");
//    DestinationMenu_AVGS.push_back("GrainSize");
//    DestinationMenu_AVGS.push_back("Overlaps");
//    DestinationMenu.RegisterBranch("AVGS", &DestinationMenu_AVGS);
//    
//    //SHADER Destination Buttons Menu
//    DestinationMenu_SHADER.push_back("Speed");
//    DestinationMenu_SHADER.push_back("Width");
//    DestinationMenu_SHADER.push_back("Division");
//    DestinationMenu_SHADER.push_back("Alpha");
//    DestinationMenu_SHADER.push_back("Glow");
//    DestinationMenu.RegisterBranch("SHADER", &DestinationMenu_SHADER);
//    
//    //FM Destination Buttons Menu
//    DestinationMenu_FM.push_back("CarrierFreq");
//    DestinationMenu_FM.push_back("ModFreq");
//    DestinationMenu_FM.push_back("ModIndex");
//    DestinationMenu_FM.push_back("Cutoff");
//    DestinationMenu_FM.push_back("Resonace");
//    DestinationMenu_FM.push_back("Lfo1Speed");
//    DestinationMenu_FM.push_back("Lfo1Amp");
//    DestinationMenu_FM.push_back("Lfo2Speed");
//    DestinationMenu_FM.push_back("Lfo2Amp");
//    DestinationMenu_FM.push_back("Lfo3Speed");
//    DestinationMenu_FM.push_back("Lfo3Amp");
//    DestinationMenu.RegisterBranch("FM", &DestinationMenu_FM);
//    
}

//--------------------------------------------------------------
void InteractiveMenu::update(){
    
}

//--------------------------------------------------------------
void InteractiveMenu::draw(){

    // Draw GUI Up here so it can be drawn over!
    gui->draw();
    
    ofSetColor(255,100,10);
    ofDrawBitmapString("Dest", xPos, yPos - 5);
    ofDrawBitmapString("Mod", xPos+padding, yPos - 5);
 
    /*-------------Draw Dest Menu-------------*/
    ofSetColor(255, 0, 25);
    ofNoFill();
    ofRect(xPos, yPos, 100,30);
    ofFill();
    
    ofSetHexColor(0xFFFFFF);
    ofDrawBitmapString(destination, xPos+8,yPos+20);
    
    /*-------------Draw Mod Menu-------------*/
    ofSetColor(255, 0, 25);
    ofNoFill();
    ofRect(xPos + padding, yPos, 100,30);
    ofFill();
    
    ofSetHexColor(0xFFFFFF);
    ofDrawBitmapString(modulator, xPos+padding+8,yPos+20);
    
   // destMenu.draw(xPos, yPos);
    modMenu.draw(xPos + padding, yPos);
    
   // DestinationMenu.draw();
    modulatorMenu.draw();

//    ofSetColor(0);
//    ofRect(ofGetMouseX(),ofGetMouseY(),200,200);
//    ofSetColor(255);
}

//--------------------------------------------------------------
//void InteractiveMenu::cmdEvent(ofxCDMEvent &ev){
    void InteractiveMenu::cmdEvent(string &ev){
        
//        cout << " --------------------------- " << endl;
//    /*-------------Catch Destination Menu Messages-------------*/
//    for(int i = 0; i < DestinationMenu_AVGS.size(); i++){
//        if(ev == "destinationMenu::AVGS::" + DestinationMenu_AVGS[i]) destination = DestinationMenu_AVGS[i];
//    }
//    for(int i = 0; i < DestinationMenu_SHADER.size(); i++){
//        if(ev == "destinationMenu::SHADER::" + DestinationMenu_SHADER[i]) destination = DestinationMenu_SHADER[i];
//    }
//    for(int i = 0; i < DestinationMenu_FM.size(); i++){
//        if(ev == "destinationMenu::FM::" + DestinationMenu_FM[i]) destination = DestinationMenu_FM[i];
//    }
//    
//    /*-------------Catch Modulator Menu Messages-------------*/
//    for(int i = 0; i < ModulatorMenu_LFO.size(); i++){
//        if(ev == "modulatorMenu::LFO::" + ModulatorMenu_LFO[i]) modulator = ModulatorMenu_LFO[i];
//    }
//    for(int i = 0; i < instruments_JEN.size(); i++){
//        if(ev == "Instruments::" + instruments_JEN[i]) modulator = instruments_JEN[i];
//    }
//    for(int i = 0; i < playheads_JEN.size(); i++){
//        if(ev == "Playheads::" + playheads_JEN[i]) modulator = playheads_JEN[i];
//    }
//    
//    cout << "Click message = " << ev << endl;
}

//--------------------------------------------------------------
void InteractiveMenu::guiEvent(ofxUIEventArgs &e)
{
    
}