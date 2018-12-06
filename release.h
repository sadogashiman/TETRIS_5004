#pragma once

//関数形式マクロ
#define SAFE_RELEASE(x) {if(x){ x -> Release(); x = NULL;}}

//メモリの解放
#define SAFE_DELETE(x) {delete x; x = NULL;}            //1つ

#define SAFE_DELETE_ARRAY(x) {delete[] x; x = NULL;}      //配列
