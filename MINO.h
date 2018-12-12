#pragma once


#define field_width 11
#define field_height 21

#define block_width 4
#define block_height 4

#include"texture.h"
#include"player.h"
#include"sprite.h"
#include"key.h"
#include"pad.h"
#include<ctime>



enum
{
    i, //棒
    o, //四角
    t, //T字
    j, //J字
    l, //L字
    s, //S字
    z  //Z字
};

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
    void create_block();

    //ミノ
    int back[22][12]; //流すよう配列
    int main[22][12]{ 0 };
    int sub[22][12] = { 0 }; //サブ
    int test[4][4] = {
        {0,0,0,0},
        {0,1,0,0},
        {0,1,1,0},
        {0,0,1,0}
    }; //流す用テスト
    int clearlinepos[21] = { 0 }; //横一列そろっている場所の確認用
    int tmp[4][4] = { 0 };

    int nowtime = 0;
    int oldtime = 0;

    int time = 1;

    //方向キー
    int up = 0;
    int down = 0;
    int pos = 0;

    //カウント
    int cnt = 0;
    bool downf = false;

    bool collision_left = false;
    bool collision_right = false;
    bool collision_down = false;

};