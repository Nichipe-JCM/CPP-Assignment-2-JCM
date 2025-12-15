#include "archer.h"
#include "monster.h"
#include <string>
#include <iostream>
using namespace std;

Archer::Archer(string nickname):Player(nickname) {
	this->job_name = "궁수";
    this-> HP = 60;
	this-> power = 11;
	this -> accuracy = 20;
	cout << this->job_name << "로 전직하셨습니다!" << endl;
}
void Archer::attack() {
	cout << this->job_name << " " << this->nickname << "의 공격! 트리플 샷!" << endl;
}
void Archer::attack(Monster* monster) {
	cout << this->job_name << " " << this->nickname << "의 공격! 트리플 샷!" << endl;
	int damage = (this->power / 3) - monster->getDefence();
	if (damage <= 0) damage = 1;
	Sleep(500);
	for (int i = 0; i < 3; i++) {
		cout << monster->getName() << "에게 명중! " << damage << "의 피해를 입혔다!" << endl;
		Sleep(100);
	}
	Sleep(500);
	monster->setHP(monster->getHP() - (damage * 3));
	if (monster->getHP() > 0) {
		cout << monster->getName() << "의 남은 HP : " << monster->getHP() << endl;
		Sleep(500);
	}
}