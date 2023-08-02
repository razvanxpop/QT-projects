#pragma once

#include <QWidget>
#include "ui_showdepartmentsgui.h"

#include "Observer.h"
#include "Service.h"

class ShowDepartmentsGui : public QWidget, public Observer {
Q_OBJECT
private:
	Service* service;
public:
	explicit ShowDepartmentsGui(Service* service, QWidget *parent = nullptr);
	~ShowDepartmentsGui() override;
	void update() override;

private:
	Ui::ShowDepartmentsGuiClass* ui;
};
