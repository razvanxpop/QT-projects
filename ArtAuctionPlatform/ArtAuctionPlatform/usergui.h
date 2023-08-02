#pragma once

#include <QWidget>
#include "ui_usergui.h"

#include "Observer.h"
#include "Service.h"

class UserGui : public QWidget, public Observer {
Q_OBJECT

private:
	Service* service;
	User* user;

public:
	explicit UserGui(QWidget *parent = nullptr);
	~UserGui() override;
	void init(Service* service, User* user);
	void update() override;
	void makeConnections();
	void filterByCategory();
	void viewItemOffers();
	void addButton();
	void bidForSelectedItem();

private:
	Ui::UserGuiClass* ui;
};
