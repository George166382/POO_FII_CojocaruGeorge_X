#include "Canvas.h"
#include <iostream>
#include <cmath>
Canvas::Canvas(int width, int height)
{
	this->mat = new char*[height];
	for (int i = 0; i < height; i++)
	{
		this->mat[i] = new char[width];
	}
	this->width = width;
	this->height = height;
}
Canvas::~Canvas()
{
	for (int i = 0; i < this->height; i++)
	{
		char *m = this->mat[i];
		delete[] m;
		std::cout << "Distrus\n";
	}
	delete[] this->mat;
	std::cout << "Distrus complet\n";
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1)) && ((i - x
				) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1)))
			{
				mat[i][j] = ch;
			}
			else
			{
				mat[i][j] = ' ';
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				mat[i][j] = ch;
			}
			else
			{
				mat[i][j] = ' ';
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if ((i == top && (j>=left&&j<=right)) || (i == bottom && (j >= left && j <= right)) || (j == left && (i >= top && i <= bottom)) || (j == right && (i >= top && i <= bottom)))
			{
				mat[i][j] = ch;
			}
			else
			{
				mat[i][j] = ' ';
			}
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			if (i >= top && i <= bottom && j >= left && j <= right)
			{
				mat[i][j] = ch;
			}
			else
			{
				mat[i][j] = ' ';
			}
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x < this->height && y>0 && y < this->width)
	{
		this->mat[x][y] = ch;
	}
	else
	{
		this->mat[x][y] = ' ';
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2,char ch) {
	if (abs(y2 - y1) < abs(x2 - x1)) {
		if (x1 > x2) {
			int aux = x1;
			x1 = x2;
			x2 = aux;
			aux = y1;
			y1 = y2;
			y2 = aux;
		}
		int dx = x2 - x1;
		int dy = y2 - y1;
		int yi = 1;
		if (dy < 0) {
			yi = -1;
			dy = -dy;
		}
		int D = 2 * dy - dx;
		int y = y1;

		for (int x = x1; x <= x2; x++) {
			SetPoint(x, y, ch);
			if (D > 0) {
				y = y + yi;
				D = D - 2 * dx;
			}
			D = D + 2 * dy;
		}
	}
	else {
		if (y1 > y2) {
			int aux = x1;
			x1 = x2;
			x2 = aux;
			aux = y1;
			y1 = y2;
			y2 = aux;
		}
		int dx = x2 - x1;
		int dy = y2 - y1;
		int xi = 1;
		if (dx < 0) {
			xi = -1;
			dx = -dx;
		}
		int D = 2 * dx - dy;
		int x = x1;

		for (int y = y1; y <= y2; y++) {
			SetPoint(x, y, ch);
			if (D > 0) {
				x = x + xi;
				D = D - 2 * dy;
			}
			D = D + 2 * dx;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			std::cout << mat[i][j];
		}
		std::cout << '\n';
	}
}


void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			this->mat[i][j] = ' ';
}