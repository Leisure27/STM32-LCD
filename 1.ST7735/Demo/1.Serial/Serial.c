#include <stdio.h>
#include "usart.h"
#include <string.h>
#include <stdarg.h>

/**
 * @brief 阻塞式发送数据
 * @note  USART1
 * @param format 格式化字符串，该字符串可以包含格式说明符
 * @retval 无
 */
void log_block(const char *format, ...)
{
    va_list args;           // 定义参数列表变量
    va_start(args, format); // 从format位置开始接收参数表，放在arg里面

    char strBuf[256]; // 定义输出的字符串

    // 使用vsnprintf将格式化的数据写入缓冲区，并进行溢出检查
    if (vsnprintf(strBuf, sizeof(strBuf), format, args) >= sizeof(strBuf))
    {
        // 缓冲区溢出处理
        HAL_UART_Transmit(&huart1, (uint8_t *)"Log message truncated!\r\n", 24, 100);
    }
    else
    {
        HAL_UART_Transmit(&huart1, (uint8_t *)strBuf, strlen(strBuf), 100);
    }

    va_end(args); // 结束可变参数的使用
}

/**
 * @brief DMA式发送数据
 * @note  USART1
 * @param format 格式化字符串，该字符串可以包含格式说明符
 * @retval 无
 */
void log_dma(const char *format, ...)
{
    va_list args;           // 定义参数列表变量
    va_start(args, format); // 从format位置开始接收参数表，放在arg里面

    char strBuf[256]; // 定义输出的字符串

    // 使用vsnprintf将格式化的数据写入缓冲区，并进行溢出检查
    if (vsnprintf(strBuf, sizeof(strBuf), format, args) >= sizeof(strBuf))
    {
        // 缓冲区溢出处理
        HAL_UART_Transmit(&huart1, (uint8_t *)"Log message truncated!\r\n", 24, 100);
    }
    else
    {
        // 使用DMA进行串口传输
        HAL_UART_Transmit_DMA(&huart1, (uint8_t *)strBuf, strlen(strBuf));

        // 等待DMA传输完成
        uint32_t timeout = HAL_GetTick() + 100; // Adjust the timeout value as needed
        while (HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX)
        {
            if (HAL_GetTick() > timeout)
            {
                // Handle timeout error
                break;
            }
        }
    }

    va_end(args); // 结束可变参数的使用
}
