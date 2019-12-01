#ifndef FEN_LANCERCOURSE_H
#define FEN_LANCERCOURSE_H

#include <QDialog>
#include "ui_fen_lancercourse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FEN_LancerCourse; }
QT_END_NAMESPACE

class FEN_LancerCourse : public QDialog
{
    Q_OBJECT

public:
    FEN_LancerCourse(QWidget *parent = nullptr);
    ~FEN_LancerCourse();

private:
    Ui::FEN_LancerCourse *ui;

private slots:
    void launchRace();
};
#endif // FEN_LANCERCOURSE_H
