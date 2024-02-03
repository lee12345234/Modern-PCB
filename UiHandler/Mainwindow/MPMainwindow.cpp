#include "MPMainwindow.h"
#include <QMenuBar>
#include <QGraphicsView>
#include <QLineEdit>
#include <QPushButton>
MPMainwindow::MPMainwindow() : QMainWindow()
{
    InitUI();

}

void MPMainwindow::InitConnectAndSignals()
{
    
}

void MPMainwindow::InitMenuConnectAndSignal()
{
}

void MPMainwindow::InstallEventFilter()
{

}

void MPMainwindow::InitUI()
{
    m_MPWidget = new QWidget(this);
    m_MPWidget->setMinimumSize(1200, 800);
    this->setCentralWidget(m_MPWidget);
    InitLayout();
    InitBackGroud();
    InitMenu();
    InitToolBar();
    InitConnectAndSignals();
    
}

bool MPMainwindow::eventFilter(QObject* watch, QEvent* event)
{
    return false;
}

void MPMainwindow::InitMenu()
{
    QColor color;
    color.setRgb(25, 25, 112, 100);

    auto bar = QMainWindow::menuBar();
    bar->setStyleSheet("QMenuBar{background-color:rgba(50,50,50);} \
                        QMenuBar::item{ font - size:12px; font - family:Arial; color:rgba(255,255,255,1); } \
                        \
                        ");

    QMenu* file = bar->addMenu("File");
    file->setStyleSheet("QMenu {font-family: Arial; color:white ;} \
                         QMenu {background-color: black;} \
                         \
                        ");

    m_fileSave = file->addAction("Save File");
    m_fileOpen = file->addAction("Open File");
    
    this->setMenuBar(bar);
}

void MPMainwindow::InitToolBar()
{
}

void MPMainwindow::InitLayout()
{
    m_layout = new QVBoxLayout;
    m_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_MPWidget->setLayout(m_layout);
    
}

void MPMainwindow::InitBackGroud()
{
    QColor color;
    color.setRgb(30, 30, 30);
    auto pal = m_MPWidget->palette();
    pal.setColor(QPalette::Window, color);
    m_MPWidget->setAutoFillBackground(true);
    m_MPWidget->setPalette(pal);
    
}
