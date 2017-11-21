#include "Vehicle.h"



Vehicle::Vehicle()
{
	location.set(10, 10);
	mass = 1;
	maxSpeed = 4;
	maxForce = 0.1;
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
	acceleration *= 0; // restar force application for next cycle
}

void Vehicle::draw()
{
	//static float _x = 0;
	//_x += 1;
	//ofDrawCircle(_x, location.y, 20);
	ofSetColor(ofColor::white);
	//ofDrawCircle(location, 20);
	float tetha = velocity.angleRad(ofVec2f(1.0, 0.0)) + PI;
	ofPushMatrix();
	ofTranslate(location);
	ofRotate(ofRadToDeg(tetha));
	ofDrawTriangle(ofVec2f(-50, 0), ofVec2f(50, -50), ofVec2f(0, 0));
	ofPopMatrix();
	// TODO DRAW TRIANGLE
}

Vehicle::~Vehicle()
{
}
