```c++
#include <string>  
  
#include "raylib.h"  
#include "raymath.h"  
  
int main(void)  
{  
    InitWindow(800,800,"Test 4");  
    SetTargetFPS(60);  
  
  
    const float playerWidth = 50.0f;  
    const float playerHeight = 50.0f;  
    Vector2 playerPosition = {400.0f, 225.0f};  
  
    float playerSpeed = 240.0f;  
  
    // Variables (Add these constants and variables outside the loop)  
    // ... Player Variables ...    const float targetWidth = 60.0f;  
    const float targetHeight = 60.0f;  
    Vector2 targetPosition = {600.0f, 100.0f};  
  
    Color playerColor = BLUE;  
  
    int Keys[4] = {KEY_W,KEY_S,KEY_A,KEY_D};  
    while (!WindowShouldClose())  
    {  
        // 1. UPDATE PHASE  
  
        bool isColliding = false;  
  
        ClearBackground(RAYWHITE);  
  
        // INPUT & MOVEMENT  
  
        Vector2 playerDirection = {0.0f, 0.0f};  
        if (IsKeyDown(Keys[0])) playerDirection.y -= 1.0f;  
        if (IsKeyDown(Keys[1])) playerDirection.y += 1.0f;  
        if (IsKeyDown(Keys[2])) playerDirection.x -= 1.0f;  
        if (IsKeyDown(Keys[3])) playerDirection.x += 1.0f;  
  
        if (playerDirection.x != 0 || playerDirection.y != 0) {  
            playerDirection = Vector2Normalize(playerDirection);  
        }  
  
        playerPosition.x += playerDirection.x * playerSpeed * GetFrameTime();  
        playerPosition.y += playerDirection.y * playerSpeed * GetFrameTime();  
  
        // COLLISION DETECTION  
  
        // a. Create the Player Rectangle        Rectangle playerRectangle = {playerPosition.x, playerPosition.y, playerWidth, playerHeight};  
  
        // b. Create the Target Rectangle  
        Rectangle targetRectangle = {targetPosition.x, targetPosition.y, targetWidth, targetHeight};  
  
        // c. Check for collision and update player color  
        if (CheckCollisionRecs(playerRectangle, targetRectangle)) {  
            playerColor = RED;  
        }  
        else {  
            playerColor = BLUE;  
        }  
  
        // BOUNDARIES  
  
        if (playerPosition.x < 0) {  
            playerPosition.x = 0;  
        }  
  
        float rightLimit = (float)GetScreenWidth() - playerWidth;  
        if (playerPosition.x > rightLimit) {  
            playerPosition.x = rightLimit;  
        }  
        if (playerPosition.y < 0) {  
            playerPosition.y = 0;  
        }  
  
        float downLimit = (float)GetScreenHeight() - playerHeight;  
        if (playerPosition.y > downLimit) {  
            playerPosition.y = downLimit;  
        }  
  
        BeginDrawing();  
        DrawRectangle((int)targetPosition.x, (int)targetPosition.y, (int)targetWidth, (int)targetHeight, GREEN); 
        DrawRectangle((int)playerPosition.x, (int)playerPosition.y, (int)playerWidth, (int)playerHeight, playerColor);   
        EndDrawing();  
    }  
    CloseWindow();  
}
```