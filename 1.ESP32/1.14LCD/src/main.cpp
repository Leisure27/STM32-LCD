#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI(); // 创建TFT对象

void setup()
{
  tft.init(); // 初始化
  tft.setRotation(1);
  analogWrite(TFT_BL, 150);
  tft.fillScreen(TFT_BLACK); // 设置屏幕背景颜色

  tft.setTextColor(TFT_WHITE, TFT_BLACK); // 参数1：字体颜色，参数2：背景色

  tft.setTextFont(4); // 字体大小16*16
  tft.println("Hello,world");

  tft.setTextFont(4);                     // 字体大小26*26
  tft.setTextColor(TFT_GREEN, TFT_BLACK); // 参数1：字体颜色，参数2：背景色
  tft.drawNumber(1234, 0, 30);
  tft.setTextColor(TFT_RED, TFT_BLACK); // 参数1：字体颜色，参数2：背景色
  tft.drawFloat(3.14159, 5, 0, 60);
}

void loop()
{
  // put your main code here, to run repeatedly:
}
