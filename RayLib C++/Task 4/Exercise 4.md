```c++
#include <string>  
  
#include "raylib.h"  
#include "raymath.h"  
  
int main(void)  
{  
    InitWindow(800,800,"Test 4");  
    SetTargetFPS(60);  
  
    // Variables (add these constants before the loop)  
    const float playerWidth = 50.0f;  
    const float playerHeight = 50.0f;  
    Vector2 playerPosition = {400.0f, 225.0f};  
    //Stores the direction of movement for the current frame  
  
    float playerSpeed = 4.0f;  
    int Keys[4] = {KEY_W,KEY_S,KEY_A,KEY_D};  
    while (!WindowShouldClose())  
    {  
        ClearBackground(RAYWHITE);  
        // 1. INPUT (Movement logic from Task 3)  
        // ... (KEY_D, KEY_A, KEY_W, KEY_S checks) ...        Vector2 playerDirection = {0.0f, 0.0f};  
        if (IsKeyDown(Keys[0])) playerDirection.y -= 1.0f;  
        if (IsKeyDown(Keys[1])) playerDirection.y += 1.0f;  
        if (IsKeyDown(Keys[2])) playerDirection.x -= 1.0f;  
        if (IsKeyDown(Keys[3])) playerDirection.x += 1.0f;  
  
        //Normalising the vector to prevent faster diagonal movement  
        if (playerDirection.x != 0 || playerDirection.y != 0) {  
            playerDirection = Vector2Normalize(playerDirection);  
        }  
  
        playerPosition.x += playerDirection.x * playerSpeed;  
        playerPosition.y += playerDirection.y * playerSpeed;  
  
        // ******************************************************  
        // 2. BOUNDARY CHECKING (New Logic for Task 4)        // ******************************************************  
        // Clamp X-axis (Left and Right)  
        // Left edge (Lower Bound)        if (playerPosition.x < 0) {  
            playerPosition.x = 0;  
        }  
  
        // Right edge (Upper Bound) - HINT: Need GetScreenWidth() and playerWidth  
        // ... YOUR CODE HERE ...        float rightLimit = (float)GetScreenWidth() - playerWidth;  
        if (playerPosition.x > rightLimit) {  
            playerPosition.x = rightLimit;  
        }  
        // Clamp Y-axis (Top and Bottom)  
  
        // Top edge (Lower Bound)        if (playerPosition.y < 0) {  
            playerPosition.y = 0;  
        }  
  
        // Bottom edge (Upper Bound) - HINT: Need GetScreenHeight() and playerHeight  
        // ... YOUR CODE HERE ...        float downLimit = (float)GetScreenHeight() - playerHeight;  
        if (playerPosition.y > downLimit) {  
            playerPosition.y = downLimit;  
        }  
  
        // 3. DRAWING (Remember to use playerWidth/playerHeight)  
        // ...        BeginDrawing();  
        DrawRectangle((int)playerPosition.x, (int)playerPosition.y, (int)playerWidth, (int)playerHeight, BLUE);  
        EndDrawing();  
        // ...  
    }  
    CloseWindow();  
}
```
