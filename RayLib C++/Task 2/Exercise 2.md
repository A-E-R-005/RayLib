```c++
#include "raylib.h"  
  
int main(void)  
{  
    int width = 800;  
    int height = 800;  
  
    InitWindow(width, height, "window example");  
  
    SetTargetFPS(60);  
  
    while (!WindowShouldClose()) {  
        BeginDrawing();  
        ClearBackground(RAYWHITE);  
        DrawText("Congrats! Raylib is working!",400,400,20,LIGHTGRAY);  
  
        // ... inside the while loop ...  
  
        // Drawing  
  
        // 1. Draw Red Rectangle (Top-Left)        
        DrawRectangle(650, 650, 100, 50, RED);  
  
        // 2. Draw Blue Circle (Center)  
        DrawCircle(50,50,5, BLUE);  
  
        // 3. Draw Yellow Line (Across the screen)  
        DrawLine(200,400,400,200, YELLOW);  
  
        // 4. Draw Your Name (Bottom-Right, Green)  
        DrawText("Adam Rehman", 300,300,5,GREEN);  
  
        EndDrawing();  
        // ...  
    }  
    CloseWindow();  
    return 0;  
}
```
![[Pasted image 20251128181636.png]]