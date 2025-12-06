```c++
#ifndef SHEETANIMATION_H  
#define SHEETANIMATION_H  
#include <raylib.h>  
  
struct SheetAnim {  
    Texture2D* spriteSheet;  
    int totalFrames;  
    float frameWidth;  
    float frameHeight;  
    int frameIndex;  
  
    float frameTime;  
    float updateTime;  
  
    Rectangle sourceRect;  
  
    void Aloading(int totframes, Texture2D* texture);  
    void Alogic();  
};  
  
#endif //SHEETANIMATION_H
```

```c++
#include "sheetanimation.h"  
#include "raylib.h"  
#include "raymath.h"  
  
void SheetAnim::Aloading(int totframes, Texture2D* texture) {  
    spriteSheet = texture;  
    totalFrames = totframes;  
  
    frameWidth = spriteSheet->width/totalFrames;  
    frameHeight = spriteSheet->height;  
    frameIndex = 0;  
  
    frameTime = 0.0f;  
    updateTime = 1.0f/12.0f;  
}  
  
void SheetAnim::Alogic() {  
    frameTime += GetFrameTime();  
    if (frameTime >= updateTime) {  
        frameTime = 0.0f;  
        frameIndex++;  
        if (frameIndex >= totalFrames) {  
            frameIndex = 0;  
        }  
    }  
  
    sourceRect = {frameIndex * frameWidth, 0.0f, frameWidth, frameHeight};  
}
```

```c++
#include "player.h"  
#include "raylib.h"  
#include "raymath.h"  
  
  
void Player::loading(){  
    playerTexture = LoadTexture(("../assets/Characters/Soldier/Soldier/Soldier-Idle.png"));  
    playerColor = BLUE;  
    playerSpeed = 240.0f;  
    playerPosition = {400.0f, 225.0f};  
    playerRect = {playerPosition.x, playerPosition.y, 17, 13};  
  
}  
  
void Player::Draw(Rectangle sourceRect) {  
    //playerRect.width = sourceRect.width;  
    //playerRect.height = sourceRect.height;    DrawTextureRec(playerTexture, sourceRect, playerPosition, playerColor);  
}  
  
void Player::Movement() {  
    playerDirection = {0.0f, 0.0f};  
    if (IsKeyDown(KEY_W)) playerDirection.y -= 1.0f;  
    if (IsKeyDown(KEY_S)) playerDirection.y += 1.0f;  
    if (IsKeyDown(KEY_A)) playerDirection.x -= 1.0f;  
    if (IsKeyDown(KEY_D)) playerDirection.x += 1.0f;  
  
    if (playerDirection.x != 0 || playerDirection.y != 0) {  
        playerDirection = Vector2Normalize(playerDirection);  
    }  
  
    playerPosition.x += playerDirection.x * playerSpeed * GetFrameTime();  
    playerPosition.y += playerDirection.y * playerSpeed * GetFrameTime();  
  
    playerRect.x = playerPosition.x;  
    playerRect.y = playerPosition.y;  
}  
  
void Player::Boundaries() {  
    if (playerPosition.x < 0) {  
        playerPosition.x = 0;  
    }  
  
    float rightLimit = (float)GetScreenWidth() - playerRect.width;  
    if (playerPosition.x > rightLimit) {  
        playerPosition.x = rightLimit;  
    }  
    if (playerPosition.y < 0) {  
        playerPosition.y = 0;  
    }  
  
    float downLimit = (float)GetScreenHeight() - playerRect.height;  
    if (playerPosition.y > downLimit) {  
        playerPosition.y = downLimit;  
    }  
  
    playerRect.x = playerPosition.x;  
    playerRect.y = playerPosition.y;  
}
```

```c++
#include <string>  
#include "raylib.h"  
#include "raymath.h"  
#include "player.h"  
#include "sheetanimation.h"  
#include "target.h"  
  
  
  
  
int main(void)  
{  
    // I. INITIALIZATION  
    InitWindow(800,800,"Test 8");  
    SetTargetFPS(60);  
  
    Player player;  
    player.loading();  
    Target target;  
    target.loading();  
    SheetAnim playerA;  
    playerA.Aloading(6,&player.playerTexture);  
    SheetAnim targetA;  
    targetA.Aloading(6,&target.targetTexture);  
    while (!WindowShouldClose())  
    {  
        bool isColliding = false;  
  
        // INPUT & MOVEMENT  
        player.Movement();  
        // BOUNDARIES  
        player.Boundaries();  
  
        //ANIMATION  
        playerA.Alogic();  
        targetA.Alogic();  
        // COLLISION  
        if (CheckCollisionRecs(player.playerRect, target.targetRect)) {  
            player.playerColor = RED;  
        }  
        else {  
            player.playerColor = BLUE;  
        }  
  
  
        // DRAWING  
        BeginDrawing();  
        ClearBackground(RAYWHITE);  
        target.Draw(targetA.sourceRect);  
        player.Draw(playerA.sourceRect);  
        EndDrawing();  
    }  
    // DE-INITIALIZATION  
    UnloadTexture(player.playerTexture);  
    UnloadTexture(target.targetTexture);  
  
    CloseWindow();  
    return 0;  
  
}
```


![[Pasted image 20251203011136.png]]