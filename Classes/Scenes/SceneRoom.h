﻿#ifndef __SCENE_ROOM_H__
#define __SCENE_ROOM_H__

#include "LayerBase.h"
#include "SceneBase.h"

class SceneRoom final : public SceneBase
{
public:
    static Scene* createScene();

    virtual bool init() override;
    virtual void updateLayer(Tag tag) override;
    virtual void updateScene(Tag tag) override;

    CREATE_FUNC(SceneRoom);
private:

    LayerBase * layerRoom;
    LayerBase * layerReady;
};

#endif //__SCENE_ROOM_H__s
