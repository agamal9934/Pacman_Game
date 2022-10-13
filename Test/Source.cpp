#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
#include <sstream>
#include <Windows.h>
using namespace sf;
using namespace std;
bool blue = false, add = false; int ab, ba, ca = 15, sc_evils = 0, t1_attack, t2_attack, zx, zy, conter_life = 3;
bool attack1 = false, achway = false, e1u = false, e1d = false, e1r = false, e1l = false;  int conter1 = 0, ax1, ay1;
bool attack2 = false, achway2 = false, e2u = false, e2d = false, e2r = false, e2l = false; int conter2 = 0, ax2, ay2;
bool e3u = false, e3d = false, e3r = false, e3l = false; int conter3 = 0, ax3, ay3;
bool e4u = false, e4d = false, e4r = false, e4l = false; int conter4 = 0, ax4, ay4;
struct Ahmed {
	void Start_game(Text& star, Font& font, Music& start) {
		star.setFont(font);  star.setCharacterSize(50);
		star.setScale(1.5, 1.5);  star.setString(" R E A D Y !! :) ");
		star.setFillColor(Color::Yellow);  star.setPosition(50, 250);
		start.play();
	}
	void Finsh(Text& finsh, Font& font, Music& dead) {
		finsh.setFont(font);  finsh.setCharacterSize(50);
		finsh.setScale(0.15, 0.15);  finsh.setString(" Game Over :( ");
		finsh.setFillColor(Color::Yellow);  finsh.setPosition(20, 10);
		dead.play();
	}
	void Win(Text& win, Font& font) {
		win.setFont(font);  win.setCharacterSize(50);
		win.setScale(0.15, 0.15);  win.setString(" You Win :D ");
		win.setFillColor(Color::Yellow);  win.setPosition(20, 10);
	}
	void Score(int score, Text& mscore, Font& font) {
		mscore.setFont(font);  mscore.setCharacterSize(40);
		mscore.setScale(0.05, 0.05);  mscore.setFillColor(Color::Yellow);
		mscore.setPosition(2, -2.5);   stringstream ss;
		ss << "Score : " << score;   mscore.setString(ss.str());
	}
	void TIME(Time elapsed1, Text& ttime, Font& font) {
		ttime.setFont(font);  ttime.setCharacterSize(40);
		ttime.setScale(0.05, 0.05);  ttime.setFillColor(Color::Cyan);
		ttime.setPosition(80, -2.5);  stringstream ss1;
		ss1 << "Time : " << (int)elapsed1.asSeconds();  ttime.setString(ss1.str());
	}
	void Time_eat(Text& conect, Font& font) {
		conect.setFont(font);  conect.setCharacterSize(40);
		conect.setScale(0.05, 0.05);  conect.setFillColor(Color::Green);
		conect.setPosition(40, -2.5);  stringstream ss5;
		ss5 << "Ti_conect : " << ca;  conect.setString(ss5.str());
	}
	void gost1(char enamy[100][100], Sprite& s, Sprite& q, int& ax1, int& ay1, Time& elapsed1, int& score) {
		int dire1 = rand() % 4 + 1;
		if ((ax1 == 0) && (ay1 == 11)) { q.setPosition(91, 11); }
		else if ((ax1 == 92) && (ay1 == 11)) { q.setPosition(1, 11); }
		if ((int)elapsed1.asSeconds() % 10 == 0) {
			attack1 = true; achway = false;
			t1_attack = (int)elapsed1.asSeconds();
		}
		if ((int)elapsed1.asSeconds() - t1_attack == 20) { achway = true; attack1 = false; }
		if ((achway && (blue || blue == false)) || blue) {
			if (enamy[ay1][ax1] == 'x' || enamy[ay1][ax1] == '1' || enamy[ay1][ax1] == '2' || enamy[ay1][ax1] == '3' || enamy[ay1][ax1] == '4' ||
				enamy[ay1][ax1] == '5' || enamy[ay1][ax1] == 'c' || enamy[ay1][ax1] == '8' || enamy[ay1][ax1] == '9' || enamy[ay1][ax1] == '0' || enamy[ay1][ax1] == 'f') {
				switch (dire1) {
				case 1:
					e1u = true; e1d = false; e1l = false; e1r = false;
					break;
				case 2:
					e1u = false; e1d = true; e1l = false; e1r = false;
					break;
				case 3:
					e1u = false; e1d = false; e1l = false; e1r = true;
					break;
				case 4:
					e1u = false; e1d = false; e1l = true; e1r = false;
					break;
				}
			}
		}
		if (attack1 && blue == false) {
			if (enamy[ay1][ax1] == 'x') {
				if (s.getPosition().y < q.getPosition().y) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if (s.getPosition().y > q.getPosition().y) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if (s.getPosition().x > q.getPosition().x) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if (s.getPosition().x < q.getPosition().x) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
			}
			else if (enamy[ay1][ax1] == '1') {
				if (s.getPosition().y < q.getPosition().y) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if (s.getPosition().y > q.getPosition().y) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().y == q.getPosition().y) && (s.getPosition().x < q.getPosition().x)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().y == q.getPosition().y) && (s.getPosition().x > q.getPosition().x)) { e1u = true; e1d = false; e1l = false; e1r = false; }
			}
			else if (enamy[ay1][ax1] == '2') {
				if ((s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
			}
			else if (enamy[ay1][ax1] == '3') {
				if ((s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
			}
			else if (enamy[ay1][ax1] == '4') {
				if (s.getPosition().y < q.getPosition().y) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().y > q.getPosition().y) && (s.getPosition().x < q.getPosition().x)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().y > q.getPosition().y) && (s.getPosition().x > q.getPosition().x)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().y < q.getPosition().y) && (s.getPosition().x < q.getPosition().x)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().y < q.getPosition().y) && (s.getPosition().x > q.getPosition().x)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
			}
			else if (enamy[ay1][ax1] == '5') {
				if (s.getPosition().y > q.getPosition().y) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if (s.getPosition().y < q.getPosition().y) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
			}
			else if (enamy[ay1][ax1] == 'c') {
				if (s.getPosition().y > q.getPosition().y) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
			}
			else if (enamy[ay1][ax1] == '8') {
				if (s.getPosition().y > q.getPosition().y) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if (s.getPosition().y < q.getPosition().y) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
			}
			else if (enamy[ay1][ax1] == '9') {
				if (s.getPosition().y > q.getPosition().y) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if (s.getPosition().y < q.getPosition().y) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = true; e1l = false; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
			}
			else if (enamy[ay1][ax1] == '0') {
				if (s.getPosition().y < q.getPosition().y) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }

			}
			else if (enamy[ay1][ax1] == 'f') {
				if (s.getPosition().y < q.getPosition().y) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
				if ((s.getPosition().x > q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x < q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) { e1u = false; e1d = false; e1l = true; e1r = false; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y > q.getPosition().y)) { e1u = false; e1d = false; e1l = false; e1r = true; }
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y < q.getPosition().y)) { e1u = true; e1d = false; e1l = false; e1r = false; }
			}
			if (e1u && enamy[ay1 - 1][ax1] == '#' && s.getPosition().x > q.getPosition().x && enamy[ay1][ax1 + 1] != '#') {
				e1u = false;         e1d = false;        e1l = false;       e1r = true;
			}
			if (e1u && enamy[ay1 - 1][ax1] == '#' && s.getPosition().x < q.getPosition().x && enamy[ay1][ax1 - 1] != '#') {
				e1u = false;         e1d = false;        e1l = true;       e1r = false;
			}
			if (e1u && enamy[ay1 - 1][ax1] == '#' && s.getPosition().y > q.getPosition().y && enamy[ay1 + 1][ax1] != '#') {
				e1u = false;         e1d = true;        e1l = false;       e1r = false;
			}
			if (e1d && enamy[ay1 + 1][ax1] == '#' && s.getPosition().x > q.getPosition().x && enamy[ay1][ax1 + 1] != '#') {
				e1u = false;         e1d = false;        e1l = false;       e1r = true;
			}
			if (e1d && enamy[ay1 + 1][ax1] == '#' && s.getPosition().x < q.getPosition().x && enamy[ay1][ax1 - 1] != '#') {
				e1u = false;         e1d = false;        e1l = true;       e1r = false;
			}
			if (e1d && enamy[ay1 + 1][ax1] == '#' && s.getPosition().y < q.getPosition().y && enamy[ay1 - 1][ax1] != '#') {
				e1u = true;         e1d = false;        e1l = false;       e1r = false;
			}
			if (e1r && enamy[ay1][ax1 + 1] == '#' && s.getPosition().y < q.getPosition().y && enamy[ay1 - 1][ax1] != '#') {
				e1u = true;         e1d = false;        e1l = false;       e1r = false;
			}
			if (e1r && enamy[ay1][ax1 + 1] == '#' && s.getPosition().y > q.getPosition().y && enamy[ay1 + 1][ax1] != '#') {
				e1u = false;         e1d = true;        e1l = false;       e1r = false;
			}
			if (e1r && enamy[ay1][ax1 + 1] == '#' && s.getPosition().x < q.getPosition().x && enamy[ay1][ax1 - 1] != '#') {
				e1u = false;         e1d = false;        e1l = true;       e1r = false;
			}
			if (e1l && enamy[ay1][ax1 - 1] == '#' && s.getPosition().y > q.getPosition().y && enamy[ay1 + 1][ax1] != '#') {
				e1u = false;         e1d = true;        e1l = false;       e1r = false;
			}
			if (e1l && enamy[ay1][ax1 - 1] == '#' && (s.getPosition().y < q.getPosition().y || s.getPosition().y == q.getPosition().y) && enamy[ay1 - 1][ax1] != '#') {
				e1u = true;         e1d = false;        e1l = false;       e1r = false;
			}
			if (e1l && enamy[ay1][ax1 - 1] == '#' && s.getPosition().x > q.getPosition().x && enamy[ay1][ax1 + 1] != '#') {
				e1u = false;         e1d = false;        e1l = false;       e1r = true;
			}
		}

		if (e1u) {
			ax1 = q.getPosition().x;
			ay1 = q.getPosition().y;
			if (enamy[ay1 - 1][ax1] != '#') {
				if (enamy[ay1 - 1][ax1] != '*')
					q.move(0, -1);
			}
		}
		if (e1d) {
			ax1 = q.getPosition().x;
			ay1 = q.getPosition().y;
			if (enamy[ay1 + 1][ax1] != '#') {
				if (enamy[ay1 + 1][ax1] != '*')
					q.move(0, 1);
			}
		}
		if (e1r) {
			ax1 = q.getPosition().x;
			ay1 = q.getPosition().y;
			if (enamy[ay1][ax1 + 1] != '#') {
				if (enamy[ay1][ax1 + 1] != '*')
					q.move(1, 0);
			}
		}
		if (e1l) {
			ax1 = q.getPosition().x;
			ay1 = q.getPosition().y;
			if (enamy[ay1][ax1 - 1] != '#') {
				if (enamy[ay1][ax1 - 1] != '*')
					q.move(-1, 0);
			}
		}
		if (blue) {
			ba = elapsed1.asSeconds();
			ca = 15 - (ba - ab);
			if (ca == 15) { q.setTextureRect(IntRect(12 * 32, 0, 32, 32)); }
			if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) {
				q.setTextureRect(IntRect(13 * 32, 2 * 32, 32, 32));
				if (conter1 == 0) { conter1++; score += 50; sc_evils += 50; }
			}
			if (ca == 0) {
				q.setTextureRect(IntRect(0 * 32, 0, 32, 32));
			}
		}
	}
	void gost2(char enamy[100][100], int& ax2, int& ay2, Sprite& s, Sprite& w, Time& elapsed1, int& score) {
		int  dire2 = rand() % 4 + 1;
		if ((ax2 == 0) && (ay2 == 11)) { w.setPosition(91, 11); }
		else if ((ax2 == 92) && (ay2 == 11)) { w.setPosition(1, 11); }
		if ((int)elapsed1.asSeconds() % 10 == 0) {
			attack2 = true; achway2 = false;
			t2_attack = (int)elapsed1.asSeconds();
		}
		if ((int)elapsed1.asSeconds() - t2_attack == 20) { achway2 = true; attack2 = false; }
		if ((achway2 && (blue || blue == false)) || blue) {
			if (enamy[ay2][ax2] == 'x' || enamy[ay2][ax2] == '1' || enamy[ay2][ax2] == '2' || enamy[ay2][ax2] == '3' || enamy[ay2][ax2] == '4' ||
				enamy[ay2][ax2] == '5' || enamy[ay2][ax2] == 'c' || enamy[ay2][ax2] == '8' || enamy[ay2][ax2] == '9' || enamy[ay2][ax2] == '0' || enamy[ay2][ax2] == 'f') {
				switch (dire2) {
				case 1:
					e2u = true; e2d = false; e2l = false; e2r = false;
					break;
				case 2:
					e2u = false; e2d = true; e2l = false; e2r = false;
					break;
				case 3:
					e2u = false; e2d = false; e2l = false; e2r = true;
					break;
				case 4:
					e2u = false; e2d = false; e2l = true; e2r = false;
					break;
				}
			}
		}
		if (attack2 && blue == false) {
			if (enamy[ay2][ax2] == 'x') {
				if (s.getPosition().y < w.getPosition().y) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if (s.getPosition().y > w.getPosition().y) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if (s.getPosition().x > w.getPosition().x) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if (s.getPosition().x < w.getPosition().x) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
			}
			else if (enamy[ay2][ax2] == '1') {
				if (s.getPosition().y < w.getPosition().y) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if (s.getPosition().y > w.getPosition().y) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().y == w.getPosition().y) && (s.getPosition().x < w.getPosition().x)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().y == w.getPosition().y) && (s.getPosition().x > w.getPosition().x)) { e2u = true; e2d = false; e2l = false; e2r = false; }
			}
			else if (enamy[ay2][ax2] == '2') {
				if ((s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
			}
			else if (enamy[ay2][ax2] == '3') {
				if ((s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
			}
			else if (enamy[ay2][ax2] == '4') {
				if (s.getPosition().y < w.getPosition().y) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().y > w.getPosition().y) && (s.getPosition().x < w.getPosition().x)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().y > w.getPosition().y) && (s.getPosition().x > w.getPosition().x)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().y < w.getPosition().y) && (s.getPosition().x < w.getPosition().x)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().y < w.getPosition().y) && (s.getPosition().x > w.getPosition().x)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
			}
			else if (enamy[ay2][ax2] == '5') {
				if (s.getPosition().y > w.getPosition().y) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if (s.getPosition().y < w.getPosition().y) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
			}
			else if (enamy[ay2][ax2] == 'c') {
				if (s.getPosition().y > w.getPosition().y) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
			}
			else if (enamy[ay2][ax2] == '8') {
				if (s.getPosition().y > w.getPosition().y) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if (s.getPosition().y < w.getPosition().y) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
			}
			else if (enamy[ay2][ax2] == '9') {
				if (s.getPosition().y > w.getPosition().y) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if (s.getPosition().y < w.getPosition().y) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = true; e2l = false; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
			}
			else if (enamy[ay2][ax2] == '0') {
				if (s.getPosition().y < w.getPosition().y) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }

			}
			else if (enamy[ay2][ax2] == 'f') {
				if (s.getPosition().y < w.getPosition().y) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
				if ((s.getPosition().x > w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x < w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) { e2u = false; e2d = false; e2l = true; e2r = false; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y > w.getPosition().y)) { e2u = false; e2d = false; e2l = false; e2r = true; }
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y < w.getPosition().y)) { e2u = true; e2d = false; e2l = false; e2r = false; }
			}
			if (e2u && enamy[ay2 - 1][ax2] == '#' && s.getPosition().x > w.getPosition().x && enamy[ay2][ax2 + 1] != '#') {
				e2u = false;         e2d = false;        e2l = false;       e2r = true;
			}
			if (e2u && enamy[ay2 - 1][ax2] == '#' && s.getPosition().x < w.getPosition().x && enamy[ay2][ax2 - 1] != '#') {
				e2u = false;         e2d = false;        e2l = true;       e2r = false;
			}
			if (e2u && enamy[ay2 - 1][ax2] == '#' && s.getPosition().y > w.getPosition().y && enamy[ay2 + 1][ax2] != '#') {
				e2u = false;         e2d = true;        e2l = false;       e2r = false;
			}
			if (e2d && enamy[ay2 + 1][ax2] == '#' && s.getPosition().x > w.getPosition().x && enamy[ay2][ax2 + 1] != '#') {
				e2u = false;         e2d = false;        e2l = false;       e2r = true;
			}
			if (e2d && enamy[ay2 + 1][ax2] == '#' && s.getPosition().x < w.getPosition().x && enamy[ay2][ax2 - 1] != '#') {
				e2u = false;         e2d = false;        e2l = true;       e2r = false;
			}
			if (e2d && enamy[ay2 + 1][ax2] == '#' && s.getPosition().y < w.getPosition().y && enamy[ay2 - 1][ax2] != '#') {
				e2u = true;         e2d = false;        e2l = false;       e2r = false;
			}
			if (e2r && enamy[ay2][ax2 + 1] == '#' && s.getPosition().y < w.getPosition().y && enamy[ay2 - 1][ax2] != '#') {
				e2u = true;         e2d = false;        e2l = false;       e2r = false;
			}
			if (e2r && enamy[ay2][ax2 + 1] == '#' && s.getPosition().y > w.getPosition().y && enamy[ay2 + 1][ax2] != '#') {
				e2u = false;         e2d = true;        e2l = false;       e2r = false;
			}
			if (e2r && enamy[ay2][ax2 + 1] == '#' && s.getPosition().x < w.getPosition().x && enamy[ay2][ax2 - 1] != '#') {
				e2u = false;         e2d = false;        e2l = true;       e2r = false;
			}
			if (e2l && enamy[ay2][ax2 - 1] == '#' && s.getPosition().y > w.getPosition().y && enamy[ay2 + 1][ax2] != '#') {
				e2u = false;         e2d = true;        e2l = false;       e2r = false;
			}
			if (e2l && enamy[ay2][ax2 - 1] == '#' && (s.getPosition().y < w.getPosition().y || s.getPosition().y == w.getPosition().y) && enamy[ay2 - 1][ax2] != '#') {
				e2u = true;         e2d = false;        e2l = false;       e2r = false;
			}
			if (e2l && enamy[ay2][ax2 - 2] == '#' && s.getPosition().x > w.getPosition().x && enamy[ay2][ax2 + 1] != '#') {
				e2u = false;         e2d = false;        e2l = false;       e2r = true;
			}
		}

		if (e2u) {
			ax2 = w.getPosition().x;
			ay2 = w.getPosition().y;
			if (enamy[ay2 - 1][ax2] != '#') {
				if (enamy[ay2 - 1][ax2] != '*')
					w.move(0, -1);
			}
		}
		if (e2d) {
			ax2 = w.getPosition().x;
			ay2 = w.getPosition().y;
			if (enamy[ay2 + 1][ax2] != '#') {
				if (enamy[ay2 + 1][ax2] != '*')
					w.move(0, 1);
			}
		}
		if (e2r) {
			ax2 = w.getPosition().x;
			ay2 = w.getPosition().y;
			if (enamy[ay2][ax2 + 1] != '#') {
				if (enamy[ay2][ax2 + 1] != '*')
					w.move(1, 0);
			}
		}
		if (e2l) {
			ax2 = w.getPosition().x;
			ay2 = w.getPosition().y;
			if (enamy[ay2][ax2 - 1] != '#') {
				if (enamy[ay2][ax2 - 1] != '*')
					w.move(-1, 0);
			}
		}
		if (blue) {
			ba = elapsed1.asSeconds();
			ca = 15 - (ba - ab);
			if (ca == 15) { w.setTextureRect(IntRect(12 * 32, 0, 32, 32)); }
			if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) {
				w.setTextureRect(IntRect(13 * 32, 2 * 32, 32, 32));
				if (conter2 == 0) { conter2++; score += 50; sc_evils += 50; }
			}
			if (ca == 0) {
				w.setTextureRect(IntRect(2 * 32, 0, 32, 32));
			}
		}
	}
	void gost3(char enamy[100][100], Sprite& s, Sprite& t, int& ax3, int& ay3, Time& elapsed1, int& score) {
		int dire3 = rand() % 4 + 1;
		if ((ax3 == 0) && (ay3 == 11)) { t.setPosition(91, 11); }
		else if ((ax3 == 92) && (ay3 == 11)) { t.setPosition(1, 11); }
		if (enamy[ay3][ax3] == 'x' || enamy[ay3][ax3] == '1' || enamy[ay3][ax3] == '2' || enamy[ay3][ax3] == '3' || enamy[ay3][ax3] == '4' ||
			enamy[ay3][ax3] == '5' || enamy[ay3][ax3] == 'c' || enamy[ay3][ax3] == '8' || enamy[ay3][ax3] == '9' || enamy[ay3][ax3] == '0' || enamy[ay3][ax3] == 'f') {
			switch (dire3) {
			case 1:
				e3u = true; e3d = false; e3l = false; e3r = false;
				break;
			case 2:
				e3u = false; e3d = true; e3l = false; e3r = false;
				break;
			case 3:
				e3u = false; e3d = false; e3l = false; e3r = true;
				break;
			case 4:
				e3u = false; e3d = false; e3l = true; e3r = false;
				break;
			}
		}
		if (e3u) {
			ax3 = t.getPosition().x;
			ay3 = t.getPosition().y;
			if (enamy[ay3 - 1][ax3] != '#') {
				if (enamy[ay3 - 1][ax3] != '*')
					t.move(0, -1);
			}
		}
		if (e3d) {
			ax3 = t.getPosition().x;
			ay3 = t.getPosition().y;
			if (enamy[ay3 + 1][ax3] != '#') {
				if (enamy[ay3 + 1][ax3] != '*')
					t.move(0, 1);
			}
		}
		if (e3r) {
			ax3 = t.getPosition().x;
			ay3 = t.getPosition().y;
			if (enamy[ay3][ax3 + 1] != '#') {
				if (enamy[ay3][ax3 + 1] != '*')
					t.move(1, 0);
			}
		}
		if (e3l) {
			ax3 = t.getPosition().x;
			ay3 = t.getPosition().y;
			if (enamy[ay3][ax3 - 1] != '#') {
				if (enamy[ay3][ax3 - 1] != '*')
					t.move(-1, 0);
			}
		}
		if (blue) {
			ba = elapsed1.asSeconds();
			ca = 15 - (ba - ab);
			if (ca == 15) { t.setTextureRect(IntRect(12 * 32, 0, 32, 32)); }
			if ((s.getPosition().x == t.getPosition().x) && (s.getPosition().y == t.getPosition().y)) {
				t.setTextureRect(IntRect(13 * 32, 2 * 32, 32, 32));
				if (conter3 == 0) { conter3++; score += 50; sc_evils += 50; }
			}
			if (ca == 0) {
				t.setTextureRect(IntRect(4 * 32, 0, 32, 32));
			}
		}
	}
	void gost4(char enamy[100][100], Sprite& s, Sprite& y, int& ax4, int& ay4, Time& elapsed1, int& score) {
		int  dire4 = rand() % 4 + 1;
		if ((ax4 == 0) && (ay4 == 11)) { y.setPosition(91, 11); }
		else if ((ax4 == 92) && (ay4 == 11)) { y.setPosition(1, 11); }
		if ((enamy[ay4][ax4] == 'x' || enamy[ay4][ax4] == '1' || enamy[ay4][ax4] == '2' || enamy[ay4][ax4] == '3' || enamy[ay4][ax4] == '4' ||
			enamy[ay4][ax4] == '5' || enamy[ay4][ax4] == 'c' || enamy[ay4][ax4] == '8' || enamy[ay4][ax4] == '9' || enamy[ay4][ax4] == '0' || enamy[ay4][ax4] == 'f')
			&& (((s.getPosition().y == y.getPosition().y) && (enamy[ay4][ax4 + 1] != '#' || enamy[ay4][ax4 - 1] != '#')) || ((s.getPosition().x == y.getPosition().x)
				&& (enamy[ay4 - 1][ax4] != '#' || enamy[ay4 + 1][ax4] != '#'))) && blue == false) {
			for (int i = 0; i < 92; i++) {
				if (s.getPosition().y == y.getPosition().y) {
					if (y.getPosition().x + i == s.getPosition().x) {
						if (s.getPosition().x > y.getPosition().x)
							e4u = false; e4d = false; e4l = false; e4r = true;
						break;
					}
					if (y.getPosition().x + i == '#')
						break;
				}
			}
			for (int i = 0; i < 92; i++) {
				if (s.getPosition().y == y.getPosition().y) {
					if (y.getPosition().x - i == s.getPosition().x) {
						if (s.getPosition().x < y.getPosition().x)
							e4u = false; e4d = false; e4l = true; e4r = false;
						break;
					}
					if (y.getPosition().x - i == '#')
						break;
				}
			}
			for (int i = 0; i < 30; i++) {
				if (s.getPosition().x == y.getPosition().x) {
					if (y.getPosition().y + i == s.getPosition().y) {
						if (s.getPosition().y > y.getPosition().y)
							e4u = false; e4d = true; e4l = false; e4r = false;
						break;
					}
					if (y.getPosition().y + i == '#')
						break;
				}
			}
			for (int i = 0; i < 30; i++) {
				if (s.getPosition().x == y.getPosition().x) {
					if (y.getPosition().y - i == s.getPosition().y) {
						if (s.getPosition().y < y.getPosition().y)
							e4u = true; e4d = false; e4l = false; e4r = false;
						break;
					}
					if (y.getPosition().y - i == '#')
						break;
				}
			}
		}
		else {
			if (enamy[ay4][ax4] == 'x' || enamy[ay4][ax4] == '1' || enamy[ay4][ax4] == '2' || enamy[ay4][ax4] == '3' || enamy[ay4][ax4] == '4' ||
				enamy[ay4][ax4] == '5' || enamy[ay4][ax4] == 'c' || enamy[ay4][ax4] == '8' || enamy[ay4][ax4] == '9' || enamy[ay4][ax4] == '0' || enamy[ay4][ax4] == 'f') {
				switch (dire4) {
				case 1:
					e4u = true; e4d = false; e4l = false; e4r = false;
					break;
				case 2:
					e4u = false; e4d = true; e4l = false; e4r = false;
					break;
				case 3:
					e4u = false; e4d = false; e4l = false; e4r = true;
					break;
				case 4:
					e4u = false; e4d = false; e4l = true; e4r = false;
					break;
				}
			}
		}
		if (e4u) {
			ax4 = y.getPosition().x;
			ay4 = y.getPosition().y;
			if (enamy[ay4 - 1][ax4] != '#') {
				if (enamy[ay4 - 1][ax4] != '*')
					y.move(0, -1);
			}
		}
		if (e4d) {
			ax4 = y.getPosition().x;
			ay4 = y.getPosition().y;
			if (enamy[ay4 + 1][ax4] != '#') {
				if (enamy[ay4 + 1][ax4] != '*')
					y.move(0, 1);
			}
		}
		if (e4r) {
			ax4 = y.getPosition().x;
			ay4 = y.getPosition().y;
			if (enamy[ay4][ax4 + 1] != '#') {
				if (enamy[ay4][ax4 + 1] != '*')
					y.move(1, 0);
			}
		}
		if (e4l) {
			ax4 = y.getPosition().x;
			ay4 = y.getPosition().y;
			if (enamy[ay4][ax4 - 1] != '#') {
				if (enamy[ay4][ax4 - 1] != '*')
					y.move(-1, 0);
			}
		}
		if (blue) {
			ba = elapsed1.asSeconds();
			ca = 15 - (ba - ab);
			if (ca == 15) { y.setTextureRect(IntRect(12 * 32, 0, 32, 32)); }
			if ((s.getPosition().x == y.getPosition().x) && (s.getPosition().y == y.getPosition().y)) {
				y.setTextureRect(IntRect(13 * 32, 2 * 32, 32, 32));
				if (conter4 == 0) { conter4++; score += 50; sc_evils += 50; }
			}
			if (ca == 0) {
				y.setTextureRect(IntRect(6 * 32, 0, 32, 32));
			}
		}
	}
	void pac_man(char arr[100][100], Sprite& s, int& zx, int& zy, int& score, int x, bool u, bool d, bool r, bool l, Time& elapsed1, Music& s_score) {
		if ((zx == 0) && (zy == 11)) { s.setPosition(92, 11); }
		else if ((zx == 92) && (zy == 11)) { s.setPosition(0, 11); }
		if (u) {
			if (arr[zy][zx] == '.') {
				score++;
				arr[zy][zx] = ' ';
				s_score.play();
			}
			if (arr[zy - 1][zx] != '#') {
				s.move(0, -1);
			}
			s.setTextureRect(IntRect(x * 32, 3 * 32, 32, 32));
		}
		else if (d) {
			if (arr[zy][zx] == '.') {
				score++;
				arr[zy][zx] = ' ';
				s_score.play();
			}
			if (arr[zy + 1][zx] != '#') {
				if (arr[zy + 1][zx] != '*')
					s.move(0, 1);
			}
			s.setTextureRect(IntRect(x * 32, 1 * 32, 32, 32));
		}
		else if (l) {
			if (arr[zy][zx] == '.') {
				score++;
				arr[zy][zx] = ' ';
				s_score.play();
			}
			if (arr[zy][zx - 1] != '#') {
				s.move(-1, 0);
			}
			s.setTextureRect(IntRect(x * 32, 2 * 32, 32, 32));
		}
		else if (r) {
			if (arr[zy][zx] == '.') {
				score++;
				arr[zy][zx] = ' ';
				s_score.play();
			}
			if (arr[zy][zx + 1] != '#') {
				s.move(1, 0);
			}
			s.setTextureRect(IntRect(x * 32, 0 * 32, 32, 32));
		}
		if (arr[zy][zx] == '@') {
			ab = elapsed1.asSeconds();
			arr[zy][zx] = ' ';
			blue = true;
		}
	}
	void Ahmed_Gamal() {
		int score = 0, x = 0, k = 0;
		char arr[100][100] = { "#############################################################################################",
							  "#  . . . . . . . . . . . . . . .  . . . .#####. . . . . . . . . . . .  . . . . . . . . . . @#",
							  "#.###########.########################.#.#####.#.########################.#################.#",
							  "#.###########.########################.#.#####.#.########################.#################.# o   ",
							  "#.###########.########################.#. . . .#.########################.#################.#     ",
							  "#. . . . . . . . . . . . . . . . . .  .#.#####.#. . . . . . . . . . . .  . . . . . . . . . .# o   ",
							  "#.###########.###########.############.#.#####.#.############.####.############.###########.#     ",
							  "#. . . . . . .###########.############. . . . . . . . . . .  .####.############. . . . . . .# o   ",
							  "#############.###########.############.#######********#######.####.############.#############",
							  "#############. . . .  .  .############.#                    #.####. . . . . .  .#############",
							  "#############.###########.############.#                    #.####.############.#############",
							  "         . . . . . . . . . . . . .  . .######################. . . . . . . . . . . .         ",
							  "#############.###########.############. . . . . . . . . . . . #.###############.#############",
							  "#############.###########.############.##########.########.####.###############.#############",
							  "#############.###########. . . . . . .. . . . .  .########.####.  . . . .######.#############",
							  "#@ . . . . . .###########.############.##########.########.####.########.######. . . . . . @#",
							  "#.###########. .  . . .  .############.##########. . . .  .  . .####. . . . .  .###########.#",
							  "#.###########.###########.############.##########.########.#########.##########.###########.#",
							  "#. . . . ####. . . . . . . . . . . . . .  . . . . . . . . . . . .  . . . . . . .####. . .  .#",
							  "########.####.####.###################.##########.#########################.###.####.########",
							  "########.####.####.###################.##########.#########################.###.####.########",
							  "#. . . . . . .####.  . .#####. . . . . . . . . . . . . . . . . . . .#######.###. . . . . . .#",
							  "#.#####################.#####.#############.#########.#############.#######.###############.#",
							  "#.#####################.#####.#############.#########.#############.#######.###############.#",
							  "#@ . . . . . . . . . . .  .  . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . @#",
							  "#############################################################################################", },

			enamy[100][100] = { "#############################################################################################",
							  "#3 . . . . . c . . . . . . . . .  . . x 5#####3 x . . . . . . . . . .  . c . . . . . . . . 5#",
							  "#.###########.########################.#.#####.#.########################.#################.#     ",
							  "#.###########.########################.#.#####.#.########################.#################.#     ",
							  "#.###########.########################.#x . . 8#.########################.#################.#     ",
							  "#x . . . . . 9 . . . . . c. . . . .  .x#.#####.#x . . . . . .c. . c . .  4 . . c . . . . . 8#     ",
							  "#.###########.###########.############.#.#####.#.############.####.############.###########.#     ",
							  "#2 . . . . . 8###########.############x 4 . . 4 4 . . . . .  8####.############x . . . . . 1#",
							  "#############.###########.############.#######********#######.####.############.#############",
							  "#############x . . .  .  8############.#x       x          x#.####x . . . . .  8#############",
							  "#############.###########.############.#x     x x          x#.####.############.#############",
							  "         . . 9 . . . . . 9 . . . .  . 8######################x x .4. . . . . . 9 . .         ",
							  "#############.###########.############x          c        c  1#.###############.#############",
							  "#############.###########.############.##########.########.####.###############.#############",
							  "#############.###########x . . . . . .9 . . . .  8########.####x  . . . 5######.#############",
							  "#3 . . . . . 8###########.############.##########.########.####.########.######x . . . . . 5#",
							  "#.###########x .  . . .  8############.##########x . . . .9  . 1####3 . f . .  x###########.#",
							  "#.###########.###########.############.##########.########.#########.##########.###########.#",
							  "#2 . . .5####x . .c. . . 4 . . . . . .9.  . . . .9. . . . x . . .  .4. . . c . 8####3 . .  1#",
							  "########.####.####.###################.##########.#########################.###.####.########",
							  "########.####.####.###################.##########.#########################.###.####.########",
							  "#3 . . .0. . 1####2 .. 5#####3 . . . .x. . x . . 4 . c . . . . . . 5#######.###2 . .f. . . 5#",
							  "#.#####################.#####.#############.#########.#############.#######.###############.#",
							  "#.#####################.#####.#############.#########.#############.#######.###############.#",
							  "#2 . . . . . . . . . . 4  .  4 . . . . . . 4 . . . . x . . . . . . 4 . . . 4 . . . . . . . 1#",
							  "#############################################################################################", };
		bool u = false, d = false, l = false, r = false;
		RenderWindow ahmed(VideoMode(600, 620), "pacman");
		ahmed.setFramerateLimit(10);
		View view(FloatRect(0, -2, 100, 30));
		Event event; Font font;
		font.loadFromFile("COOPBL.ttf");
		Text mscore, ttime, conect, star, finsh, win;
		Texture character, sqaure, e1, e2, e3, evils, LIFE;
		character.loadFromFile("pacman.PNG");
		sqaure.loadFromFile("wall.PNG");
		evils.loadFromFile("evils.PNG");
		LIFE.loadFromFile("life.PNG");
		CircleShape point(0.3);  point.setFillColor(Color::White);
		CircleShape app(0.3);  app.setFillColor(Color::Yellow);
		RectangleShape rectangle(Vector2f(0.2, 0.2));
		rectangle.setTexture(&sqaure); rectangle.setScale(3.8, 3.8); rectangle.setFillColor(Color::Green);
		Sprite s(character), a(sqaure), q(evils), w(evils), t(evils), y(evils), eat(LIFE);
		a.setScale(0.069, 0.069);  a.setTextureRect(IntRect(0, 0, 15, 15));
		s.setTextureRect(IntRect(0, 0, 32, 32));  s.setPosition(2, 1);  s.setScale(0.035, 0.035);
		q.setTextureRect(IntRect(0, 0, 32, 32));  q.setPosition(48, 7);  q.setScale(0.037, 0.037);
		w.setTextureRect(IntRect(2 * 32, 0, 32, 32));  w.setPosition(43, 9);  w.setScale(0.037, 0.037);
		t.setTextureRect(IntRect(4 * 32, 0, 32, 32));  t.setPosition(55, 9);  t.setScale(0.037, 0.037);
		y.setTextureRect(IntRect(6 * 32, 0, 32, 32));   y.setPosition(50, 9);  y.setScale(0.037, 0.037);
		eat.setScale(0.07, 0.07);
		Clock clock;
		Music start, dead, s_score;
		start.openFromFile("pacman_beginning.wav"); dead.openFromFile("pacman_death.wav"); s_score.openFromFile("pacman_chomp.wav");
		while (ahmed.isOpen()) {
			k++;  Time elapsed1 = clock.getElapsedTime();
			Score(score, mscore, font);
			TIME(elapsed1, ttime, font);
			Time_eat(conect, font);
			while (ahmed.pollEvent(event)) {
				switch (event.type)
				{
				case Event::Closed:
					ahmed.close();
					break;
				case Event::KeyPressed:
					switch (event.key.code) {
					case Keyboard::Up:
						u = true; d = false; l = false; r = false;
						break;
					case Keyboard::Down:
						u = false; d = true; l = false; r = false;
						break;
					case Keyboard::Right:
						u = false; d = false; l = false; r = true;
						break;
					case Keyboard::Left:
						u = false; d = false; l = true; r = false;
						break;
					}
				}
			}
			x++;
			if (x >= 7) { x = 0; }
			if ((int)elapsed1.asSeconds() == 5) { t.setPosition(48, 7); }
			if ((int)elapsed1.asSeconds() == 10) { w.setPosition(48, 7); }
			if ((int)elapsed1.asSeconds() == 15) { y.setPosition(48, 7); }
			ahmed.clear();
			if (k == 1) {
				Start_game(star, font, start);
				ahmed.draw(star);
				ahmed.display();
				Sleep(2000);
			}
			ax1 = q.getPosition().x;  ay1 = q.getPosition().y;
			ax2 = w.getPosition().x;  ay2 = w.getPosition().y;
			ax3 = t.getPosition().x;  ay3 = t.getPosition().y;
			ax4 = y.getPosition().x;  ay4 = y.getPosition().y;
			zx = s.getPosition().x;   zy = s.getPosition().y;
			srand(time(NULL));
			pac_man(arr, s, zx, zy, score, x, u, d, r, l, elapsed1, s_score);
			if (((s.getPosition().x == q.getPosition().x) && (s.getPosition().y == q.getPosition().y) && blue == false)
				|| ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y == w.getPosition().y) && blue == false)
				|| ((s.getPosition().x == t.getPosition().x) && (s.getPosition().y == t.getPosition().y) && blue == false)
				|| ((s.getPosition().x == y.getPosition().x) && (s.getPosition().y == y.getPosition().y) && blue == false)) {
				conter_life--;
				if (arr[3][94] == 'o') { arr[3][94] = ' '; }
				else if (arr[5][94] == 'o') { arr[5][94] = ' '; }
				else if (arr[7][94] == 'o') { arr[7][94] = ' '; }
				if (conter_life > 0) { q.setPosition(48, 7);  w.setPosition(43, 9); t.setPosition(55, 9);  y.setPosition(50, 9); }
				if (conter_life == 0) {
					Finsh(finsh, font, dead);
					ahmed.draw(finsh);
					ahmed.display();
					Sleep(2000); break;
				}
			}
			gost1(enamy, s, q, ax1, ay1, elapsed1, score);
			gost2(enamy, ax2, ay2, s, w, elapsed1, score);
			gost3(enamy, s, t, ax3, ay3, elapsed1, score);
			gost4(enamy, s, y, ax4, ay4, elapsed1, score);
			if (score - sc_evils == 450) {
				Win(win, font);
				ahmed.draw(win);
				ahmed.display();
				Sleep(2000);  break;
			}
			if (blue) {
				if ((s.getPosition().x == q.getPosition().x) && (s.getPosition().y == q.getPosition().y)) {
					q.setTextureRect(IntRect(13 * 32, 2 * 32, 32, 32));
					if (conter1 == 0) { conter1++; score += 50;  sc_evils += 50; }
				}
				if ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y == w.getPosition().y)) {
					w.setTextureRect(IntRect(13 * 32, 2 * 32, 32, 32));
					if (conter2 == 0) { conter2++; score += 50;  sc_evils += 50; }
				}
				if ((s.getPosition().x == t.getPosition().x) && (s.getPosition().y == t.getPosition().y)) {
					t.setTextureRect(IntRect(13 * 32, 2 * 32, 32, 32));
					if (conter3 == 0) { conter3++; score += 50;  sc_evils += 50; }
				}
				if ((s.getPosition().x == y.getPosition().x) && (s.getPosition().y == y.getPosition().y)) {
					y.setTextureRect(IntRect(13 * 32, 2 * 32, 32, 32));
					if (conter4 == 0) { conter4++; score += 50;  sc_evils += 50; }
				}
				if (ca == 0) {
					q.setTextureRect(IntRect(0 * 32, 0, 32, 32)); w.setTextureRect(IntRect(2 * 32, 0, 32, 32));
					t.setTextureRect(IntRect(4 * 32, 0, 32, 32)); y.setTextureRect(IntRect(6 * 32, 0, 32, 32));
				}
			}
			if (ca == 0) { blue = false; conter1 = 0; conter2 = 0; conter3 = 0; conter4 = 0; }
			for (int i = 0; i < 29; i++) {
				for (int j = 0; j < 100; j++) {
					if (arr[i][j] == '#') {
						a.setPosition(j, i);
						ahmed.draw(a);
					}
					else if (arr[i][j] == '.') {
						point.setPosition(j + 0.2, i + 0.2);
						ahmed.draw(point);
					}
					else if (arr[i][j] == '@') {
						app.setPosition(j + 0.2, i + 0.2);
						ahmed.draw(app);
					}
					else if (arr[i][j] == '*') {
						rectangle.setPosition(j, i);
						ahmed.draw(rectangle);
					}
					else if (arr[i][j] == 'o') {
						eat.setPosition(j, i);
						ahmed.draw(eat);
					}
				}
			}

			if (elapsed1.asSeconds() >= 5.0f * 60) { break; }
			ahmed.setView(view);
			ahmed.draw(q);
			ahmed.draw(w);
			ahmed.draw(t);
			ahmed.draw(y);
			ahmed.draw(mscore);
			ahmed.draw(ttime);
			ahmed.draw(conect);
			ahmed.draw(s);
			ahmed.display();
			if (((s.getPosition().x == q.getPosition().x) && (s.getPosition().y == q.getPosition().y) && blue == false)
				|| ((s.getPosition().x == w.getPosition().x) && (s.getPosition().y == w.getPosition().y) && blue == false)
				|| ((s.getPosition().x == t.getPosition().x) && (s.getPosition().y == t.getPosition().y) && blue == false)
				|| ((s.getPosition().x == y.getPosition().x) && (s.getPosition().y == y.getPosition().y) && blue == false)) {
				conter_life--;
				if (arr[3][94] == 'o') { arr[3][94] = ' '; }
				else if (arr[5][94] == 'o') { arr[5][94] = ' '; }
				else if (arr[7][94] == 'o') { arr[7][94] = ' '; }

				if (conter_life > 0) { q.setPosition(48, 7);  w.setPosition(43, 9); t.setPosition(55, 9);  y.setPosition(50, 9); }
				if (conter_life == 0) {
					Finsh(finsh, font, dead);
					ahmed.draw(finsh);
					ahmed.display();
					Sleep(2000); break;
				}
			}
		}
	}
}level5;
int main() {

	level5.Ahmed_Gamal();

	return 0;
}
