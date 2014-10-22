#pragma once

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include "SDL.h"
//#include <gl/GL.h>
//#include <gl/GLU.h>
#include "SDL_opengl.h"
//#include "SDL_opengles.h"
//#include "SDL_opengles2.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <glm.hpp>
#include <glut.h>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstdio>

/*ANIMATION SETTINGS*/
#define _zdefault -12.0f
#define _animationspeed 1/100000
#define _cameraSpeed 0.25f
#define _rotationSpeed 0.5f;
//#define _animationspeed 10

/* KEY BINDINGS */
#define Space	SDLK_SPACE
#define LArrow	SDLK_LEFT
#define RArrow	SDLK_RIGHT
#define UArrow	SDLK_UP
#define DArrow	SDLK_DOWN
#define Plus	SDLK_PLUS
#define Minus	SDLK_MINUS
#define Shift	SDLK_LSHIFT
#define Control SDLK_LCTRL
#define Zero	SDLK_0
#define Home	SDLK_HOME
#define Esc		SDLK_ESCAPE
#define _Space		SDL_SCANCODE_SPACE
#define _LArrow		SDL_SCANCODE_LEFT
#define _RArrow		SDL_SCANCODE_RIGHT
#define _DArrow		SDL_SCANCODE_DOWN
#define _UArrow		SDL_SCANCODE_UP
#define _Z			SDL_SCANCODE_Z
#define _H			SDL_SCANCODE_H
#define _J			SDL_SCANCODE_J
#define _K			SDL_SCANCODE_K
#define _L			SDL_SCANCODE_L
#define _W			SDL_SCANCODE_W
#define _A			SDL_SCANCODE_A
#define _S			SDL_SCANCODE_S
#define _D			SDL_SCANCODE_D
#define _U			SDL_SCANCODE_U
#define _P			SDL_SCANCODE_P
#define _V			SDL_SCANCODE_V
#define _Alt		SDL_SCANCODE_LALT
#define _RAlt		SDL_SCANCODE_RALT
#define	_Plus		SDL_SCANCODE_EQUALS
#define _Minus		SDL_SCANCODE_MINUS
#define _Shift		SDL_SCANCODE_LSHIFT
#define _Control	SDL_SCANCODE_LCTRL
#define _RControl	SDL_SCANCODE_RCTRL
#define _Zero		SDL_SCANCODE_0
#define _Home		SDL_SCANCODE_HOME
#define _Esc		SDL_SCANCODE_ESCAPE
#define _Tab		SDL_SCANCODE_TAB
#define _Tilde		SDL_SCANCODE_GRAVE
#define _Delete		SDL_SCANCODE_DELETE
#define _Backspace	SDL_SCANCODE_BACKSPACE
#define _F1			SDL_SCANCODE_F1

#define Select			Esc
#define PanLeft			LArrow
#define PanRight		RArrow
#define PanUp			UArrow
#define PanDown			DArrow
#define ZoomIn			Shift
#define ZoomOut			Control
#define ResetCamera		Home
#define _Select			_Esc
#define _Command		_F1
#define	_PanLeft		_LArrow
#define _PanRight		_RArrow
#define _PanUp			_UArrow
#define _PanDown		_DArrow
#define _MoveUp			_W
#define _MoveLeft		_A
#define _MoveDown		_S
#define _MoveRight		_D
#define _MoveIn			_Shift
#define _MoveOut		_Control
#define _ScrollForward	_Tab
#define _ScrollBackward	_Tilde
#define _ZoomIn			_Plus
#define _ZoomOut		_Minus
#define _ResetCamera	_Home
#define _Remove			_Delete
#define _FineAdjustment	_RAlt
#define _Attributes		_P
#define _FieldForward	_Space
#define _FieldBackward	_Backspace

#define _buttonspeed 300

struct coordinate{
	float x, y, z;
	coordinate(float a, float b, float c) : x(a), y(b), z(c) {};
};

struct face{
	int facenum;
	bool quad;
	int faces[4];
	face(int facen, int f1, int f2, int f3) : facenum(facen)
	{
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		quad = false;
	}

	face(int facen, int f1, int f2, int f3, int f4) : facenum(facen)
	{
		faces[0] = f1;
		faces[1] = f2;
		faces[2] = f3;
		faces[3] = f4;
		quad = true;
	}
};

