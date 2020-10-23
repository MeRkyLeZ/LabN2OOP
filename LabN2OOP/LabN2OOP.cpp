#include <iostream>

using namespace std;

class Point {	// Интерфейс
protected:
	virtual void get() = NULL;	// Виртуальный метод вывода

public:
	Point() {	// Конструктор
		cout << "Point construct\n";
	}
	~Point() {	// Деструктор
		cout << "Point destruct\n";
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
		cout << "Point2D construct\n";
	}
	Point2D(double x, double y) {	// Конструктор
		this->x = x;
		this->y = y;
		cout << "Point2D construct\n";
	}
	Point2D(const Point2D& p) {	// Конструктор копирования
		x = p.x;
		y = p.y;
		cout << "Point2D construct copy\n";
	}
	~Point2D() {	// Деструктор
		cout << "Point2D destruct\n";
	}
	void set(double x, double y) {	// Установка значений
		this->x = x;
		this->y = y;
	}
	void get() {	// Вывод
		cout << "x=" << this->x << " , y=" << this->y << " , dist=" << getdist();
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
		cout << "Point3D construct\n";
	}
	Point3D(double x, double y, double z) {	// Конструктор
		this->x = x;
		this->y = y;
		this->z = z;
		cout << "Point3D construct\n";
	}
	Point3D(const Point3D& p) {	// Конструктор копирования
		x = p.x;
		y = p.y;
		z = p.z;
		cout << "Point3D construct copy\n";
	}
	~Point3D() {	// Деструктор
		cout << "Point3D destruct\n";
	}
	void set(double x, double y, double z) {	// Установка значений
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void get() {	// Вывод
		cout << "x=" << this->x << " , y=" << this->y << " , z=" << this->z << " , dist=" << getdist();
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

int main()
{

	return 0;
}