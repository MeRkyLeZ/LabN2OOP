#include <iostream>

using namespace std;

class Point {	// Интерфейс
public:
	virtual void get() = NULL;	// Виртуальный метод вывода

	Point() {	// Конструктор
		cout << "Point construct\n";
	}
	~Point() {	// Деструктор
		cout << "Point destruct\n";
	}
};

class Point2D : public Point {	// Точка в 2-х мерном пространстве
public:
	int x;
	int y;

	Point2D() {	// Конструктор
		x = 0;
		y = 0;
		cout << "Point2D construct\n";
	}
	Point2D(int x, int y) {	// Конструктор
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
	void set(int x, int y) {	// Установка значений
		this->x = x;
		this->y = y;
	}
	void get() {	// Вывод
		cout << "x=" << this->x << " , y=" << this->y << "\n";
	}
	void setX(int x) {	// Утановка x
		this->x = x;
	}
	void setY(int y) {	// Утановка y
		this->y = y;
	}
	int getX() {	// Получение x
		return x;
	}
	int getY() {	// Получение y
		return y;
	}
};

class Point3D : public Point2D {
public:
	int z;
	Point3D() {	// Конструктор
		z = 0;
		cout << "Point3D construct\n";
	}
	Point3D(int x, int y, int z) {	// Конструктор
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
	void set(int x, int y, int z) {	// Установка значений
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void get() {	// Вывод
		cout << "x=" << this->x << " , y=" << this->y << " , z=" << this->z << "\n";
	}
	void setZ(int z) {	// Утановка z
		this->z = z;
	}
	int getZ() {	// Получение z
		return z;
	}
};

int main()
{

	return 0;
}