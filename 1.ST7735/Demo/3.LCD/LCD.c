#include "ST7735.h"

extern TIM_HandleTypeDef htim4;
char str1[64] = {0};

void init_LCD(void)
{
    ST7735_Init();
    ST7735_SetRotation(3);
    ST7735_FillScreen(ST7735_BLACK);
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
    TIM4->CCR2 = 300; // PWM mode2，值越大屏幕越亮，最大值1000-1，使用手机拍摄时，屏幕亮度设为50
}

void LCD_test(void)
{
    static float i = 0.0f;
    snprintf(str1, 23, "i = %.1f", i);
    // ST7735_WriteString(0, 0, "FOC", Font_11x18, ST7735_RED, ST7735_BLACK);
    // // ST7735_WriteString(40, 0, "MODE1", Font_11x18, ST7735_RED, ST7735_BLACK);
    // // ST7735_WriteString(0, 18, "U=5.68V", Font_11x18, ST7735_GREEN, ST7735_BLACK);
    // // ST7735_WriteString(0, 38, "V=6.23V", Font_11x18, ST7735_BLUE, ST7735_BLACK);
    // // ST7735_WriteString(0, 60, "W=3.26V", Font_11x18, ST7735_YELLOW, ST7735_BLACK);
    // snprintf(str1, 23, "i = %.1f", i);

    i = i + 0.3f;
    ST7735_DrawString(0, 0, "Hello World 123456789", ST7735_RED, ST7735_BLACK, &Font_11x18);
    ST7735_DrawString(0, 40, str1, ST7735_YELLOW, ST7735_BLACK, &Font_11x18);

    // HAL_Delay(10);
    // ST7735_FillScreen(ST7735_RED);
    // HAL_Delay(500);
    // ST7735_FillScreen(ST7735_GREEN);
    // HAL_Delay(500);
    // ST7735_FillScreen(ST7735_BLUE);
    // HAL_Delay(500);
    // ST7735_DrawString(0, 0, "Hello", ST7735_BLUE, ST7735_BLACK, &Font_11x18);
}
