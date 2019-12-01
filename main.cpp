#include "fen_lancercourse.h"

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FEN_LancerCourse w;
    w.show();
    return a.exec();
}
