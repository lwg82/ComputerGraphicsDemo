
#include <cstdio>

#include <easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>

int main(void)
{
	initgraph(640, 480);	// ������ͼ���ڣ���СΪ 640x480 ����
	circle(200, 200, 100);	// ��Բ��Բ��(200, 200)���뾶 100
	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
    return 0;
}