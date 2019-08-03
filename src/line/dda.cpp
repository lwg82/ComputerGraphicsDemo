
#include <cstdio>

#include <easyx.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <math.h>

/**
 * Digital Differential Analyzer DDA ��ֵ΢�ַ�����
 * y = kx + b
 * 0 < |k| <=1  y[i+1] = yi + k
 * |k| > 1      x[i+1] = xi + 1/k
 */
void line_dda(int x0, int y0, int x1, int y1, COLORREF clr)
{
	double dx = x1 - x0;
	double dy = y1 - y0;

	double k = dy / dx; // б��

	double y = y0 + 0.5;
	double x = x0 + 0.5;
	int   step = 0;   // ������ÿ�μ�1

	if (fabs(k) > 1)
	{
		while ((y + step) < y1)
		{
			int xp = static_cast<int>(x);
			int yp = static_cast<int>(y + step);

			putpixel(xp, yp, clr);

			step++;
			x += 1 / k;
		}
	}
	else
	{
		while ((x + step) < x1)
		{
			int xp = static_cast<int>(x + step);
			int yp = static_cast<int>(y);

			putpixel(xp, yp, clr);

			step++;
			y += k;
		}
	}

	

}

int main(void)
{
	initgraph(640, 480);	// ������ͼ���ڣ���СΪ 640x480 ����
	
	// ��������ԭ��
	setorigin(320, 240);

	line_dda(0, 0, 50, 100, RGB(0, 255, 0));
	line_dda(0, 0, 50, 50, RGB(255, 0, 0));
	
	
	

	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
    return 0;
}
