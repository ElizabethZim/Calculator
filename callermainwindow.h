

#ifndef UNTITLED5_CALLERMAINWINDOW_H
#define UNTITLED5_CALLERMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <exception>
#include <QRegExp>


#include <iostream>
using namespace std;


class CallerMainWindow : public QMainWindow{
Q_OBJECT
public:
    QLineEdit *lineEdit = nullptr;

    CallerMainWindow(QWidget *parent = nullptr): QMainWindow(parent){ }

public slots:
    void slot0(){lineEdit->setText(lineEdit->text() + "0");};
    void slot1(){lineEdit->setText(lineEdit->text() + "1");};
    void slot2(){lineEdit->setText(lineEdit->text() + "2");};
    void slot3(){lineEdit->setText(lineEdit->text() + "3");};
    void slot4(){lineEdit->setText(lineEdit->text() + "4");};
    void slot5(){lineEdit->setText(lineEdit->text() + "5");};
    void slot6(){lineEdit->setText(lineEdit->text() + "6");};
    void slot7(){lineEdit->setText(lineEdit->text() + "7");};
    void slot8(){lineEdit->setText(lineEdit->text() + "8");};
    void slot9(){lineEdit->setText(lineEdit->text() + "9");};
    void slotDot(){lineEdit->setText(lineEdit->text() + ".");};
    void slotMult(){lineEdit->setText(lineEdit->text() + "*");};
    void slotDel(){lineEdit->setText(lineEdit->text() + "/");};
    void slot_(){lineEdit->setText(lineEdit->text() + "-");};
    void slotAddition(){lineEdit->setText(lineEdit->text() + "+");};
    void MakeResult(){lineEdit->setText(Result(lineEdit->text()));};
    void ClearF(){
        QString l = lineEdit->text();
        lineEdit->setText(l.mid(0, l.size() - 1));
    }

    void MakeClearAll(){lineEdit->setText("");};

public:
    bool isHex(const QString &str){
        QRegExp reg("[0-9a-hA-H]+");
        return reg.indexIn(str) != -1;
    }

    double operation(double firstNumber, QChar y, double secondNumber){
        double result = 0;
            if (y == '+') result = firstNumber + secondNumber;
            else if (y == '-') result = firstNumber - secondNumber;
            else if (y == '*') result = firstNumber * secondNumber;
            else if (y == '/' ){
                if (secondNumber == 0) {
                    throw exception();
                }
                result = firstNumber / secondNumber;
            }

        return result;

    }


    QString Result(QString l ) {

        double firstNumber;
        double secondNumber;

        int n = l.size();
        QString str = "";
        QChar y;
        double result;
        int i = 0;


        while (l.data()[i] != '+' && l.data()[i] != '/' && l.data()[i] != '-' && l.data()[i] != '*') {
            str.append(l.data()[i]);
            i++;
        }


        if (isHex(str)) firstNumber = str.toDouble();
        else throw invalid_argument("Invalid argument");


        y = l.data()[i];
        i++;
        str.clear();


        while (i < n && l.data()[i] != '+' && l.data()[i] != '/' && l.data()[i] != '-' && l.data()[i] != '*') {
            str.append(l.data()[i]);
            i++;
        }

        if (isHex(str)) secondNumber = str.toDouble();
         else throw invalid_argument("Invalid argument");
        try {
            result = operation(firstNumber, y, secondNumber);
        }
        catch (const exception& x){
            cerr << x.what() << endl;
            return "Error!";
        }

        if (i + 1 < n) result = Result(QString::number(result) + l.mid(i)).toDouble();



        return QString::number(result);

}
};


#endif //UNTITLED5_CALLERMAINWINDOW_H
