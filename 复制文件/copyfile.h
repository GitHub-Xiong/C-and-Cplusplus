#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*返回值  0 成功拷贝 1 文件名错误 2打开源文件失败
3 打开目标文件失败 4 读文件错误 5 写文件错误*/
int copyfile(char *SRCfile, char *targrtfile);