#pragma once
#include"texture.h"
#include"player.h"
#include"sprite.h"
#include"key.h"
#include"pad.h"
#include<ctime>

class Mino
{
private:
    ID3D11ShaderResourceView* texture_; //テクスチャ
public:
    Mino();

    bool init();
    bool update();
    void draw();
    void maindraw();
    void destroy();

    //ミノ
    int back[22][12]; //流すよう配列
    int main[22][12] = {            //積み上げる配列
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,0,0,0,0,0,0,0,0,0,0,9},
        {9,9,9,9,9,9,9,9,9,9,9,9},
    };
    int sub[22][12] = { 0 }; //サブ
    int test[4][4]; //流す用テスト
    int clearlinepos[21] = { 0 }; //横一列そろっている場所の確認用

    int nowtime = 0;
    int oldtime = 0;

    //方向キー
    int up = 0;
    int down = 0;
    int pos = 0;

    //カウント
    int cnt = 0;
    int acnt = 0;
    //フラグ
    bool advance = false;  //繰り上げ（そろった行を消す)
};