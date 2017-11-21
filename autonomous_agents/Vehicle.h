#pragma once
#include "ofMain.h"
/*
In his 1999 paper “Steering Behaviors for Autonomous Characters,”
Reynolds uses the word “vehicle” to describe his autonomous agents,
so we will follow suit.
*/
class Vehicle
{
public:
	// METHODS
	Vehicle();
	void seek(ofVec2f target);
	void applyForce(ofVec2f force);
	void update();
	void draw();
	~Vehicle();

	// ATTRIBUTES
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	float maxSpeed;
	float maxForce;
	float mass;
};

