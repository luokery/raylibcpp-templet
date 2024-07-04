#ifndef ExampleBall_h
#define ExampleBall_h

#include <string>

#include "raylib.h"

class ExampleBall {
    public:
        ExampleBall();

        void setName(char *name);
        std::string getName();

        void setBallPosition(Vector2 ballPosition);
        Vector2 getBallPosition();
        
        void setBallSpeed(Vector2 ballSpeed);
        Vector2 getBallSpeed();
        
        void setBallRadius(float ballRadiu);
        float getBallRadius();
        
        void draw();

        void update();
    private:
        std::string mStrName;
        Vector2 mBallPosition = { 250.0f, 250.0f };
        Vector2 mBallSpeed = { 15.0f, 14.0f };
        float mBallRadius = 20;
};

#endif
