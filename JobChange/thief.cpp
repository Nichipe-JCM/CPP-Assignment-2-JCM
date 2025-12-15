#include "thief.h"
#include "monster.h"
#include <string>
#include <iostream>
using namespace std;

Thief::Thief(string nickname) :Player(nickname) {
	this->job_name = "도적";
	this->accuracy = 20;
	this->speed = 20;
	cout << this->job_name << "로 전직하셨습니다!" << endl;
}
void Thief::attack() {
	cout << "도적 " << this->nickname << "의 공격! 퀸터플 슬래시!" << endl;
}
void Thief::attack(Monster* monster) {
	cout << this->job_name << " " << this->nickname << "의 공격! 퀸터플 슬래시!" << endl;
	int damage = (this->power / 5) - monster->getDefence();
	if (damage <= 0) damage = 1;
	Sleep(500);
	for (int i = 0; i < 5; i++) {
		cout << monster->getName() << "에게 명중! " << damage << "의 피해를 입혔다!" << endl;
		Sleep(100);
	}
	Sleep(500);
	monster->setHP(monster->getHP() - (damage * 5));
	if (monster->getHP() > 0) {
		cout << monster->getName() << "의 남은 HP : " << monster->getHP() << endl;
		Sleep(500);
	}
}