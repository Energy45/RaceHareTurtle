#ifndef COURSEWINDOW_H
#define COURSEWINDOW_H

#include <QDialog>
#include <QPixmap>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include "Tortue.h"
#include "Lievre.h"

struct Player
{
    QLabel* m_label;
    Participant* m_participant;
};

class CourseWindow : public QDialog
{
    Q_OBJECT

public:
    CourseWindow(int _nbHare, int _nbTurtle, QWidget *parent = nullptr);
    ~CourseWindow();

private:
    vector<Player> players;
    QTimer* m_timer;

    const int MAX_CASES = 70;
    const int RESOLUTION = 64;

private slots:
    void updateCourse();
};
#endif // COURSEWINDOW_H
