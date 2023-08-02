#pragma once

#include <QWidget>
#include "ui_couriercompanygui.h"

#include "Observer.h"
#include "Controller.h"

class CourierCompanyGui : public QWidget, public Observer
{
	Q_OBJECT
private:
	Controller* controller;

public:
	explicit CourierCompanyGui(Controller* controller, QWidget* parent = nullptr);
	~CourierCompanyGui() override;
	void update() override;
	void makeConnections();
	void addPackage();

private:
	Ui::CourierCompanyGuiClass* ui;
};
