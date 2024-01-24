

# 查看Keil编译工程后的内存大小

文件查找路径：“MDK-ARM/工程名/工程名.map”，使用记事本打开，直接拉到最后。

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

