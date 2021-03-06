#include "UI.h"

Pov pov2_;

UI::UI()
{
    texture_ = NULL;
}

bool UI::init()
{
    //リトライ時の初期化に使用

    texture_ = Texture::load(L"Tetris11_SingleT.png");

    if (texture_ == NULL)
    {
        Error::showDialog("Tetris11_singleT.pngが読み込めません");

        //エラー
        return false;
    }

    return true;
}

void UI::update()
{
    const GamePad::State pad = Pad::getState();
    const Keyboard::State state = Key::getState();

    uipov = pov2_.update();

    if (state.C||pad.buttons.start)
    {
        pstart = 1;
    }
    else
    {
        pstart = 0;
    }

    if (state.LeftShift||pad.buttons.leftShoulder)
    {
        plb = 1;
    }
    else
    {
        plb = 0;
    }

    if (state.RightShift||pad.buttons.b)
    {
        pspace = 1;
    }
    else
    {
        pspace = 0;
    }

    if (state.Enter||pad.buttons.a)
    {
        penter = 1;
    }
    else
    {
        penter = 0;
    }
}

void UI::draw(int type)
{
    RECT rect;
    rect.top = 0;
    rect.left = 0;
    rect.bottom = rect.top + 720;
    rect.right = rect.left + 1280;

    if (type == tetoris_s)
    {
        Sprite::draw(texture_, Vector2::Zero,&rect);
    }
}

void UI::inputdraw(int type)
{
    //*******************************************
    //****************  type  *****************//
    // 1・タイトル
    // 2・ランキング・クレジット
    // 3・リザルト・オプション
    // 4・テトリスシングル
    // 5・ぷよぷよシングル
    // 6・テトリスマルチ
    //*******************************************

    if(type==Title_||type==result_option ||type == tetoris_s ||type == puyopuyo)
    {
        //十字キー
        RECT trim;
        trim.top = 725;
        trim.left = 5 + (230 * uipov) - 3 * uipov;
        trim.bottom = trim.top + 220;
        trim.right = trim.left + 220;

        Sprite::draw(texture_, Vector2(49, 425), &trim);
    }

    if (type!=tetris_multi)
    {
        //Aボタン
        RECT atrim;
        atrim.top = 463 + (128 * penter);
        atrim.left = 1536;
        atrim.bottom = atrim.top + 129;
        atrim.right = atrim.left + 128;

        Sprite::draw(texture_, Vector2(1002, 519), &atrim);
    }

    if(type==puyopuyo||type==tetoris_s)
    {
        //Bボタン
        RECT btrim;
        btrim.top = 463 + (pspace * 128);
        btrim.left = 1663;
        btrim.bottom = btrim.top + 129;
        btrim.right = btrim.left + 129;

        Sprite::draw(texture_, Vector2(1100, 320), &btrim);
    }

    if (type==tetoris_s)
    {
        //LBボタン
        RECT lbtrim;
        lbtrim.top = 464 + (plb * 128);
        lbtrim.left = 1280;
        lbtrim.bottom = lbtrim.top + 128;
        lbtrim.right = lbtrim.left + 128;

        Sprite::draw(texture_, Vector2(38, 230), &lbtrim);
    }

    if (type==result_option || type==tetoris_s || type==puyopuyo)
    {
        //STARTボタン
        RECT strim;
        strim.top = 336 + (pstart * 64);
        strim.left = 1920;
        strim.bottom = strim.top + 64;
        strim.right = strim.left + 128;

        Sprite::draw(texture_, Vector2(1063, 82), &strim);
    }


}

void UI::Hiddendraw()
{
    RECT rect;
    rect.top = 40;
    rect.left = 510;
    rect.bottom = rect.top + 133;
    rect.right = rect.left + 253;

    Sprite::draw(texture_,Vector2(510,40),&rect);

}

void UI::destroy()
{
    SAFE_RELEASE(texture_);
}