#!/bin/bash
# 查找当前目录及子目录下所有的.cpp文件，并统计行数
find . -name '*.cpp' -o -name '*.h' | xargs grep -Ev "^$|^//" | wc -l


