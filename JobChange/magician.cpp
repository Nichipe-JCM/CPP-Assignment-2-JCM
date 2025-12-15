#include "magician.h"
#include "monster.h"
#include <string>
#include <iostream>
using namespace std;

Magician::Magician(string nickname) :Player(nickname) {
	this->job_name = "마법사";
	this->MP = 80;
	this->power = 15;
	cout << this->job_name << "로 전직하셨습니다!" << endl;
}
void Magician::attack() {
	cout << this->job_name << " " << this->nickname << "의 공격! 파이어 볼!" << endl;
}
void Magician::attack(Monster* monster) {
	cout << this->job_name << " " << this->nickname << "의 공격! 파이어 볼!" << endl;
	int damage = this->power - monster->getDefence();
	if (damage <= 0) damage = 1;
	Sleep(500);
	cout << monster->getName() << "에게 명중! " << damage << "의 피해를 입혔다!" << endl;
	Sleep(500);
	monster->setHP(monster->getHP() - damage);
	if (monster->getHP() > 0) {
		cout << monster->getName() << "의 남은 HP : " << monster->getHP() << endl;
		Sleep(500);
	}
}