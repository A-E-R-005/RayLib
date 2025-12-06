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
  
    float playerSpeed = 240.0f; // <--- This is now 240 pixels per second  
  
    int Keys[4] = {KEY_W,KEY_S,KEY_A,KEY_D};  
    while (!WindowShouldClose())  
    {  
        // ******************************************************  
        // 1. UPDATE PHASE        // ******************************************************  
        // ... Input and Vector2Normalize logic remains the same ...        ClearBackground(RAYWHITE);  
        Vector2 playerDirection = {0.0f, 0.0f};  
        if (IsKeyDown(Keys[0])) playerDirection.y -= 1.0f;  
        if (IsKeyDown(Keys[1])) playerDirection.y += 1.0f;  
        if (IsKeyDown(Keys[2])) playerDirection.x -= 1.0f;  
        if (IsKeyDown(Keys[3])) playerDirection.x += 1.0f;  
  
        // ... Input and Vector2Normalize logic remains the same ...  
        if (playerDirection.x != 0 || playerDirection.y != 0) {  
            playerDirection = Vector2Normalize(playerDirection);  
        }  
  
        // 2. APPLY MOVEMENT (New Logic for Task 5)  
  
        playerPosition.x += playerDirection.x * playerSpeed * GetFrameTime();  
        playerPosition.y += playerDirection.y * playerSpeed * GetFrameTime();  
  
        // 3. BOUNDARY CHECKING (remains the same)  
        // ...        if (playerPosition.x < 0) {  
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
        DrawRectangle((int)playerPosition.x, (int)playerPosition.y, (int)playerWidth, (int)playerHeight, BLUE);  
        EndDrawing();  
    }  
    CloseWindow();  
}
```
