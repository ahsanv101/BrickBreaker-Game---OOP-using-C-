#ifndef STATICS_H_INCLUDED
#define STATICS_H_INCLUDED

enum MouseEventType { ClickUp, MouseMotion, ClickDown, RightClickUp, RightClickDown };
enum CollisionType { Horizontal, Vertical, None};
enum BallType { NormalBallType, ThroughBallType, FireBallType};
enum FireType { NormalFireType, MissileFireType};
enum ANIMATION_FRAMES {FLYING_FRAMES = 1};
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 650;
const int BOARD_WIDTH = 12;
const int BOARD_HEIGHT = 8;
const int BOARD_BRWIDTH = 63;
const int BOARD_BRHEIGHT = 31;


#endif // STATICS_H_INCLUDED
