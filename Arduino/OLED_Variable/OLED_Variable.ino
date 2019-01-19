#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
int a;

void setup(void) {
  u8g2.begin();
  u8g2.clearBuffer();          // clear the internal memory
  u8g2.setFont(u8g2_font_ncenB12_tr); // choose a suitable font

}

void loop(void) {
  a += 1;
  String b = "Hello!  ";
  b += a;
  char *z = b.c_str();
  u8g2.drawStr(0, 20, z);
  u8g2.sendBuffer();
  u8g2.clearBuffer();
  delay(100);

}
