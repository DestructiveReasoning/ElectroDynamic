#pragma once

#include "destructive_reasoning.h"
#include "Entity.h"

#define ArrowLength (1.0/4000000.0)

class ChargedParticle : public Entity
{
public:
	ChargedParticle(int model, int texture, Vector3 pos, float mass, float charge, bool isFixed, Vector3 *cameraPos);
	~ChargedParticle(void);

	inline float getCharge(void) { return charge; };
	inline bool  isMobile(void) { return mobile; };

	static void drawArrow(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, bool);

private:
	float charge;
};

namespace ElectroDynamic
{
	static const float k = 8.998 * pow(10,9);
	static GLuint proton;
	static GLuint electron;
	static GLuint arrow;
	static GLuint arrowTexture;
	static GLuint arrowTextureSelected;

	static int index = 0;
	static int fieldIndex = 0;

	static std::vector<ChargedParticle*> particles;

	static void calculateElectricForce(ChargedParticle *p1, ChargedParticle *p2)
	{
		float q1, q2;
		float r;
		float theta;
		long double fe;
		q1 = p1->getCharge();
		q2 = p2->getCharge();
		r = p1->getPosition().distanceFrom(p2->getPosition());
		//theta = acos(p1->getPosition().dot(p2->getPosition()) / (p1->getPosition().length() * p2->getPosition().length()));
		Vector3 rhat = p2->getPosition() - p1->getPosition();
		rhat.normalize();
		if(r < 1) r = 1;
		fe = k  *  q1 * q2 / (r * r);
		p1->appendForce(rhat * -fe * _animationspeed);
		p2->appendForce(rhat * fe * _animationspeed);
	}


	static Vector3 calculateElectricField(Vector3 pos)
	{
		Vector3 net = Vector3(0,0,0);
		for(int c = 0; c < particles.size(); c++)
		{
			float q;
			float r;
			Vector3 rhat;
			q = particles[c]->getCharge();
			r = particles[c]->getPosition().distanceFrom(pos);
			rhat = pos - particles[c]->getPosition();
			rhat.normalize();
			if(r < 0.5) r = 0.5;
			net += (rhat * (k * q / (r * r)));
		}
		return net;
	}

	struct FieldSensor
	{
		Vector3 pos;
		Vector3 field;
		FieldSensor(Vector3 _pos, Vector3 _field) : pos(_pos), field(_field) {};
		
		void Update()
		{
			field = calculateElectricField(pos);
		};

		void Render(Vector3 cameraPos, bool selected)
		{
			//glScalef(field.length() * ArrowLength,1.0,1.0);
			glTranslatef(0,0,_zdefault);
			glRotatef(Entity::yangle,0,1,0);
			//glRotatef(1.0,field.getX(),field.getY(),field.getZ());

			glTranslatef(pos.getX() + cameraPos.getX(), pos.getY() + cameraPos.getY(), pos.getZ() + cameraPos.getZ() - _zdefault);
			//glRotatef(atan2(field.getZ(),field.getY()) * 180/M_PI, 1.0,0.0,0.0);
			//glRotatef(atan2(field.getX(),field.getZ()) * 180/M_PI, 0.0,1.0,0.0);
			//glRotatef(atan2(field.getY(),field.getX()) * 180/M_PI, 0.0,0.0,1.0);

			//float rot2d = atan2(field.getY(),field.getX()) * 180 / M_PI; //Store xy plane angle
			//glRotatef(rot2d, 0,0,1); //Rotate vector to proper 2D orientation
			//float rot3d = atan2(field.getY(),field.getZ()) * 180 / M_PI; //Store yz plane angle
			//glRotatef(atan2(sqrt(field.getX() * field.getX() + field.getY() * field.getY()), field.getZ()) * 180/M_PI,0,1,0); 
			//glRotatef(-rot3d, -sin(rot2d * M_PI/180), cos(rot2d * M_PI/180), 0);

			ChargedParticle::drawArrow(0,0,0,field.getX() * ArrowLength, field.getY() * ArrowLength, field.getZ() * ArrowLength, 0.1, selected);

			//printf("Angle: %.4f\n", rot3d);
			glBindTexture(GL_TEXTURE_2D,arrowTexture);
			//glCallList(arrow);
			glLoadIdentity();
		};
	};

	static std::vector<FieldSensor *> fields;
};

