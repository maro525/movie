#ifndef MyChar_h
#define MyChar_h

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

class MyChar {
public:
    void setup(int _fontsize, float _letterspacing);
    void drawRandom(int _char_num, int _row, int _column);
    void drawChar(string _str, float _posx, float _posy);
    void drawBand();
    void drawSong();
    
private:
    vector< string > separateUTF8String( string _srcStr );
    
    ofxTrueTypeFontUC verdana;
    int fontSize;
    
    int fps = 10;
    
    bool draw = true;
    bool counting_flag = true;
    int drawRandom_num = 1;
    
    float move_length = 460.0;
    float move_speed = 20.0;
    
    float bandposx = 500.0;
    float bandstartposx = bandposx;
    int drawband_counter = 0;
    
    float songposx = 960.0;
    float songstartposx = songposx;
    int drawsong_counter = 0;
    
    string char_band = "02美声BUT5U";
    string char_song = "Mary, Did You Know?";
    
    vector< string > letter_band;
    vector< string > letter_song;

};


#endif /* MyChar_h */
