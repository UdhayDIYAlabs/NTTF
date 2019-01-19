#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(9600);
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB12_tr);
  pinMode(A0, INPUT);
}

void loop() {
  int a = analogRead(A0);
  Serial.println(a);
  u8g2.clearBuffer();
  u8g2.drawStr(0, 20, "Val: ");
  u8g2.setCursor(54, 20);
  u8g2.print(a);
  u8g2.sendBuffer();
}
