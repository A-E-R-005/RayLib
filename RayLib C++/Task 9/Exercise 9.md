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
  
  
    Target target;  
    target.loading();  
    SheetAnim targetA;  
    targetA.Aloading(6,&target.targetTexture);  
  
    Player player;  
    player.loading();  
    SheetAnim player_idle;  
    player_idle.Aloading(6,&player.playerTexture_idle);  
    SheetAnim player_walk;  
    player_walk.Aloading(8,&player.playerTexture_walk);  
  
  
    while (!WindowShouldClose())  
    {  
        bool isColliding = false;  
  
        // INPUT & MOVEMENT  
        player.Movement();  
        // BOUNDARIES  
        player.Boundaries();  
  
        //ANIMATION  
        if (player.currentState == IDLE) {  
            player_idle.Alogic();  
        }  
        else if (player.currentState == WALK) {  
            player_walk.Alogic();  
        }  
  
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
        if (player.currentState == IDLE) {  
            player.Draw(player_idle.sourceRect, player.playerTexture_idle);  
        }  
        else {  
            player.Draw(player_walk.sourceRect, player.playerTexture_walk);  
        }  
  
        EndDrawing();  
    }  
    // DE-INITIALIZATION  
    UnloadTexture(player.playerTexture_idle);  
    UnloadTexture(player.playerTexture_walk);  
    UnloadTexture(target.targetTexture);  
  
    CloseWindow();  
    return 0;  
  
}
```

```c++
  
#ifndef PLAYER_H  
#define PLAYER_H  
#include "raylib.h"  
  
enum PlayerState {IDLE, WALK};  
  
struct Player {  
  
    Texture2D playerTexture_idle;  
    Texture2D playerTexture_walk;  
    Color playerColor;  
    float playerSpeed;  
    PlayerState currentState;  
  
    Vector2 playerPosition;  
    Rectangle playerRect;  
    Vector2 playerDirection;  
  
    void loading();  
    void Boundaries();  
    void Draw(Rectangle sourceRect, Texture2D texture) const;  
    void Movement();  
};  
  
#endif //PLAYER_H
```

```c++
#include "player.h"  
#include "raylib.h"  
#include "raymath.h"  
  
  
void Player::loading(){  
    playerTexture_idle = LoadTexture("../assets/Characters/Soldier/Soldier/Soldier-Idle.png");  
    playerTexture_walk = LoadTexture("../assets/Characters/Soldier/Soldier/Soldier-Walk.png");  
    playerColor = BLUE;  
    playerSpeed = 240.0f;  
    playerPosition = {400.0f, 225.0f};  
    playerRect = {playerPosition.x, playerPosition.y, 17, 13};  
    currentState = IDLE;  
  
}  
  
void Player::Draw(Rectangle sourceRect, Texture2D texture) const {  
    DrawTextureRec(texture, sourceRect, playerPosition, playerColor);  
  
}  
  
void Player::Movement() {  
    playerDirection = {0.0f, 0.0f};  
    if (IsKeyDown(KEY_W)) playerDirection.y -= 1.0f;  
    if (IsKeyDown(KEY_S)) playerDirection.y += 1.0f;  
    if (IsKeyDown(KEY_A)) playerDirection.x -= 1.0f;  
    if (IsKeyDown(KEY_D)) playerDirection.x += 1.0f;  
  
    if (playerDirection.x != 0 || playerDirection.y != 0) {  
        playerDirection = Vector2Normalize(playerDirection);  
        currentState = WALK;  
    }  
    else {  
        currentState = IDLE;  
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
