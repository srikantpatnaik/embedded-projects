#include <U8glib.h>

// http://forums.4fips.com/viewtopic.php?f=3&p=1610
// https://github.com/olikraus/u8glib/wiki/tdisplaysetup
// https://github.com/olikraus/u8glib/wiki/tstring
// http://www.instructables.com/id/DIY-Arduino-temperature-sensor/?ALLSTEPS
// http://henrysbench.capnfatz.com/henrys-bench/u8glib-arduino-oled-tutorial-1-hello-world-on-steroids/

// SCK/Clk = 13, MOSI/Din = 11, CS/CE = 10,
// A0/RS/DC = 9, Reset/Rst = 8
U8GLIB_PCD8544 u8g(13, 11, 10, 9, 8); 

void draw(){
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(5, 22, "gnu-linux.org");
    u8g.drawStr(24, 35, "2015");
}

void setup(){
    u8g.setColorIndex(1); // pixel on
}

void loop(){
    u8g.firstPage();
    do{
        draw();
    } while(u8g.nextPage());
    delay(500);
}
