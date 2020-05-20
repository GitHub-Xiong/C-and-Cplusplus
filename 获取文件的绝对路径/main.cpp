#include<stdio.h>
#include<io.h>
#include<string.h>
int main(){
    long Handle;
	struct _finddata_t FileInfo;
	char folderin[600] = "C:\\Users\\octob\\AppData\\Local\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets\\";//windows下‘\’需要加转义符'\'.
	char filename[600];//存放文件绝对路径
	memset(filename, '\0', 600);//初始化filename[600]
	int n = 0;//目标文件数计数
		if ((Handle = _findfirst("C:\\Users\\octob\\AppData\\Local\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets\\*", &FileInfo)) == -1L)
			printf("没有找到匹配的项目\n");
		else//存在第一个文件
		{
			if (FileInfo.size <= 10000) printf("这个不是目标文件\n");
			else {//第一个文件是目标文件时，执行
				n++;
				strcpy(filename, folderin);
				strcat(filename, FileInfo.name);
				printf("%s\n", filename);
				printf("数据大小为：%d\n", FileInfo.size);
				memset(filename, '\0', 600);//初始化filename[600]
			}
				while (_findnext(Handle, &FileInfo) == 0) {
					if (FileInfo.size <= 10000) printf("这个不是目标文件\n");
					else {
						n++;
						strcpy(filename, folderin);
						strcat(filename, FileInfo.name);
						printf("%s\n", filename);
						printf("数据大小为：%d\n", FileInfo.size);
						memset(filename, '\0', 600);//初始化filename[600]
					}
				}
		}
	printf("目标文件数为%d个\n", n);
    _findclose(Handle);
	return 0;
}