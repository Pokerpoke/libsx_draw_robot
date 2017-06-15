# 使用方法

- 执行以下命令
```shell
git clone https://github.com/Pokerpoke/libsx_draw_robot.git
cd libsx_draw_robot
mkdir build
cd build
cmake ..
make
cd app
cp ../../app/robot.lg ./
./robot
```
- 直接执行
```shell
./make.sh
```

# 说明

生成的可执行文件为`build/app/robot`,界面中`file`指令所需的文件是`robot.lg`,可以更改此文件来绘制不同图形.

# 指令

- FD 10
前进10个单位
- BK 10
后退10个单位
- TR 10
右转10度,以x轴为正向
- TL 10
左转10度
- COLOR GREEN
设置颜色,在`BLACK WHITE GREEN RED BLUE YELLOW`中选择
- DRAW
落笔,开始绘画
- UNDRAW
提笔

# 状态
- x、ｙ
坐标，左上角为(0,0)
- n
步进，移动的单位，默认为10
- degree
与ｘ轴的夹角，用以指示方向，默认为0