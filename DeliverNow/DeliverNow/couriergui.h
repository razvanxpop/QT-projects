#pragma once

#include <QWidget>
#include "ui_couriergui.h"

#include "Observer.h"
#include "Controller.h"

class CourierGui : public QWidget, public Observer {
	Q_OBJECT

private:
	Controller* controller;
	Courier* courier;

public:
	explicit CourierGui(QWidget* parent = nullptr);
	~CourierGui() override;
	void init(Controller* controller, Courier* courier);
	void makeConnections();
	void update() override;
	void getPackagesOnSelectedStreet();
	void deliverPackage();

private:
	Ui::CourierGuiClass* ui;
};