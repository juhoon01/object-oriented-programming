#pragma once
#include "Shape.h"

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor();
	~GraphicEditor();
	void run();
	void show();
	void insertShape(int n);
	void deleteShape(int n);
};