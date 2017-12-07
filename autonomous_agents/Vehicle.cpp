#include "Vehicle.h"



Vehicle::Vehicle()
{
	location.set(10, 10);
	mass = 1;
	maxSpeed = 1;
	maxForce = 0.05;
	printf("New vehicle created!");
}

void Vehicle::seek(ofVec2f target)
{
	// calculating desired velocity
	ofVec2f desired = target - location;
	desired.normalize();
	desired *= maxSpeed;

	// calculating stearing
	ofVec2f steer = desired - velocity;
	steer.limit(maxForce);
	applyForce(steer);
}

void Vehicle::applyForce(ofVec2f force)
{
	// F = m * a -> a = F / m
	//ofVec2f nf(force);
	acceleration += force / mass;
}

void Vehicle::update()
{
	// use euler integrator for update position
	velocity += acceleration;
	velocity.limit(maxSpeed);
	location += velocity;
	acceleration *= 0; // restart force application for next cycle
}

void Vehicle::draw()
{
	//static float _x = 0;
	//_x += 1;
	//ofDrawCircle(_x, location.y, 20);
	
	//velocity.set(cos(ofGetElapsedTimef()), sin(ofGetElapsedTimef()));
	// velocity.set(-1, 0);
	//float tetha = velocity.angleRad(ofVec2f(1.0, 0.0)) + PI;
	//float tetha = velocity.angleRad(ofVec2f(ofGetMouseX(), ofGetMouseY()));
	
	ofPushMatrix();
	ofSetColor(ofColor::white);
	//ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	float tetha = -ofVec2f(ofGetMouseX(), ofGetMouseY()).angle(ofVec2f(-25, 0));
	ofTranslate(location);

	// draw triangle
	//ofRotate(ofRadToDeg(tetha));
	ofRotate(tetha);
	ofDrawTriangle(ofVec2f(25, 30), ofVec2f(25, -30), ofVec2f(-25, 0));
	
	// draw front
	ofSetColor(ofColor::red);
	ofDrawCircle(ofVec2f(-25, 0), 10);

	// draw triangle center
	ofSetColor(ofColor::blue);
	ofDrawCircle(ofVec2f(0, 0), 5);

	ofPopMatrix();
	// TODO DRAW TRIANGLE
}

Vehicle::~Vehicle()
{
}
