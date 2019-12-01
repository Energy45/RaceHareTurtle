#include "coursewindow.h"

CourseWindow::CourseWindow(QWidget *parent)
    : QDialog(parent)
{
    setGeometry(0, 0, 800, 800);

    srand(static_cast<unsigned int>(time(nullptr)));

    players.push_back(Player{new QLabel(this),
                      new Tortue()});
    players.push_back(Player{new QLabel(this),
                      new Lievre()});
    players.push_back(Player{new QLabel(this),
                      new Lievre()});

    for(unsigned int i = 0; i < players.size(); i++)
    {
        if(dynamic_cast<Tortue*>(players.at(i).m_participant) != nullptr) // TORTUE
        {
            players.at(i).m_label->setPixmap(QPixmap("F:\\turtle.png"));
        }
        else if(dynamic_cast<Lievre*>(players.at(i).m_participant) != nullptr)
        {
            players.at(i).m_label->setPixmap(QPixmap("F:\\hare.jpg"));
        }
        players.at(i).m_label->setGeometry(0, static_cast<int>(i*RESOLUTION), static_cast<int>(RESOLUTION), static_cast<int>(RESOLUTION));
    }

    m_timer = new QTimer(this);

    connect(m_timer, &QTimer::timeout, this, &CourseWindow::updateCourse);
    m_timer->start(100);
}

CourseWindow::~CourseWindow()
{
    delete m_timer;
    if(!players.empty())
    {
        for(unsigned int i = 0; i < players.size(); i++)
        {
            if(players.at(i).m_participant != nullptr)
                delete players.at(i).m_participant;
            if(players.at(i).m_label != nullptr)
                delete players.at(i).m_label;
        }
    }
}

void CourseWindow::updateCourse()
{
    unsigned int nbWinners = 0;
    for(unsigned int i = 0; i < players.size(); i++)
    {
        players.at(i).m_participant->bouger();
        uint position = players.at(i).m_participant->getPosition();
        players.at(i).m_label->setGeometry(static_cast<int>(position*10), static_cast<int>(i*RESOLUTION), static_cast<int>(RESOLUTION), static_cast<int>(RESOLUTION));

        if(position >= MAX_CASES)
        {
            nbWinners++;
        }
    }

    if(nbWinners != 0)
    {
        m_timer->stop();
        cout << "Les gagnants sont : " << endl;
        for(unsigned int i = 0; i < players.size(); i++)
        {
            if(players.at(i).m_participant->getPosition() >= MAX_CASES) // Si le participant est a la ligne d'arrivée
            {
                cout << players.at(i).m_participant->getName() << "  " << players.at(i).m_participant->getPosition() << endl;
            }
            else
            {
                players.at(i).m_label->setVisible(false);
            }
        }
    }

}

