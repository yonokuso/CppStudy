#include <iostream>
using namespace std;

// 객체 지향
// 
// 데이터 + 가공 (로직, 동작) 
// 객체란? 플레이어, 몬스터, 게임룸

// knight 를 설계해보자
// - 속성(데이터): hp, attack, position, y, x
// - 기능(동작): Move, Attack, Die

// class는 일종의 설계도
class Knight
{
public:
	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

// Instantiate 객체를 만든다!
int main()
{
	Knight k1;
	k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;


	Knight k2;
	k2._hp = 80;
	k2._attack = 5;
	k2._posY = 1;
	k2._posX = 1;

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}