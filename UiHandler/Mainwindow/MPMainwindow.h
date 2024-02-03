#pragma once
/*****************************************************************//**
 * \file   MPMainwindow.h
 * \brief  
 * 
 * \author liyingtai
 * \date   January 2024
 *********************************************************************/
#include <QMainwindow>
#include <QMenubar>
#include <QVBoxLayout>

class MPMainwindow :public QMainWindow
{
    Q_OBJECT
public:
    MPMainwindow();
    void InitConnectAndSignals();
    void InitMenuConnectAndSignal();
    void InstallEventFilter();
    void InitUI();

    bool eventFilter(QObject* watch, QEvent* event) override;
private:
    void InitBackGroud();
    void InitMenu();
    void InitToolBar();
    void InitLayout();

private:
    QAction* m_fileOpen = nullptr;
    QAction* m_fileSave = nullptr;
    QAction* m_fileCreate = nullptr;
    QWidget* m_MPWidget = nullptr;
    QVBoxLayout* m_layout = nullptr;
};

