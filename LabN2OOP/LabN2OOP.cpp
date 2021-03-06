﻿#include <iostream>

using namespace std;

class Point {	// Интерфейс
protected:
	virtual void print() = NULL;	// Виртуальный метод вывода

public:
	Point() {	// Конструктор
		cout << "Point()\n";
	}
	~Point() {	// Деструктор
		cout << "~Point()\n";
	}
};

class Point2D : public Point {	// Точка в 2-х мерном пространстве
protected:
	double x;
	double y;

public:
	Point2D() {	// Конструктор
		x = 0;
		y = 0;
		cout << "Point2D()\n";
	}
	Point2D(double x, double y) {	// Конструктор
		this->x = x;
		this->y = y;
		cout << "Point2D(double x, double y)\n";
	}
	Point2D(const Point2D& p) {	// Конструктор копирования
		x = p.x;
		y = p.y;
		cout << "Point2D(const Point2D& p)\n";
	}
	~Point2D() {	// Деструктор
		cout << "~Point2D()\n";
	}
	void set(double x, double y) {	// Установка значений
		this->x = x;
		this->y = y;
	}
	void print() {	// Вывод
		cout << "x=" << this->x << " , y=" << this->y << " , dist=" << getdist() << endl;
	}
	void setX(double x) {	// Утановка x
		this->x = x;
	}
	void setY(double y) {	// Утановка y
		this->y = y;
	}
	double getX() {	// Получение x
		return x;
	}
	double getY() {	// Получение y
		return y;
	}
private:
	double getdist() {	// Получение расстояния до центра
		return sqrt(x * x + y * y);
	}
};

class Point3D : public Point2D {
protected:
	double z;

public:
	Point3D() {	// Конструктор
		z = 0;
		cout << "Point3D()\n";
	}
	Point3D(double x, double y, double z) {	// Конструктор
		this->x = x;
		this->y = y;
		this->z = z;
		cout << "Point3D(double x, double y, double z)\n";
	}
	Point3D(const Point3D& p) {	// Конструктор копирования
		x = p.x;
		y = p.y;
		z = p.z;
		cout << "Point3D(const Point3D& p)\n";
	}
	~Point3D() {	// Деструктор
		cout << "~Point3D()\n";
	}
	void set(double x, double y, double z) {	// Установка значений
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void print() {	// Вывод
		cout << "x=" << this->x << " , y=" << this->y << " , z=" << this->z << " , dist=" << getdist() << endl;
	}
	void setZ(double z) {	// Утановка z
		this->z = z;
	}
	double getZ() {	// Получение z
		return z;
	}
private:
	double getdist() {	// Получение расстояния до центра
		return sqrt(x * x + y * y + z * z);
	}
};

class Line {	// Интерфейс
protected:
	virtual void print() = NULL;	// Виртуальный метод вывода

public:
	Line() {	// Конструктор
		cout << "Line()\n";
	}
	~Line() {	// Деструктор
		cout << "~Line()\n";
	}
};

class Line2D : public Line {
protected:
	Point2D* p1;
	Point2D* p2;

public:
	Line2D() {	// Конструктор
		p1 = new Point2D;
		p2 = new Point2D;
		cout << "Line2D()\n";
	}
	Line2D(double x1, double y1, double x2, double y2) {	// Конструктор
		p1 = new Point2D(x1, y1);
		p2 = new Point2D(x2, y2);
		cout << "Line2D(double x1, double y1, double x2, double y2)\n";
	}
	Line2D(const Line2D& l) {	// Конструктор копирования
		p1 = new Point2D(*(l.p1));
		p2 = new Point2D(*(l.p2));
		cout << "Line2D(const Line2D& l)\n";
	}
	~Line2D() {	// Деструктор
		delete p1;
		delete p2;
		cout << "~Line2D()\n";
	}
	void print() {	// Вывод
		cout << "p1: ";
		(*p1).print();
		cout << "p2: ";
		(*p2).print();
	}
	void set(Point2D* p1, Point2D* p2) {	// Установка значений
		delete this->p1;
		delete this->p2;
		this->p1 = new Point2D(*p1);
		this->p2 = new Point2D(*p2);
	}
	void setP1(Point2D* p1) {	// Утановка p1
		delete this->p1;
		this->p1 = new Point2D(*p1);;
	}
	void setP2(Point2D* p2) {	// Утановка p2
		delete this->p2;
		this->p2 = new Point2D(*p2);;
	}
	Point2D* getP1() {	// Получение p1
		return p1;
	}
	Point2D* getP2() {	// Получение p2
		return p2;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int code = 0;
	while (1) {
		cout << "Введите код (1-5):";
		cin >> code;
		cout << endl;
		system("cls");
		switch (code) {
		case 1: {	// Статическое создание и удаление объекта
			Point2D point;
		} break;
		case 2: {	// Динамическое создание и удаление объекта
			Point2D* point = new Point2D;
			delete point;
		} break;
		case 3: {	// Помещение объектов в переменные различных типов 
			Point2D* point2D = new Point3D;
			Point3D* point3D = new Point3D;
			point2D->set(1, 2);
			point3D->set(1, 2, 3);
			delete point2D;
			delete point3D;
		} break;
		case 4: {	// Создание и удаление класса-наследника Point2D
			Point3D point;
		} break;
		case 5: {	// Композиция объектов
			Line2D ln;
			ln.print();
		} break;
		default: return 0;
		}
	}
	return 0;
}