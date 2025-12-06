#include <string>
#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include "sheetanimation.h"
#include "target.h"




int main(void)
{
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    // I. INITIALIZATION
    InitWindow(1920,1080,"Test 8");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("../craftpix background/nature_1/origbig.png");
    const int WORLD_WIDTH = 1920;
    const int WORLD_HEIGHT = 1080;
    float halfScreenWidth = (float)GetScreenWidth()/2.0f;
    float halfScreenHeight = (float)GetScreenHeight()/2.0f;

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

    Camera2D gameCamera = {0};
    gameCamera.target = player.playerPosition;
    gameCamera.offset = {halfScreenWidth, halfScreenHeight};
    gameCamera.rotation = 0.0f;
    gameCamera.zoom = 2.0f;

    float zoomHalfScreenWidth = halfScreenWidth / gameCamera.zoom;
    float zoomHalfScreenHeight = halfScreenHeight / gameCamera.zoom;

    float minCameraX = zoomHalfScreenWidth;
    float minCameraY = zoomHalfScreenHeight;

    float maxCameraX = WORLD_WIDTH - zoomHalfScreenWidth;
    float maxCameraY = WORLD_HEIGHT - zoomHalfScreenHeight;
    while (!WindowShouldClose())
    {
        bool isColliding = false;
        // INPUT & MOVEMENT
        player.Movement();
        // BOUNDARIES
        player.Boundaries();

        float targetX = Clamp(player.playerPosition.x, minCameraX, maxCameraX);
        float targetY = Clamp(player.playerPosition.y, minCameraY, maxCameraY);
        gameCamera.target = (Vector2){targetX, targetY};



        //ANIMATION
        SheetAnim* activeAnim = (player.currentState == IDLE) ? &player_idle : &player_walk;
        float drawDirectionX;
        if (player.playerDirection.x != 0.0f) {
            drawDirectionX = player.playerDirection.x;
        } else {
            drawDirectionX = player.lastHorizontalDirection;
        }
        activeAnim->Alogic(drawDirectionX);

        targetA.Alogic(0.0f);
        // COLLISION
        /*if (CheckCollisionRecs(player.playerRect, target.targetRect)) {
            player.playerColor = RED;
        }
        else {
            player.playerColor = BLUE;
        }*/

        Rectangle boundary;
        boundary.x = 0;
        boundary.y = 0;
        boundary.width = WORLD_WIDTH;
        boundary.height = WORLD_HEIGHT;
        Vector2 pos = {0,0};

        // DRAWING
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode2D(gameCamera);
        DrawTextureRec(background, boundary, pos, WHITE);
        //DrawRectangle(0,0,WORLD_WIDTH,WORLD_HEIGHT,BLUE);
        target.Draw(targetA.sourceRect);
        if (player.currentState == IDLE) {
            player.Draw(player_idle.sourceRect, player.playerTexture_idle);
        }
        else {

            player.Draw(player_walk.sourceRect, player.playerTexture_walk);
        }
        EndMode2D();
        EndDrawing();
    }
    // DE-INITIALIZATION
    UnloadTexture(player.playerTexture_idle);
    UnloadTexture(player.playerTexture_walk);
    UnloadTexture(target.targetTexture);

    CloseWindow();
    return 0;

}