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
    void Alogic(float directionX);
};

#endif //SHEETANIMATION_H
