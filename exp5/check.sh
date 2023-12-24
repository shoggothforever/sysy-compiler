#!/bin/bash

# 检查是否提供了文件参数
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi
make
if [ $? -ne 0 ]; then
    echo "make failed "
    exit 1
fi
# 调用parsecpp可执行文件，传入文件参数
./parse "$1"

# 检查parse执行后的退出状态
if [ $? -ne 0 ]; then
    echo "parse failed "
    exit 1
fi

FILE=ast_output.txt
OUTPUT=ast_output.png
if [ ! -f "$FILE" ]; then
    touch $FILE
fi

# 执行Python脚本生成可视化图形
python3 visual.py

# 检查visual.py脚本执行后的退出状态
if [ $? -ne 0 ]; then
    echo "visual.py failed to run successfully."
    exit 1
fi

echo "AST visualization generated successfully."

make clean >/dev/null
if [ $? -ne 0 ]; then
    echo "make clean failed"
    exit 1
fi
