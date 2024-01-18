源码参考：https://github.com/afiskon/stm32-st7735

0.96寸LCD的尺寸偏移：

```c
#define ST7735_XSTART 0
#define ST7735_YSTART 24
#define ST7735_WIDTH  160
#define ST7735_HEIGHT 80
```

常用函数：

```c
/**
 * @brief 设置液晶屏的显示方向（旋转）
 * @param rotation 旋转方向，取值范围为 0 到 3
 * @note  0: 正常显示, 1: 逆时针旋转 90 度, 2: 逆时针旋转 180 度, 3: 逆时针旋转 270 度
 */
void ST7735_SetRotation(uint8_t rotation)
```
