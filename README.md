# 基于STM32的智能避障小车

## 开发平台

- [x] STM32f103C8
- [x] 此项目开发平台为keil5

## 主要内容：

- 避障算法：通过超声波传感器感知前方障碍物的距离，根据感知到的距离信息，控制小车的速度和方向，以避开障碍物。避障算法的实现是项目中的关键部分，需要优化算法以提高避障的准确性和效率。

---

- 循迹导航：利用红外传感器感知地面情况，实现小车的循迹导航功能。根据传感器数据反馈控制，使小车能够按照预定路径行驶。

---

- STM32编程：使用C语言或汇编语言对STM32微控制器进行编程，实现上述功能以及与其他模块的通信。

---

## 使用方法

1. 安装Keil5并配置
2. 打开USER文件夹，双击.uvprojx文件
3. 烧录进stm32单片机
