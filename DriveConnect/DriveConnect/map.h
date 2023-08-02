#pragma once

#include <QWidget>
#include "ui_map.h"

#include "Observer.h"
#include "Service.h"

class Map : public QWidget, public Observer {
Q_OBJECT

private:
	Service* service;

public:
	explicit Map(Service* service, QWidget *parent = nullptr);
	~Map() override;

private:
	void update() override;
	void paintEvent(QPaintEvent* event) override;

private:
	Ui::MapClass* ui;
};
