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
        EndDrawing();  
    }  
    CloseWindow();  
    return 0;  
}
```
![[Pasted image 20251128181839.png]]