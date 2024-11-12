#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "BitmapObject.h"
#include "AnimatedObject.h"

class SpriteObject : public BitmapObject, public AnimatedObject {
public:
    void animate() override;
};

#endif // SPRITEOBJECT_H
