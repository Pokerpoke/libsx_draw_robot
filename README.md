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