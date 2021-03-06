#include"title.h"

// コンストラクタ
Title::Title()
{  
    texture_ = NULL;
    
}

//デストラクタ
Title::~Title()
{
}

Pov pov_;

//初期化
bool Title::init()
{
    //テクスチャの読み込み
    if( !(texture_ = Texture::load( L"Tetris10_Title.png" )) )
    {

        Error::showDialog("タイトル.pngの読み込みに失敗");

        //エラー
        return false;
    }

    return true;
}

//更新
int Title::update()
{
    //ゲームパットの入力を取得
    const GamePad::State pad = Pad::getState();
    const GamePad::State pad2 = Pad::getState2();
    const GamePad::ButtonStateTracker pad_tracker = Pad::getTracker();

    // キーボードの入力を取得
    const Keyboard::State state = Key::getState();
    const Keyboard::KeyboardStateTracker key_tracker = Key::getTracker();
    

    pov = pov_.update();

    if (state.Enter||pad.buttons.a)
    {
        penter = 1;
    }
    else
    {
        penter = 0;
    }

    // 上が押されたら
    if (key_tracker.pressed.Up || pad_tracker.dpadUp == GamePad::ButtonStateTracker::PRESSED)
    {
        Adx::play(9);
        menu--;

    }
    // 上が押されたら
    if (key_tracker.pressed.Down || pad_tracker.dpadDown == GamePad::ButtonStateTracker::PRESSED)
    {
        Adx::play(9);

        menu++;
    }

    if (menu == 0 && (key_tracker.pressed.Enter|| pad_tracker.a == GamePad::ButtonStateTracker::PRESSED))
    {
        Adx::play(10);

        return 2; //テトリスシングル
    }
    else if (menu == 1 && (key_tracker.pressed.Enter || pad_tracker.a == GamePad::ButtonStateTracker::PRESSED))
    {
        Adx::play(10);

        return 3; //ランキング
    }
    else if (menu == 2 && (key_tracker.pressed.Enter || pad_tracker.a == GamePad::ButtonStateTracker::PRESSED))
    {
        Adx::play(0); //4人テトリス（いけない）

    }
    else if (menu == 3 && (key_tracker.pressed.Enter|| pad_tracker.a == GamePad::ButtonStateTracker::PRESSED))
    {
        Adx::play(10);

        return 4; //オプション
    }
    else if (menu == 4 && (key_tracker.pressed.Enter|| pad_tracker.a == GamePad::ButtonStateTracker::PRESSED))
    {
        Adx::play(10);

        return 5; //クレジット
    }
    else if (menu == 5 && (key_tracker.pressed.Enter || pad_tracker.a == GamePad::ButtonStateTracker::PRESSED))
    {
        Adx::play(0); //ぷよぷよ（いけない）
    }

    // メニューのループ
    if (menu > 5)
    {
        menu = 0;
    }

    if (menu < 0)
    {
        menu = 5;
    }
    return 1;

}

//描画
void Title::draw()
{

    RECT rect;

    rect.top = 0;
    rect.left = 0;
    rect.bottom = rect.top + 720;
    rect.right = rect.left + 1280;

    Sprite::draw(texture_, Vector2::Zero, &rect);
}

void Title::dpaddraw()
{
    RECT trim;

    trim.top = 725;
    trim.left = 5 + (230 * pov)-3*pov;
    trim.bottom = trim.top + 220;
    trim.right = trim.left + 220;

    Sprite::draw(texture_, Vector2(49,425), &trim);

}

void Title::buttondraw()
{

    RECT btrim;
    btrim.top = 463+(129*penter);
    btrim.left = 1536;
    btrim.bottom = btrim.top+129;
    btrim.right = btrim.left + 128;

    Sprite::draw(texture_, Vector2(1002, 519), &btrim);

}

void Title::cursordraw()
{
    RECT ctrim;

    ctrim.top = 947;
    ctrim.left = 1201;
    ctrim.bottom = ctrim.top + 35;
    ctrim.right = ctrim.left + 265;

    Sprite::draw(texture_, Vector2(505, 322+(menu*42)), &ctrim);

}

//破棄
void Title::destroy()
{
    //テクスチャの解放
    SAFE_RELEASE( texture_ );
}