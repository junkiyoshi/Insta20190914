#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int radius = 150;
	int size = (radius * 2 * PI) / 360 * 10;
	for (int deg = 0; deg < 360; deg += 10) {

		auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
		auto height = ofMap(ofNoise(location.x * 0.01, location.y * 0.01, ofGetFrameNum() * 0.01), 0, 1, 0, 80);

		ofPushMatrix();
		ofTranslate(location);
		ofRotateZ(deg);
		ofTranslate(height * 0.5, 0, 0);

		ofFill();
		ofSetColor(239);
		ofDrawBox(height - 1, size - 1, size - 1);

		ofNoFill();
		ofSetColor(39);
		ofDrawBox(height, size, size);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}