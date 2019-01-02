#include "MyChar.h"

void MyChar::setup(int _fontsize, float _letterspacing) {
    
    letter_band = separateUTF8String(char_band);
    letter_song = separateUTF8String(char_song);

    
    verdana.load("NotoSansCJKjp-Black.otf", _fontsize);
    verdana.setLineHeight(24);
    verdana.setLetterSpacing(_letterspacing);

}


// 参考 : http://qiita.com/watabo_shi/items/e1217a4e2cd60502bba0
vector<string> MyChar::separateUTF8String( string _srcStr )
{
    vector< string > letters;
    
    for( int i = 0; i < _srcStr.length(); ++i )
    {
        string bin_str = ofToBinary( _srcStr.at( i ) );
        
        // 1 byte character
        if( bin_str.find( "0" ) == 0 )
        {
            letters.push_back( ofToString( _srcStr.at( i ) ) );
        }
        // 2 byte character
        else if( bin_str.find( "110" ) == 0 )
        {
            letters.push_back( ofToString( _srcStr.at( i ) ) + ofToString( _srcStr.at( i + 1 ) ) );
        }
        // 3 byte character
        else if( bin_str.find( "1110" ) == 0 )
        {
            letters.push_back( ofToString( _srcStr.at( i ) ) + ofToString( _srcStr.at( i + 1 ) ) + ofToString( _srcStr.at( i + 2 ) ) );
        }
        // continue byte ( second or later byte )
        else if( bin_str.find( "10" ) == 0  )
        {
            
        }
    }
    
    return letters;
}


// 文字を書く関数
void MyChar::drawChar(string _str, float _posx, float _posy) {
    
    ofTrueTypeFont::setGlobalDpi(72);
    
    ofSetColor(255);
    float charW = verdana.stringWidth("W");
    float charH = verdana.stringHeight("W");
    float charX = _posx - charW/2;
    float charY = _posy + charH/2;
    verdana.drawString(_str, charX, charY);
}


// 3個のときとか上手くいかない
void MyChar::drawRandom(int _char_num, int _column, int _row) {
    
    float posx[_char_num];
    float posy[_char_num];
    int index[_char_num];
    bool char_draw[_char_num];
    for (int i = 0; i < _char_num; i++) char_draw[i] = true;
    
    // 一定間隔ごとにフラッグ切り替え＆関数実行カウンタ
    if(ofGetFrameNum() % (30/fps) == 0 && counting_flag) {
        draw = !draw;
        drawRandom_num += 1;
    }
    
    // １つ１つの数字に座標と文字のインデックスを当てる
    for(int a = 0; a < _row; a++) {
        
        float y_height = ofGetHeight() * (a+1) / (_row+1);
        
        for (int b = 0; b < _column; b++) {
        
            float x_width = ofGetWidth() * (b+1) / (_column+1);
            
            posx[a*_column + b] = x_width;
            posy[a*_column + b] = y_height;
            index[a*_column + b]  = (drawRandom_num + a + b) % letter_band.size();
        }
        
    }
    
    // ドロー
    for(int i = 0; i < _char_num; i++) {
        
        int t = 90;
        if(ofGetFrameNum() > t && i == 0) index[i] = 2;
        t += 15;
        if(ofGetFrameNum() > t && i == 1) index[i] = 3;
        t += 15;
        if(ofGetFrameNum() > t && i == 2) index[i] = 6;
        if(ofGetFrameNum() > t && i == 3) index[i] = 4;
        t += 15;
        if(ofGetFrameNum() > t && i == 4) index[i] = 0;
        if(ofGetFrameNum() > t && i == 5) index[i] = 1;
        t += 15;
        if(ofGetFrameNum() > t && i == 6) index[i] = 8;
        t += 15;
        if(ofGetFrameNum() > t && i == 7) index[i] = 7;
        t += 15;
        if(ofGetFrameNum() > t && i == 8) index[i] = 5;
        
        
        if(ofGetFrameNum() > t && i == 0) char_draw[i] = false;
        t += 20;
        if(ofGetFrameNum() > t && i == 7) char_draw[i] = false;
        t += 20;
        if(ofGetFrameNum() > t && i == 1) char_draw[i] = false;
        t += 20;
        if(ofGetFrameNum() > t && i == 6) char_draw[i] = false;
        t += 20;
        if(ofGetFrameNum() > t && i == 2) char_draw[i] = false;
        t += 20;
        if(ofGetFrameNum() > t && i == 8) char_draw[i] = false;
        t += 20;
        if(ofGetFrameNum() > t && i == 3) char_draw[i] = false;
        
        
        t += 30;
        if(ofGetFrameNum() > t && i == 4) posx[i] += 20.0;
        if(ofGetFrameNum() > t && i == 5) posx[i] -= 20.0;
        t += 20;
        if(ofGetFrameNum() > t && i == 4) posx[i] += 60.0;
        if(ofGetFrameNum() > t && i == 5) posx[i] -= 60.0;
        t += 10;
        if(ofGetFrameNum() > t && i == 4) posx[i] += 10.0;
        if(ofGetFrameNum() > t && i == 5) posx[i] -= 10.0;
        t += 30;
        if(ofGetFrameNum() > t && i == 0) { char_draw[i] = true; posx[i] = 600; posy[i] = ofGetHeight()/2; }
        t += 30;
        if(ofGetFrameNum() > t && i == 1) { char_draw[i] = true; posx[i] = 630; posy[i] = ofGetHeight()/2; }
        t += 10;
        if(ofGetFrameNum() > t && i == 3) { char_draw[i] = true; posx[i] = 660; posy[i] = ofGetHeight()/2;}
        t += 10;
        if(ofGetFrameNum() > t && i == 8) { char_draw[i] = true; posx[i] = 680; posy[i] = ofGetHeight()/2; fps = 4;}
        t += 10;
        if(ofGetFrameNum() > t && i == 2) { char_draw[i] = true; posx[i] = 700; posy[i] = ofGetHeight()/2; }
        t += 10;
        if(ofGetFrameNum() > t && i == 7) { char_draw[i] = true; posx[i] = 720; posy[i] = ofGetHeight()/2; counting_flag = false;}
        t += 10;
        if(ofGetFrameNum() > t && i == 6) { char_draw[i] = true; posx[i] = 740; posy[i] = ofGetHeight()/2; }
        t += 30;
        if(ofGetFrameNum() == t) ofTranslate(50.0, 0);
        
        
        
        if(draw && char_draw[i]) {
            drawChar(letter_band[index[i]], posx[i], posy[i]);
        }
        
    }

}

void MyChar::drawBand() {
    
    drawRandom_num += 1;
    
    // 一定間隔ごとにフラッグ切り替え＆関数実行カウンタ
    if(ofGetFrameNum() % (30/fps) == 0 && drawRandom_num > 60) draw = !draw;
    
    if(drawRandom_num > 210) draw = true;
    
    if (fps != 10) fps = 10;
    
    bool band_move = false;
    drawband_counter += 1;
    if (drawband_counter > 90) band_move = true;
    
    if (bandposx == bandstartposx - move_length) band_move = false;
    
    if (band_move && ofGetFrameNum() % (30/fps) == 0) bandposx -= move_speed;
    
    if(draw) drawChar("02 美声BUT5U", bandposx, ofGetHeight()/2);
}

void MyChar::drawSong() {
    
    drawRandom_num += 1;
    
    // 一定間隔ごとにフラッグ切り替え＆関数実行カウンタ
    if(ofGetFrameNum() % (30/fps) == 0 && drawRandom_num > 20) draw = !draw;
    
    if(drawRandom_num > 210) draw = true;
       
    if (fps != 10) fps = 10;
    
    bool song_move = false;
    drawsong_counter += 1;
    if(drawsong_counter > 90) song_move = true;
    
    if(songposx == songstartposx - move_length) song_move = false;
    
    if(song_move && ofGetFrameNum() % (30/fps) == 0) songposx -= move_speed;
    
    if (draw) drawChar(char_song, songposx, ofGetHeight()/2);
}
