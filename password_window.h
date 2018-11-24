#ifndef PASSWORD_WINDOW_H
#define PASSWORD_WINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QTextEdit>
#include "ctime"
#include <QPalette>
#include <QMediaPlayer>

class Pass_Window:public QDialog
{

    Q_OBJECT

private:

    QDialog* pass_win;
    QLabel *lab_input, *lab_name_of_res, *lab_result;
    QLineEdit* pole_input;
    QLabel* lab_temp;
    QHBoxLayout* h_lay_1,*h_box_result;
    QPushButton* but_ok;
    QPushButton* but_close;
    QPushButton* but_rules;
    QVBoxLayout* v_lay_1;
    QMessageBox* mess_box, *mess_box_victory;
    QTextEdit* edit_pole;
    QPalette* palet;
    QMediaPlayer* play_app;

    int* mass_number=new int[4];
    int* comp_number=new int[4];
    int programs_number;
     int number_of_answers;
void set_number()
{

    programs_number=999+rand()%9000;
    qDebug()<<programs_number;

number_of_answers++;

}

public:
    void func_sravn(int& numb ,int& my_numb);


        Pass_Window(QWidget* parent=nullptr);
    ~Pass_Window();

signals:
    void input_text();
    void copy_text(QString text);
    void sound();


public slots:
    void push_ok_btn();
    void show_rules();
    void sound_victory();

    friend void function(int &numb, int& my_numb);


};

#endif // PASSWORD_WINDOW_H
