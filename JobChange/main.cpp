#include <iostream>
#include "player.h"
#include "warrior.h"
#include "magician.h"
#include "thief.h"
#include "archer.h"
#include "monster.h"
using namespace std;

// 메인 함수
int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;
    string monname;

    Player* player = nullptr;
    Monster* monster = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
    cout << "* 원하시는 직업을 선택해주세요." << endl;

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << endl;
    }

    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice) {
    case 1:
        player = new Warrior(nickname);
        break;
    case 2:
        player = new Magician(nickname);
        break;
    case 3:
        player = new Thief(nickname);
        break;
    case 4:
        player = new Archer(nickname);
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
        return 1;
    }
    cout << "* 전직했으니 스킬을 습득하였습니다! 1회 사용을 실시합니다." << endl;

    player->attack();
    cout << "* 현재 스테이터스를 표기합니다." << endl;
    player->printPlayerStatus();

    //전투 시퀀스 시작
    Sleep(1500);
    cout << "\n앗! 야생의 몬스터가 나타났습니다!" << endl;
    Sleep(1000);
    cout << "몬스터의 이름을 입력해주세요 : ";
    cin >> monname;
    monster = new Monster(monname); // 몬스터의 이름을 입력받아 몬스터 클래스의 객체 생성
    cout << "전투 발생! " << player->getNickname() << "의 선공!" << endl;
    while (player->getHP() != 0 && monster->getHP() != 0) { // 플레이어와 몬스터 둘 중 하나의 체력이 0이 될때까지 반복
        player->attack(monster);
        if (monster->getHP() <= 0) break; // 플레이어의 공격 후 몬스터의 체력이 0이하면 즉시 탈출
        monster->attack(player);
    }
    if (player->getHP() <= 0) { // 패배연출
        Sleep(1000);
        cout << player->getNickname() << "의 HP가 전부 소진 되었습니다." << endl;
        Sleep(500);
        cout << "패배..." << endl;
        Sleep(500);
        cout << "눈이 점점 감기기 시작합니다..." << endl;
        Sleep(1000);
        cout << "---- GAME OVER ----" << endl;
    }
    else if (monster->getHP() <= 0) { // 승리연출
        Sleep(1000);
        cout << monster->getName() << "의 HP가 전부 소진 되었습니다." << endl;
        Sleep(500);
        cout << "승리!" << endl;
        Sleep(500);
        cout << player->getJobName() << " " << player->getNickname() << "은(는) 승리의 기쁨을 만끽하고 있습니다!" << endl;
        Sleep(1000);
        cout << "---- YOU WIN! ----" << endl;
    }
    else { //디버그용 라인
        cout << "프로그램 실행 중 예기치 못한 에러가 발생했습니다! 코드를 수정하세요!" << endl;
        return -1;
    }

    if (player != nullptr)
        delete player;
    if (monster != nullptr)
        delete monster;

    return 0;
}