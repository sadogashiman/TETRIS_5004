//*****************************************************************************
//  Include
//*****************************************************************************
#include "key.h"


//*****************************************************************************
//  実体の宣言
//*****************************************************************************
Keyboard Key::key_;
Keyboard::State Key::state_;
Keyboard::KeyboardStateTracker Key::key_tracker_;

//*****************************************************************************
//  初期化
//*****************************************************************************
void Key::update()
{
    // 入力状態を取得
    state_ = key_.GetState();

    // トラッカーを更新
    key_tracker_.Update( state_ );
}