#include "ExampleBall.h"

ExampleBall::ExampleBall() {
    mBallPosition = { 250.0f, 250.0f };
    mBallSpeed = { 15.0f, 14.0f };
    mBallRadius = 20;
}

void ExampleBall::setName(char* name) {
	mStrName = name;
}
std::string ExampleBall::getName() {
	return mStrName;
}

void ExampleBall::setBallPosition(Vector2 ballPosition){
    mBallPosition = ballPosition;
}
Vector2 ExampleBall::getBallPosition(){
    return mBallPosition;
}

void ExampleBall::setBallSpeed(Vector2 ballSpeed){
    mBallSpeed = ballSpeed;
}
Vector2 ExampleBall::getBallSpeed(){
    return mBallSpeed;
}

void ExampleBall::setBallRadius(float ballRadiu){
    mBallRadius = ballRadiu;
}
float ExampleBall::getBallRadius(){
    return mBallRadius;
}

void ExampleBall::draw(){
    DrawCircleV(mBallPosition, mBallRadius, MAROON);

    DrawRectangleLinesEx((Rectangle) { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() }, 4, RAYWHITE);
}

void ExampleBall::update(){
    // Bouncing ball logic
    // 小球移动控制
    mBallPosition.x += mBallSpeed.x;
    mBallPosition.y += mBallSpeed.y;

    // 小球碰撞屏幕控制
    if ((mBallPosition.x >= (GetScreenWidth() - mBallRadius)) || (mBallPosition.x <= mBallRadius)) mBallSpeed.x *= -1.0f;
    if ((mBallPosition.y >= (GetScreenHeight() - mBallRadius)) || (mBallPosition.y <= mBallRadius)) mBallSpeed.y *= -1.0f;
}

