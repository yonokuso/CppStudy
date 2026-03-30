#include <iostream>
using namespace std;

// 객체지향
// - 상속성
// - 은닉성
// - 다형성

// 은닉성 - 캡슐화
// 몰라도 되는 것은 깔끔하게 숨기겠다!
// 숨기는 이유
// 1) 정말 위험하고 건드리면 안되는 경우
// 2) 다른 경로로 접근하길 원하는 경우
// 
// ex)자동차
// - 핸들, 페달, 문, 엔진,..
// 일반 구매자 입장에서 사용하는 것?
// - 핸들/페달/문 등..
// 구매자가 몰라도 되는 것(오히려건드리면 큰일남
// - 엔진, 각종 전기선...
//
// public : 누구한테나 공개
// protected : 나의 자손들한테만 허락
// private : 나만 사용할거임(class car 내부에서만)

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줘야?
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음
// public : 공개적 상속 (부모님의 유산설계 그대로) public->public protected->protected
// protected : 보호받은 상속 - 내 자손들한테만 물려줌 (public->protected protected->protected)
// private : 개인적인 상속, 나까지만 잘 쓰고 자손들한테는 아예 안물려줌 (public -> private protected->private )
// 아무것도 안 쓸시 자동으로 private으로 됨
// public을 거의 쓰고 아주가끔 private을 씀

class Car
{
public: // (멤버)접근 지정자
	void MoveHandle(){}
	void PushPedal(){}
	void OpenDoor(){}

	void TurnKey()
	{
		RunEngine();
	}

protected:
	void RunEngine() {} // 엔진을 구동

private:
	void DisassembleCar(){}// 차 분해
	void ConnectCircuit(){} // 전기선 연결

public:
	

};

class SuperCar : Car // 상속 접근 지정자
{
public :
	void PushRemoteController()
	{
		RunEngine();
	}
};


// 캡슐화 - 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker
{
public:

	int GetHp() { return _hp; }

	void SetHp(int hp)
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

	// 사망: 체력이 50이하로 떨어지면 버서커모드 발동(강해짐)

private:
	void SetBerserkerMode()
	{
		cout << "매우 강해짐!" << endl;
	}

private:
	int _hp = 100;
};


int main()
{
	Berserker b;
	b.SetHp(20);


	return 0;
}