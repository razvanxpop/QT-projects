#pragma once

#include <QWidget>
#include "ui_departmentgui.h"

#include "Observer.h"
#include "Service.h"

class DepartmentGui : public QWidget, public Observer {
Q_OBJECT
private:
	Service* service;
	Department* department;
public:
	explicit DepartmentGui(QWidget *parent = nullptr);
	~DepartmentGui() override;
	void update() override;
	void init(Service* service, Department* department);
	void makeConnections();
	void addVolunteer();
	void assignVolunteer();
	void mostSuitable();

private:
	Ui::DepartmentGuiClass* ui;
};
