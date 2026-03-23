#include <iostream>
using namespace std;

// 객체지향
// - 상속성
// - 은닉성
// - 다형성
//

// 메모리
// [[ Player ]]
// [ Knight ]

// 상속(Inheritance) ? 부모 -> 자식에게 유산을 물려주는 것

class Player
{
public:
	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player
{
public: 

public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _sp;

};

int main()
{
	Knight k;

	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;


	k.Attack();
	k.Die();

	return 0;
}