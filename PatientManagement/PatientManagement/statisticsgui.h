#pragma once

#include <QWidget>
#include "ui_statisticsgui.h"

#include "Observer.h"
#include "Service.h"

class StatisticsGui : public QWidget, public Observer {
	Q_OBJECT
private:
	Service* service;

public:
	explicit StatisticsGui(Service* service, QWidget *parent = nullptr);
	~StatisticsGui() override;
	void update() override;
	virtual void paintEvent(QPaintEvent* event);

private:
	Ui::StatisticsGuiClass* ui;
};
