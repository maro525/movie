#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(30);
    
    ofSetFrameRate(30);
    
    ofSetBackgroundAuto(false);
    
    // 書き出しの設定
    exp.setup(800, 600, 30);
    exp.setOutputDir("out");
    exp.setOverwriteSequence(true);
    exp.setAutoExit(true);
//    exp.startExport();
    
    mychar.setup(16, 1.0);
    bandchar.setup(16, 1.5);
    songchar.setup(16, 1.2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    exp.begin();
    
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        ofSetColor(30, 100);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        switch (ofGetFrameNum()) {
            case 460:
                scene_state = 2;
                break;
                
            default:
                break;
        }
        
        switch (scene_state) {
            case 1:
                mychar.drawRandom(9, 3, 3);
                myshape.drawTriangle(ofPoint(ofGetWidth()/2, ofGetHeight()/2), ofGetHeight()*3/4);
                break;
            case 2:
                bandchar.drawBand();
                songchar.drawSong();
                break;
                
            default:
                break;
        }
    
    exp.end();


    

    exp.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
