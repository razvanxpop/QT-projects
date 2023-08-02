#pragma once

#include <QWidget>
#include "ui_drivergui.h"

#include "Observer.h"
#include "Service.h"

class DriverGui : public QWidget, public Observer {
Q_OBJECT

private:
	Service* service;
	Driver* driver;

public:
	explicit DriverGui(QWidget *parent = nullptr);
	~DriverGui() override;
	void init(Service* service, Driver* driver);
	void update() override;
	void makeConnections();
	void addReport();
	void addMessage();
	void validateReport();

private:
	Ui::DriverGuiClass* ui;
};
