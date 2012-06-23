#ifndef SERVERCHOICE_H
#define SERVERCHOICE_H

#include <QtGui>
#include "centralwidget.h"

/* This is the dialog, when you click on "Go Online" from the menu.
   It requests a hostname/IP address to connect to, and then
   the signal textValueSelected or rejected is emitted */

class QCompactTable;
class Analyzer;

class ServerChoice : public QFrame, public CentralWidgetInterface
{
    Q_OBJECT
public:
    ServerChoice(const QString &nick);
    ~ServerChoice();

    QSize defaultSize() const {
        return QSize(500, 450);
    }

    void saveSettings();

public slots:
    void setRegistryAnnouncement(const QString &announcement);
    void addServer(const QString &name, const QString &desc, quint16 num, const QString &ip, quint16 max, quint16 port, bool passwordProtected);
    void openURL(QUrl url); // Just to avoid showing links in registry.

signals:
    void serverChosen(const QString &ip, const quint16 port, const QString &nick);
    void rejected();
private slots:
    void showDetails(int row);
    void regServerChosen(int row);
    void advServerChosen();
    void connectionError(int , const QString &mess);
    void connectToLocalhost();
private:
    QTextBrowser *announcement;
    QCompactTable *mylist;
    QLineEdit *myAdvServer;
    QLineEdit *myName;
    QTextBrowser *myDesc;
    Analyzer *registry_connection;

    QHash<QString, QString> descriptionsPerIp;
};

#endif // SERVERCHOICE_H