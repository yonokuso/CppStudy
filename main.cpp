#include <iostream>
using namespace std;

// 연산자 오버로딩(Operator Overloading)
// 
// 복사 대입연산자
// - 대입 연산자가 나온 김에 [복사 대입 연산자] 에 대해 알아보자
// 용어가 좀 헷갈린다 [복사 생성자] [대입 연산자] [복사 대입 연산자]
// - 복사 대입 연산자 = 대입 연산자 중, 자기 자신의 참조 타입을 인자로 받는 것
// 
// 
// 기타
//  - 모든 연산자를 다 오버로딩 할 수 있는 것은 아니다 (:: , . *이런거안됨)
// 모든 연산자가 다 2개 항이 있는 것은 아님. ++ --가 대표적(단항 연산자)
// - 증감 연산자 ++ --
// -- 전위형 (++a) operator++()
// -- 후위형 (a++) operator++(int)
//

class Position
{
public: 

	//Position(const Position& arg) // 복사 생성자
	//{

	//}

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

	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		//Position* this = 내자신의 주소;
		return *this; // 내 자신의 주소

	}

	// [복사 생성자] [복사 대입 연산자] 등 특별 대우를 받는 이유는
	// 말 그대로 객체가 '복사'되길 원하는 특징 때문
	//  - 동적할당 시간에 더 자세히 알아볼 것

	Position& operator=(const Position& arg)
	{
		_x = arg._x;
		_y = arg._y;
		
		return *this;
	}

	Position& operator++()
	{
		_x++;
		_y++;

		return *this;
	}

	Position& operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;

		return ret;
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
	int c = ++(++a);

	
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
	pos5 = (pos5 = 5); // 이건 대입


	// (const Pos&)줘-  (Pos)복사값 줄게-
	// 임시객체를 만들어서 고차겠다?
	// 고치겠다는 의도가 담겨있음?
	pos5 = pos3++;

	++(++pos3); // 가능
	// 타입이 일치하지 않음에도 참조값에 const를 붙이면
	// 포지션의 복사값을 우여곡절 끝에 받을 수 있음
	//pos3 = pos.operator+(pos2);
 
	return 0;
}