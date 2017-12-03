#ifndef STATICS_H_INCLUDED
#define STATICS_H_INCLUDED
#include "Point.h"
#include"Brick.h"
enum MouseEventType { ClickUp, MouseMotion, ClickDown, RightClickUp, RightClickDown };
enum CollisionType { Horizontal, Vertical, None};
enum BallType { NormalBallType, ThroughBallType, FireBallType};
enum FireType { NormalFireType, MissileFireType};
enum ANIMATION_FRAMES {FLYING_FRAMES = 1};
enum ButtonColorType {Brown, Green, Red, Life};
enum CollisionObjectType {CollisionObjectBallType, CollisionObjectBreakableBrickType, CollisionObjectUnbreakableBrickType, CollisionObjectWallType, CollisionObjectBatType};
enum MOTION {RIGHT, LEFT, UP, DOWN};
enum MovingObjectType {ObjectFireType, ObjectMissileType, ObjectBallType, ObjectPowerType};
struct CollisionInfo { CollisionObjectType objectType; CollisionType directionType; Brick* brick = NULL;};
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 650;
const int BOARD_WIDTH = 15;
const int BOARD_HEIGHT = 7;
const int BOARD_BRWIDTH = 63;
const int BOARD_BRHEIGHT = 31;
const Point BallSize = Point();
#endif // STATICS_H_INCLUDED
