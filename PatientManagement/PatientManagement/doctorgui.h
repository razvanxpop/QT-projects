#pragma once

#include <QWidget>
#include "ui_doctorgui.h"

#include "Observer.h"
#include "Service.h"

class DoctorGui : public QWidget, public Observer {
Q_OBJECT
private:
	Service* service;
	Doctor* doctor;

public:
	explicit DoctorGui(QWidget *parent = nullptr);
	~DoctorGui() override;
	void update() override;
	void init(Service* service, Doctor* doctor);
	void makeConnections();
	void checkBoxClicked();
	void addPatient();
	void updatePatient();

private:
	Ui::DoctorGuiClass* ui;
};
