```c++
#include <string>  
  
#include "raylib.h"  
#include "raymath.h"  
  
  
  
  
int main(void)  
{  
    // ... (Window Setup, SetTargetFPS) ...  
  
    //Define Texture Variables    Texture2D playerTexture;  
    Texture2D targetTexture;  
  
    // I. INITIALIZATION  
  
    InitWindow(800,800,"Test 4");  
    SetTargetFPS(60);  
  
    // Load Textures (CRITICAL STEP)  
    playerTexture = LoadTexture("../assets/Characters/Soldier/Soldier/Soldier-Idle.png");  
    targetTexture = LoadTexture("../assets/Characters/Orc/Orc/Orc-Idle.png");  
  
  
    const float playerWidth = (float)playerTexture.width;  
    const float playerHeight = (float)playerTexture.height;;  
    Vector2 playerPosition = {400.0f, 225.0f};  
  
    float playerSpeed = 240.0f;  
  
    // Variables (Add these constants and variables outside the loop)  
    // ... Player Variables ...    const float targetWidth = (float)targetTexture.width;  
    const float targetHeight = (float)targetTexture.height;  
    Vector2 targetPosition = {600.0f, 100.0f};  
  
    Color playerColor = BLUE;  
  
    while (!WindowShouldClose())  
    {  
        // 1. UPDATE PHASE  
  
        bool isColliding = false;  
  
        // INPUT & MOVEMENT  
  
        Vector2 playerDirection = {0.0f, 0.0f};  
        if (IsKeyDown(KEY_W)) playerDirection.y -= 1.0f;  
        if (IsKeyDown(KEY_S)) playerDirection.y += 1.0f;  
        if (IsKeyDown(KEY_A)) playerDirection.x -= 1.0f;  
        if (IsKeyDown(KEY_D)) playerDirection.x += 1.0f;  
  
        if (playerDirection.x != 0 || playerDirection.y != 0) {  
            playerDirection = Vector2Normalize(playerDirection);  
        }  
  
        playerPosition.x += playerDirection.x * playerSpeed * GetFrameTime();  
        playerPosition.y += playerDirection.y * playerSpeed * GetFrameTime();  
  
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
        // COLLISION  
  
        Rectangle playerRectangle = {playerPosition.x, playerPosition.y, playerWidth, playerHeight};  
  
        Rectangle targetRectangle = {targetPosition.x, targetPosition.y, targetWidth, targetHeight};  
  
        if (CheckCollisionRecs(playerRectangle, targetRectangle)) {  
            playerColor = RED;  
        }  
        else {  
            playerColor = BLUE;  
        }  
  
        // DRAWING  
  
        BeginDrawing();  
        ClearBackground(RAYWHITE);  
        DrawTextureV(targetTexture,targetPosition, WHITE);  
        DrawTextureV(playerTexture,playerPosition, playerColor);  
  
        EndDrawing();  
    }  
    // DE-INITIALIZATION  
    UnloadTexture(playerTexture);  
    UnloadTexture(targetTexture);  
  
    CloseWindow();  
    return 0;  
  
}
```
