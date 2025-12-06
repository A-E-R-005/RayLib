#include "target.h"
#include "raylib.h"

void Target::loading() {
    targetTexture = LoadTexture("../assets/Characters/Orc/Orc/Orc-Idle.png");
    targetPosition = {100.0f, 100.0f};
    targetRect = {targetPosition.x, targetPosition.y, 20, 15};
}

void Target::Draw(Rectangle sourceRect) {
    //targetRect.width = sourceRect.width;
    //targetRect.height = sourceRect.height;
    DrawTextureRec(targetTexture, sourceRect, targetPosition, WHITE);
}