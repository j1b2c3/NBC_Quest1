#include <iostream>
using namespace std;

int status[4] = { 0, 0, 0, 0 };
// 0 : HP, 1 : MP, 2 : 공격력 3 : 방어력
int potion[2] = { 0, 0 };
int level = 1;

void set_Potion(int count, int& p_HPPotion, int& p_MPPotion) {
	p_HPPotion = count;
	p_MPPotion = count;
	cout << "HP 포션과 MP 포션이 각각 " << count << "개씩 지급되었습니다." << endl;
}

void add_Potion(int& p_HPPotion, int& p_MPPotion) {
	p_HPPotion += 1;
	p_MPPotion += 1;
	cout << "HP 포션과 MP 포션이 각각 1개 지급되었습니다." << endl;
}

int get_input(string label, int min_value) {
	int value;
	while (true) {
		cout << label << " : ";
		cin >> value;
		if (cin.fail() || value <= min_value) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << label << "는 " << min_value << "보다 커야 합니다. 다시 입력해주세요." << endl;
		}
		else {
			return value;
		}
	}

}

void set_status() {
	cout << "캐릭터의 능력치를 설정합니다." << endl;
	status[0] = get_input("HP", 50);
	status[1] = get_input("MP", 50);
	status[2] = get_input("공격력", 0);
	status[3] = get_input("방어력", 0);

}

void edit_status() {
	while (true) {

		cout << "1. HP UP / 2. MP UP 3. 공격력 UP 4. 방어력 UP 5. 현재 능력치 / 6. Level Up / 0.나가기" << endl;
		int input;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			continue;
		}

		switch (input) {
		case 1: 
			if (potion[0] > 0) {
				potion[0]--;
				status[0] += 20; cout << "HP가 20 증가했습니다." << endl; break;
			}
			else {
				cout << "HP 포션이 없습니다." << endl; break;
			}
		case 2:	
			if (potion[1] > 0) {
				potion[1]--;
				status[1] += 20; cout << "MP가 20 증가했습니다." << endl; break;
			}
			else {
				cout << "MP 포션이 없습니다." << endl; break;
			}
		case 3:	
			if (status[2] >= 100000) {
				cout << "공격력이 100000 이상이므로 더 이상 증가할 수 없습니다." << endl; break;
			}
			else {
				status[2] *= 2; 
				if (status[2] > 100000) {
					status[2] = 100000;
				}
				cout << "공격력이 2배 증가했습니다." << endl; break;
			}
		case 4:
			if (status[3] >= 100000) {
				cout << "방어력이 100000 이상이므로 더 이상 증가할 수 없습니다." << endl; break;
			}
			else {
				status[3] *= 2; 
				if (status[3] > 100000) {
					status[3] = 100000;
				}
				cout << "방어력이 2배 증가했습니다." << endl; break;
			}
		case 5: 
			cout << "현재 레벨 : " << level << endl;
			cout << "현재 능력치" << endl << "HP : " << status[0] << " / MP : " << status[1] << endl;
			cout << "공격력 : " << status[2] << " / 방어력 : " << status[3] << endl;
			cout << "현재 포션 개수" << endl << "HP 포션 : " << potion[0] << "개 / MP 포션 : " << potion[1] << "개" << endl;
			break;
		case 6: 
			level ++; 
			cout << "레벨업! ";
			add_Potion(potion[0], potion[1]);
			break;
		case 0:
			cout << "능력치 편집을 종료합니다." << endl;
			return;
		default:
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			break;
		}
	}
}


int main() {

	set_status();
	set_Potion(5, potion[0], potion[1]);
	edit_status();

	return 0;
}
