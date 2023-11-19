#include <iostream>
#include "UI.h"
#include "GraphicEditor.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

GraphicEditor::GraphicEditor() {
	cout << "그래픽 에디터입니다." << endl;
	pStart = nullptr;
	pLast = nullptr;
	run();
}
GraphicEditor::~GraphicEditor() {
	Shape* p = pStart;
	Shape* q;
	while (p != nullptr)
	{
		q = p->getNext();
		delete p;
		p = q;
	}
}
void GraphicEditor::run() {
	int num;
	while (true)
	{
		num = UI::menuUI();
		if (num == 1)
			insertShape(UI::insertUI());
		else if (num == 2)
			deleteShape(UI::deleteUI());
		else if (num == 3)
			show();
		else
			return;
	}
}
void GraphicEditor::show() {
	Shape* p = pStart;
	for (int i = 0; p != nullptr; i++) {
		cout << i << ":";
		p->paint();
		p = p->getNext();
	}
}
void GraphicEditor::insertShape(int n) {
	Shape* p = nullptr;
	switch (n) {
	case 1:
		p = new Line();
		break;
	case 2:
		p = new Circle();
		break;
	case 3:
		p = new Rect();
		break;
	}
	if (!pStart) {
		pStart = p;
		pLast = pStart;
	}
	else {
		pLast = pLast->add(p);
	}
}
void GraphicEditor::deleteShape(int n) {
	Shape* p = pStart;
	if (n == 0) {
		pStart = p->getNext();
		delete p;
	}
	else {
		Shape* q = p;
		p = p->getNext();
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				q->add(p->getNext());
				delete p;
				break;
			}
			q = p;
			p = p->getNext();
		}
	}
}
