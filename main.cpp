#include <iostream>
using namespace std;

// 연산자 오버로딩(Operator Overloading)
// 

class Position
{
public: 
	//RET FUN_NAME(ARG_LIST)
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;
		
		return pos;
	}
	
	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;
		
		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	int operator=(int arg)
	{
		_x = arg;
		_y = arg;
	}

public:

	int _x;
	int _y;

};

//void operator=(const Position& a, int b)
//{
//	a._x = b;
//	a._y = b;
//}

Position operator+(int a, const Position& b)
{
	Position ret;

	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}

int main()
{
	int a = 1;
	int b = 2;

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;
	Position pos4 = pos3 + 1;
	pos3.operator+(1);

	// 이렇게 커스텀 클래스를 사용해 비교할 일이 종종 생김
	bool isSame = (pos3 == pos4); // 같다는걸 어떻게 받아들일지?

	Position pos5;
	pos5 = 5; // 이건 대입
	
	//pos3 = pos.operator+(pos2);
 
	return 0;
}