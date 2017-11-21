#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
}

//--------------------------------------------------------------
void ofApp::update()
{
	myDavid.seek(ofVec2f(ofGetMouseX(), ofGetMouseY()));
	myDavid.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{	
	ofSetColor(ofColor::red);
	ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 30);
	myDavid.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}
