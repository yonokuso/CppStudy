#include <iostream>
using namespace std;

// 객체지향 마무리
// 1) struct vs class
// C++에서는 종이 한장차이
// struct 는 기본 접근 지정자가 public, class는 private임
// 왜 이렇게 했을까? - c++은 c언어에서 파생되어 발전했기 때문에, 호환성을 지키기 위함.
// -> struct는 그냥 구조체(데이터 묶음)을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도
//
//


struct TestStruct
{
	// 
	int _a;
	int _b;
};

class TestClass
{
	// 기본 private
	int _a;
	int _b;
};

// static 변수, static 함수 (static = 정적 = 고정된)

class Marine
{
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	// 모든 마린 대표, 
	static void SetAttack()
	{
		s_attack = 100;
	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관
	static int s_attack; // 설계도상으로만 존재
};

// static 변수의 메모리는
// 초기화하면 .data
// 초기화 안 하면 .bss

int Marine::s_attack = 0; // 외부 선언
// marine 클래스에만 묶여있는

int main()
{
	Marine m1;
	m1._hp = 40;
	m1.TakeDamage(10);

	Marine::s_attack = 6;
	//m1.s_attack = 6;

	Marine m2;
	m2._hp = 40;
	//m2.s_attack = 6;

	// 마린 공격력 업그레이드 완료! (아카데미에서 업그레이드)
	Marine::s_attack = 7;
	Marine::SetAttack();

	//m1.s_attack = 7;
	//m2.s_attack = 7;
	// 모든 마린의 공격력을 바꿔주는 것은 어려움
	// 공격력은 변하지 않고 전부 같음


	return 0;
}