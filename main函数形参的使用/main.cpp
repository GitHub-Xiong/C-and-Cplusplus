#include<stdio.h>
int main(int argc, char *argv[]) {
	int i;
	printf("命令行参数有%d个，分别是：\n", argc);
	for (i = 0; i < argc; i++) {
		if (i == 0) printf("程序所在地址为%s\n", argv[i]);
		else printf("资源文件所在地址为%s\n", argv[i]);
	}
	if (i >= 2) {
		printf("资源文件所在地址为%s\n", argv[1]);
	}
}