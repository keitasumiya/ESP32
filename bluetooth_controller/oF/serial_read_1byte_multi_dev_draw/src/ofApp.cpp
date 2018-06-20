#include "ofApp.h"

ofSerial mySerial1;
ofSerial mySerial2;
int myByte1 = 0;
int myByte2 = 0;
int r1 = 0;
int r2 = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(64);
    ofSetBackgroundColor(0);
    
    //ofSetBackgroundAuto(false);
    ofSetVerticalSync(false);
    ofSetFrameRate(0);
    //ofSetFrameRate(60);
    //mySerial.setup("/dev/cu.usbmodem1421",9600);
    //mySerial.setup("/dev/tty.usbmodem1422",9600);
    mySerial1.setup("/dev/cu.ESP32-ESP32_SPP_SERVER-3",115200);
    mySerial2.setup("/dev/cu.ESP32-ESP32_SPP_SERVER-4",115200);
    
    myFont.load("cooperBlack.ttf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){
    myByte1 = mySerial1.readByte();
    myByte2 = mySerial2.readByte();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if ( myByte1 == OF_SERIAL_NO_DATA )
        printf("1:  NULL");
    else if ( myByte1 == OF_SERIAL_ERROR )
        printf("1: ERROR");
    else
        r1 = myByte1;
        //printf("1:  %d  ", myByte1);

    printf("   ");

    if ( myByte2 == OF_SERIAL_NO_DATA )
        printf("2:  NULL \n");
    else if ( myByte2 == OF_SERIAL_ERROR )
        printf("2: ERROR \n");
    else
        r2 = myByte2;
        //printf("2:  %d \n", myByte2);


    if(r1==255){
        ofSetColor(255, 255, 255);
        ofDrawCircle(int(ofGetWidth()/2.0-300), int(ofGetHeight()/2.0), r1+ofRandom(0, 20));
    }else if(r1<255){
        ofSetColor(255, 0, 0);
        ofDrawCircle(int(ofGetWidth()/2.0-300), int(ofGetHeight()/2.0), r1);
    }
    
    if(r2==255){
        ofSetColor(255, 255, 255);
        ofDrawCircle(int(ofGetWidth()/2.0+300), int(ofGetHeight()/2.0), r2+ofRandom(0, 20));
    }else if(r2<255){
        ofSetColor(0, 0, 255);
        ofDrawCircle(int(ofGetWidth()/2.0+300), int(ofGetHeight()/2.0), r2);
    }

    ofSetColor(255);
    ofFill();
    //myFont.drawString("hello",100,100);
    myFont.drawString(ofToString(r1), int(ofGetWidth()/2.0-300-100), int(ofGetHeight()/2.0-300));
    myFont.drawString(ofToString(r2), int(ofGetWidth()/2.0+300-100), int(ofGetHeight()/2.0-300));

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
