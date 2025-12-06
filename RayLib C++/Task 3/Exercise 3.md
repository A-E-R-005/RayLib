```c++
#include <string>  
  
#include "raylib.h"  
  
int main(void)  
{  
    InitWindow(800,800,"Test 3");  
    SetTargetFPS(60);  
  
    // Define player state variables BEFORE the loop  
    Vector2 playerPosition = {400.0f, 225.0f};  
    float playerSpeed = 4.0f;  
    int ACount = 0;  
    int WCount = 0;  
    int SCount = 0;  
    while (!WindowShouldClose())  
    {  
        // ******************************************************  
		// 1. UPDATE PHASE: Handle Input and Logic        //******************************************************        if (IsKeyDown(KEY_D)) { // Move Right  
            // TASK: Modify playerPosition.x here            playerPosition.x += playerSpeed;  
        }  
        // TASK: Add checks for KEY_A, KEY_W, and KEY_S  
  
  
        if (IsKeyPressed(KEY_A)) {  
            ACount+=1;  
        }  
        if (IsKeyPressed(KEY_W)) {  
            WCount+=1;  
        }  
        if (IsKeyPressed(KEY_S)) {  
            SCount+=1;  
        }  
  
        // ******************************************************  
        // 2. DRAW PHASE: Render the frame        // ******************************************************  
        BeginDrawing();  
        std::string POS = ("Player Position: " + std::to_string(playerPosition.x));  
        std::string A = "A has been pressed" + std::to_string(ACount) + "times";  
        std::string W = "W has been pressed" + std::to_string(WCount) + "times";  
        std::string S = "S has been pressed" + std::to_string(SCount) + "times";  
        DrawText(POS.c_str(),10,10,12,BLACK);  
        DrawText(A.c_str(), 350,400,10,BLACK);  
        DrawText(W.c_str(), 350,350,10,BLACK);  
        DrawText(S.c_str(), 350,300,10,BLACK);  
        ClearBackground(RAYWHITE);  
  
        // TASK: Draw the 50x50 blue rectangle using playerPosition.x and playerPosition.y  
        DrawRectangle(playerPosition.x,playerPosition.y,12,12,BLUE);  
  
        EndDrawing();  
    }  
  
    // ... (CloseWindow) ...  
}
```
![[Pasted image 20251128204615.png]]