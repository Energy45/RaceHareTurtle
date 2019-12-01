#include "fen_lancercourse.h"

FEN_LancerCourse::FEN_LancerCourse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FEN_LancerCourse)
{
    ui->setupUi(this);

    connect(ui->btn_LaunchRace, &QPushButton::clicked, this, &FEN_LancerCourse::launchRace);
}

FEN_LancerCourse::~FEN_LancerCourse()
{
    delete ui;
}

void FEN_LancerCourse::launchRace()
{
    if(ui->spBx_hares->value() > 0 || ui->spBx_turtles->value() > 0) // Si il y a au moins une tortue ou un lievre
    {

    }
    else
    {
        //TODO Prevoir un label d'erreur
    }
}

