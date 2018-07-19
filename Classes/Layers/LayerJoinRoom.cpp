﻿#include "Helpers.h"
#include "LayerJoinRoom.h"
#include "ServiceAPI.h"

LayerBase* LayerJoinRoom::createLayer()
{
    return LayerJoinRoom::create();
}

bool LayerJoinRoom::init()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();


    auto buttonBack = MenuItemImage::create("Graphics/System/BtnBack.png", "Graphics/System/BtnBack_click.png",
        CC_CALLBACK_1(LayerJoinRoom::backMenu, this));

    buttonBack->setPosition(Vec2(150, visibleSize.height - 50));

    auto menu = Menu::create();
    menu->setPosition(origin);
    menu->addChild(buttonBack);

    // 定时扫描
    schedule(schedule_selector(LayerJoinRoom::getRoomList), 2.0f, kRepeatForever, 0);

    this->addChild(menu, 1);

    return true;
}

void LayerJoinRoom::backMenu(Ref* pSender)
{
    if (!this->getActive()) return;
    this->updateLayer(Tag::LayerFromJoinRoomOrNewRoomToMenu);
}

void LayerJoinRoom::getRoomList(float dt)
{
    // todo 获取房间列表API
    if (this->getActive() == false) return;
    auto d = Singleton<ServiceAPI>::GetInstance()->GetRoomsList(1, 5);
    if (!d.HasParseError() && d.IsObject() && d.HasMember("status"))
    {
        if (strcmp(d["status"].GetString(), "success") == 0)
        {

            // 根据数据生成房间列表
        }
        else
        {
            // 参数错误的提示
        }
    }
    else
    {
        // 解析失败的提示
        return;
    }
}
