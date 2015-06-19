#include "ofApp.h"

using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    cam.initGrabber(640, 480);
    tracker.setup();

    filePlayer.connectTo(tap).connectTo(output);

    output.start(); // Audio Units work on a "pull" basis, so initiate requesting the buffer be filled

    filePlayer.setFile(ofToDataPath("FSI - Bulgarian Basic Course Volume 1 - Unit 01.mp3"));
    filePlayer.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
//        cout << tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT) << "\n";
    }

    tap.getLeftWaveform(waveform, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    cam.draw(0, 0);
    tracker.draw();
    waveform.draw();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
