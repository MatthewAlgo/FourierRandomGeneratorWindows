#include <iostream>
#include <vector>
#include <cstring>
#include <Bits.h>
#include <algorithm>
#include <fstream>
#include <random>
#include <time.h>
#include "graphics.h"
#define CENTERX 250
#define CENTERY 250
#define NUMBEROFLINES 10
#define NUMBEROFLINESTWO 10
#define ULL unsigned long long
using namespace std;


time_t timer;
struct tm y2k = { 0 };
ULL iter = 0, cntor = 0;
unsigned long long seconds;
long long prevx, prevy,currx,curry;
unsigned long long culoarea,culoarea2;
double angle1 = 0;
unsigned long long contor = 0;
unsigned long long cntiter = 0;
int w1, wgraph, wgraphx,w2,wshape;
double trand(double lower, double upper) {
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_int_distribution<int> distribution_1_1000(lower, upper);

	double randomNumber = distribution_1_1000(random_engine);

	return (double)randomNumber;
}
double trandreal(double lower, double upper) {
	std::random_device random_device;
	std::mt19937 random_engine(random_device());
	std::uniform_real_distribution<double> distribution_1_1000(lower, upper);

	double randomNumber = distribution_1_1000(random_engine);

	return (double)randomNumber;
}
class lines {
public:
	double length;
	double x1, x2, y1, y2;
	double angle = 0;
	double angleincrement;
	//long long angle = 0;
	void drawline() {
		line(x1, y1, x2, y2);
	}
	void drawcircle() {
		circle(x2, y2, 5);
	}
	void determinerandomangleincrement() {
		angleincrement = trandreal(0.001, 0.1);
		//angleincrement = 0.01;
	}
	void addincrementtoangle() {
		angle += angleincrement;
	}
};
class linestwo {
public:
	double length;
	double x1, x2, y1, y2;
	double angle = 0;
	double angleincrement;
	//long long angle = 0;
	void drawline() {
		line(x1, y1, x2, y2);
	}
	void drawcircle() {
		circle(x2, y2, 5);
	}
	void determinerandomangleincrement() {
		angleincrement = trandreal(0.001, 0.1);
		//angleincrement = 0.01;
	}
	void addincrementtoangle() {
		angle += angleincrement;
	}
};
std::vector <linestwo> liniedoi;
std::vector <lines> linie;
std::vector <double> yvalues;
std::vector <double> xvalues;
void drawyvaluesgraph() {
	setcurrentwindow(wgraph);
	setcolor(YELLOW);
	line(500, 0, 500, 500);
	line(0, 250, 1000, 250);
	setcolor(WHITE);
	for (unsigned int i = 1; i < yvalues.size(); i++) {
		line(i - 1, yvalues[i - 1], i, yvalues[i]);
	}
	cleardevice();
	setcurrentwindow(w1);
}
void drawxvaluesgraph() {
	setcurrentwindow(wgraphx);
	setcolor(YELLOW);
	line(500, 0, 500, 500);
	line(0, 250, 1000, 250);
	setcolor(WHITE);
	for (unsigned int i = 1; i < yvalues.size(); i++) {
		line(i - 1, xvalues[i - 1], i, xvalues[i]);
	}
	cleardevice();
	setcurrentwindow(w1);
}
void showresults() {
	cntor++;
	std::cout << "_________REPORT NO " << cntor << " _________" << endl;
	std::cout << "CURRENT X VALUE: " << liniedoi[liniedoi.size() - 1].x2 << endl;
	std::cout << "CURRENT Y VALUE: " << linie[linie.size() - 1].y2 << endl << endl;
}
int main() {
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
	w1 = initwindow(500, 500, "FourierGeneratorY");
	w2 = initwindow(500, 500, "FourierGeneratorX");
	wgraph = initwindow(1000, 500, "FourierGraphForYcoord");
	wgraphx = initwindow(1000, 500, "FourierGraphForXcoord");
	wshape = initwindow(500, 500, "FourierDrawingXY");
	
	setcurrentwindow(w1);
	setcolor(WHITE);

	circle(250, 250, 100);
	circle(250, 250, 200);
	circle(250, 250, 300);
	circle(250, 250, 400);
	setcurrentwindow(w2);
	circle(250, 250, 100);
	circle(250, 250, 200);
	circle(250, 250, 300);
	circle(250, 250, 400);
	unsigned long long lengthe = 100;
	for (double i = 1; i <= NUMBEROFLINES; i++) {
		lines are;
		if (i == 1) {
			are.x1 = 250;
			are.y1 = 250;
		}
		are.length = trandreal(10, 40);
		
		are.determinerandomangleincrement();

		if (i == 1) {
			are.x2 = are.x1 + are.length * sin(are.angle);
			are.y2 = are.y1 + are.length * cos(are.angle);
		}
		linie.push_back(are);
	}
	for (double i = 1; i <= NUMBEROFLINESTWO; i++) {
		linestwo area;
		if (i == 1) {
			area.x1 = 250;
			area.y1 = 250;
		}
		area.length = trandreal(10, 40);
		
		area.determinerandomangleincrement();
	
		if (i == 1) {
			area.x2 = area.x1 + area.length * sin(area.angle);
			area.y2 = area.y1 + area.length * cos(area.angle);
		}
		liniedoi.push_back(area);
	}
	for (unsigned int i = 1; i < linie.size(); i++) {
		linie[i].x1 = linie[i - 1].x2;
		linie[i].y1 = linie[i - 1].y2;
		linie[i].x2 = linie[i].x1 + linie[i].length * sin(linie[i].angle);
		linie[i].y2 = linie[i].y1 + linie[i].length * cos(linie[i].angle);
	}
	for (unsigned int i = 1; i < liniedoi.size(); i++) {
		liniedoi[i].x1 = liniedoi[i - 1].x2;
		liniedoi[i].y1 = liniedoi[i - 1].y2;
		liniedoi[i].x2 = liniedoi[i].x1 + liniedoi[i].length * sin(liniedoi[i].angle);
		liniedoi[i].y2 = liniedoi[i].y1 + liniedoi[i].length * cos(liniedoi[i].angle);
	}
	while (true) {
		time(&timer);
		seconds = difftime(timer, mktime(&y2k));
		linie[0].x2 = linie[0].x1 + linie[0].length * sin(linie[0].angle);
		linie[0].y2 = linie[0].y1 + linie[0].length * cos(linie[0].angle);
		//
		liniedoi[0].x2 = liniedoi[0].x1 + liniedoi[0].length * sin(liniedoi[0].angle);
		liniedoi[0].y2 = liniedoi[0].y1 + liniedoi[0].length * cos(liniedoi[0].angle);
		for (unsigned int i = 1; i < linie.size(); i++) {
			linie[i].x1 = linie[i - 1].x2;
			linie[i].y1 = linie[i - 1].y2;
			linie[i].x2 = linie[i].x1 + linie[i].length * sin(linie[i].angle);
			linie[i].y2 = linie[i].y1 + linie[i].length * cos(linie[i].angle);
			//
			
		}
		for (unsigned int i = 1; i < liniedoi.size(); i++) {
			liniedoi[i].x1 = liniedoi[i - 1].x2;
			liniedoi[i].y1 = liniedoi[i - 1].y2;
			liniedoi[i].x2 = liniedoi[i].x1 + liniedoi[i].length * sin(liniedoi[i].angle);
			liniedoi[i].y2 = liniedoi[i].y1 + liniedoi[i].length * cos(liniedoi[i].angle);
		}
		
		contor++;
		if (contor > 2000) {
			contor--;
			yvalues.erase(yvalues.begin());
			yvalues.push_back(linie[linie.size() - 1].y2);
			xvalues.erase(xvalues.begin());
			xvalues.push_back(liniedoi[liniedoi.size() - 1].x2);
		}
		else {
			contor++;
			yvalues.push_back(linie[linie.size() - 1].y2);
			xvalues.push_back(liniedoi[liniedoi.size() - 1].x2);
		}
		/////
		
		setcurrentwindow(wgraph);
		setcolor(YELLOW);
		line(500, 0, 500, 500);
		line(0, 250, 1000, 250);
		setcolor(WHITE);
		for (unsigned int i = 1; i < yvalues.size(); i++) {
			line(i - 1, yvalues[i - 1], i, yvalues[i]);
		}
		setcurrentwindow(w1);
		///
		setcurrentwindow(wgraphx);
		setcolor(YELLOW);
		line(500, 0, 500, 500);
		line(0, 250, 1000, 250);
		setcolor(WHITE);
		for (unsigned int i = 1; i < xvalues.size(); i++) {
			line(i - 1, xvalues[i - 1], i, xvalues[i]);
		}
		setcurrentwindow(w1);
		drawxvaluesgraph();
		drawyvaluesgraph();
	
		cntiter++;
		if (cntiter == 100) {
			//cleardevice();
			culoarea = trand(1, 15);
			culoarea2 = trand(1, 15);
			cntiter = 0;
		}
		setcurrentwindow(w1);
		setcolor(culoarea);
		//setcolor(WHITE);
		for (unsigned int i = 0; i < linie.size(); i++) {
			//setcolor(culoarea);
			linie[i].drawline();
			linie[i].drawcircle();
			linie[i].addincrementtoangle();
		}
		setcurrentwindow(w2);
		setcolor(culoarea2);
		for (unsigned int i = 0; i < liniedoi.size(); i++) {
			//setcolor(culoarea);
			liniedoi[i].drawline();
			liniedoi[i].drawcircle();
			liniedoi[i].addincrementtoangle();
		}
		setcurrentwindow(wshape);
		currx = xvalues.back();
		curry = yvalues.back();
		iter++;
		if (iter != 1) {
			line(prevx, prevy, currx, curry);
		}
		prevx = xvalues.back();
		prevy = yvalues.back();
		setcurrentwindow(w1);
		setcolor(WHITE);
		showresults();
		
	}
	
	delay(10000);
	return 0;
}

