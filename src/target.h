#ifndef TARGET_H
#define TARGET_H
#include <raylib.h>

struct Target{
    Texture2D targetTexture;

    Vector2 targetPosition;
    Rectangle targetRect;

    void loading();
    void Boundaries();
    void Draw(Rectangle sourceRect);

};

#endif //TARGET_H
