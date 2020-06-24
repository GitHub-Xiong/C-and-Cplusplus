#include"copyfile.h"
void main()
{
	FILE *p;
	//unsigned   //const 修饰char 所以不兼容
    char wbuffer[1024] = "Merry Christmas\n";//写流缓存
	char rbuffer[1024]; memset(rbuffer, '\0', 1024);//读流缓存
	p = fopen("test.txt", "wb");
	memset(wbuffer, '\0', 1024);
	scanf("%s", wbuffer);
	printf("%s\n", wbuffer);
	fprintf(p, wbuffer);
	fseek(p, 0, SEEK_SET);
	fscanf(p, "%s", rbuffer);
	fseek(p, 0, SEEK_SET);
	printf("字符=%d\n", fgetc(p));
	//fwrite(wbuffer, 1, strlen(wbuffer), p);
	//fseek(p, 0, SEEK_CUR);
    //fread(rbuffer, 1, strlen(wbuffer), p);
	//fseek(p, 0, SEEK_END);
	//if (feof(p) == 0) printf("文件没有读写到末尾\n");
	//fprintf(p, "good morning\n");
	fclose(p);
	printf("%s\n", rbuffer);
	//copyfile("test.txt", "test1.txt");
	getchar();
	getchar();
}