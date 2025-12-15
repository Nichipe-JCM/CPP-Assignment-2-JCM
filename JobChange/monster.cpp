#include "monster.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;


// Monster 생성자
// - 몬스터의 이름을 매개변수로 입력 받습니다.
// - 모든 몬스터는 HP 10, 공격력 30, 방어력 10, 스피드 10의 능력치를 가집니다.
Monster::Monster(string name) {
	this->name = name;
	this->HP = 10;
	this->power = 30;
	this->defence = 10;
	this->speed = 10;
}

// 몬스터의 공격 함수
// - 플레이어 객체 포인터를 매개변수로 입력 받습니다.
// - 몬스터의 공격력-플레이어의 방어력을 데미지로 정의합니다.
// - 만약 위에서 계산한 데미지가 0 이하라면, 데미지를 1로 정의합니다.
// - 플레이어에게 얼마나 데미지를 입혔는지 출력합니다.
// - 플레이어 객체의 getHP 함수를 실행하여 플레이어HP-데미지 계산 결과를
// - 플레이어 객체의 setHP 매개변수로 전달합니다.
// - 플레이어가 생존했을 경우, 플레이어의 남은 HP를 출력합니다.
void Monster::attack(Player* player) {
	cout << "몬스터 " << this->name << "의 공격! 몸통 박치기!" << endl;
	Sleep(500);
	int damage = this->power - player->getDefence();
	if (damage <= 0) damage = 1;
	cout << player->getJobName() << " " << player->getNickname() << "에게 명중! " << damage << " 의 피해를 입혔다!" << endl;
	Sleep(500);
	player->setHP(player->getHP() - damage);
	if (player->getHP() > 0) {
		cout << player->getJobName() << " " << player->getNickname() << "의 남은 HP : " << player->getHP() << endl;
		Sleep(500);
	}
}

// 몬스터의 속성값을 리턴하는 get 함수
string Monster::getName() {
	return name;
}
int Monster::getHP() {
	return HP;
}
int Monster::getPower() {
	return power;
}
int Monster::getDefence() {
	return defence;
}
int Monster::getSpeed() {
	return speed;
}

// 몬스터의 속성값을 정의하는 set 함수
void Monster::setName(string name) {
	this->name = name;
}
void Monster::setHP(int HP) {
	this->HP = HP;
}
void Monster::setPower(int power) {
	this->power = power;
}
void Monster::setDefence(int defence) {
	this->defence = defence;
}
void Monster::setSpeed(int speed) {
	this->speed = speed;
}