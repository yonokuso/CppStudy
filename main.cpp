#include <iostream>
using namespace std;

// 연산자 오버로딩(Operator Overloading)
// 
// 연산자 vs 함수
// - 연산자는 피연산자의 개수/타입이 고정되어 있음
// 
// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야 함
// 함수로 멤버함수 vs 전역함수가 존재하는 것처럼, 
// 연산자 함수도 두가지 방식으로 만들 수 있음

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽으로 기준으로 실행된 
// (a가 클래스여야 가능, a를 기준 피연산자 라고 함.
// - 한계) a가 클래스가 아니면 사용 못함

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

public:

	int _x;
	int _y;

};

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

	pos3 = pos.operator+(pos2);
 
	return 0;
}