参考资料：

> 1.https://github.com/afiskon/stm32-st7735/blob/master/st7735/st7735.c    
>
> 2.https://blog.csdn.net/Xiaowu12345678910/article/details/129038133

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

# 测试程序

屏幕颜色测试：

```c
    ST7735_FillScreen(ST7735_RED);
    HAL_Delay(500);
    ST7735_FillScreen(ST7735_GREEN);
    HAL_Delay(500);
    ST7735_FillScreen(ST7735_BLUE);
    HAL_Delay(500);
```

显示字符串：

```c
 ST7735_DrawString(0, 0, "Hello World", ST7735_RED, ST7735_BLACK, &Font_11x18);
```

显示变量：

```c
    static float i = 0.0f;
    snprintf(str1, 23, "i = %.1f", i);
    i = i + 0.3f;
    ST7735_DrawString(0, 0, "Hello World", ST7735_RED, ST7735_BLACK, &Font_11x18);
    ST7735_DrawString(0, 20, str1, ST7735_YELLOW, ST7735_BLACK, &Font_11x18);
```

显示变量的工程，程序编译大小：

```c
    Total RO  Size (Code + RO Data)                28036 (  27.38kB)
    Total RW  Size (RW Data + ZI Data)              2456 (   2.40kB)
    Total ROM Size (Code + RO Data + RW Data)      28056 (  27.40kB)
```

- **Flash (ROM):** Total ROM Size (Code + RO Data + RW Data) 是 28056 字节，或者27.40KB。这表示程序在Flash（只读存储器）中占用了27.40KB的空间。
- **RAM:** Total RW Size (RW Data + ZI Data) 是 2456 字节，或者2.40KB。这表示程序在RAM（随机存储器）中占用了2.40KB的空间。

## 程序内存分配

- Code：编译后的程序机器代码，占用了只读存储器(ROM)的一部分。包括程序的执行指令，用于实现程序的逻辑和功能。
- RO Data：只读数据(只读存储器，如Flash存储器，有助于减少RAM的使用，并提高程序的运行效率)，在程序运行时不会被修改的数据：常量、只读变量
- RW Data：读写数据，指程序在运行时使用的数据：全局变量、静态变量、以及在程序运行时动态分配的内存。
- ZI Data：零初始化数据，在程序启动时被初始化为零值的数据。

**RAM = RW Data + ZI Data**

**Flash(ROM) = Code + RO Data + RW Data**

