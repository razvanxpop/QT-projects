#pragma once

#include <QWidget>
#include "ui_map.h"

#include "Observer.h"
#include "Controller.h"

class Map : public QWidget, public Observer {
	Q_OBJECT
private:
	Controller* controller;
public:
	explicit Map(Controller* controller = nullptr, QWidget* parent = nullptr);
	~Map() override;
	void update() override;
	virtual void paintEvent(QPaintEvent* event);

private:
	Ui::MapClass* ui;
};
