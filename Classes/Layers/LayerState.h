﻿#ifndef _LAYER_STATE_H__
#define _LAYER_STATE_H__

#include "LayerBase.h"

class LayerState final : public LayerBase
{
public:
    static LayerBase* createLayer();

    virtual bool init() override;

    CREATE_FUNC(LayerState);

private:
    ProgressTimer* hpBar;
};

#endif // _LAYER_STATE_H__
