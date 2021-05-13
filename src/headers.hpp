#ifndef _H_HEADERS
#define _H_HEADERS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <istream>
#include <ostream>

#include <raylib/raylib.h>
#include <raylib/raymath.h>
#include <raylib/physac.h>
#include <raylib/rlgl.h>

typedef unsigned int uint;

const int MAXBOARDS = 8;

const int frameWidth = 800;
const int frameHeight = 600;
const int ballSize = 25;
const int boardWidth = 100;
const int boardHeight = 10;
const int blockWidth = 200;
const int blockHeight = 10;

const int toolWidth = 100;
const int toolHeight = 100;

const float defaultLightness = 1.0;
const float maxLightness = 2.0;
const float depressRate = 0.001;
const float lightnessEpsilon = 0.01;

//some parameters for start screen 
const float titleWidth = 250;
const float titleHeight = 200;
const float titleFontSize = 50;
const float startRecWidth = 100;
const float startRecHeight = 300;
const float startWidth = 150;
const float startHeight = 390;
const float startFontSize = 30;
// const float setWidth = 100;
// const float setHeight = 90;
// const float setFontSize = 5;
// const float exitWidth = 100;
// const float exitHeight = 100;
// const float exitFontSize = 5;
const float selectRecWidth = 500;
const float selectRecHeight = 300;
const float selectWidth = 550;
const float selectHeight = 390;
const float selectFontSize = 30;

const float developersRecWidth  = 0;
const float developersRecHeight =  0;
const float developersWidth = 20;
const float developersHeight = 50;
const float developerFontSize = 10;

const float showFontSize = 30;

//some parameters for select screen
const float selectTitleWidth = 280;
const float selectTitleHeight = 120;
const float selectTitleFontSize = 80;
const float Width1_1 = 120;
const float Height1_1 = 450;
const float FontSize1_1 = 30;
const float Width1_2 = 380;
const float Height1_2 = 450;
const float FontSize1_2 = 30;
const float Width1_3 = 650;
const float Height1_3 = 450;
const float FontSize1_3 = 30;
const float RecWidth1_1 = 50;
const float RecHeight1_1 = 380;
const float RecWidth1_2 = 310;
const float RecHeight1_2 = 380;
const float RecWidth1_3 = 580;
const float RecHeight1_3 = 380;

//some parameters for menu screen
const float menuWidth = 250;
const float menuHeight = 50;

const float menuWidth1 = 100+100;
const float menuHeight1 = 300;
const float menuWidth2 = 250 + 100;
const float menuHeight2 = 300;
const float menuWidth3 = 400 + 100;
const float menuHeight3 = 300;

const float menuFontSize = 100;
const float returnWidth = 170;
const float returnHeight = 250;
const float returnFontSize = 50;
const float mainWidth = 170;
const float mainHeight = 350;
const float mainFontSize = 50;
const float returnRecWidth = 150;
const float returnRecHeight = 220;
const float mainRecWidth = 150;
const float mainRecHeight = 320;

//some parameters for game screen
const float buttonHeight = 0;
const float bt1Width = 0;
const float bt2Width = 100;
const float bt3Width = 200;
const float bt4Width = 300;
const float bt5Width = 400;
const float bt6Width = 500;
const float bt7Width = 600;
const float bt8Width = 700;
const float gunWidth = 350;
const float gunHeight = 250;
const float ballWidth = 400;
const float ballHeight = 300;
const float pauseWidth = 700;
const float pauseHeight = 500;
#endif
