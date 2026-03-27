#include <iostream>
using namespace std;

// 객체지향
// - 상속성
// - 은닉성
// - 다형성
//

// 메모리
// 생성자 소멸자 불르는 순서는 이런느낌
// [[ Player ]]
// [ Knight ]

// 상속(Inheritance) ? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(N) / 소멸자(1)
// 생성자는 탄생을 기념해서 호출되는 함수?
// -> Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// 솔로몬의 선택! -> 둘다 호출하자
// 생성자랑 소멸자는 안물려줌, 각자 잇음
// 자식이 먼저 소멸 -> 그다음 부모 소멸

// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - Projectile
// --Arrow, Fireball
// - Env

// Item
// - Weapon
// -- Sword..
// - Armor

class Player
{
public:
	Player()
	{
		_hp = 0; // 초기화를 해줘야함
		_attack = 0;
		_defence = 0;

		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp)
	{
		_hp = hp; // 초기화를 해줘야함

		cout << "Player(int hp) 기본 생성자 호출" << endl;
	}

	~Player()
	{
		cout << "~Player() 소멸자 호출" << endl;
	}

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
	Knight()
	{
		/*
		선처리 영역
		여기서 Player 기본 생성자 호출
		*/
		_stamina = 0;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	// 부모 생성자를 지정해주고 싶을떄
	Knight(int stamina) : Player(100)
	{
		/*
		선처리 영역
		여기서 Player 기본 생성자 호출
		*/
		_stamina = 0;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	~Knight()
	{
		cout << "~Knight() 소멸자 호출" << endl;
	}
	/*
	후처리 영역
	여기서 ~Player 소멸자 호출
	*/

	// 재정의 : 부모님의 유산은 거부하고 새로운 이름으로 만든?
	void Move() { cout << "Knight Move 호출" << endl; }


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

	k.Move(); // 재정의 버전
	k.Player::Move(); // 부모 버전

	k.Attack();
	k.Die();

	return 0;
}