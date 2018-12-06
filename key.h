//*****************************************************************************
//  Copyright (C) 2018 KOUDO All Rights Reserved.
//*****************************************************************************
#pragma once


//*****************************************************************************
//  Include
//*****************************************************************************
#include <Windows.h>
#include <Keyboard.h>


//*****************************************************************************
//  名前空間
//*****************************************************************************
using namespace DirectX;


//*****************************************************************************
//  Class
//*****************************************************************************
class Key
{
private:
    static Keyboard key_;          // キーボードクラス
    static Keyboard::State state_; // 入力情報格納構造体
    static Keyboard::KeyboardStateTracker key_tracker_;

public:
    static void update();  // 更新処理
    static const Keyboard::State& getState() { return state_; } // 入力情報を返す
    static const Keyboard::KeyboardStateTracker& getTracker() { return key_tracker_; }
};