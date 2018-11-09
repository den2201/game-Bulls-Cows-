#include "password_window.h"
#include "rules.cpp"
#include <ctime>
#include<iostream>
#include <QDebug>

void function(int&,int&);
void func_sravn(int& numb ,int& my_numb);

Pass_Window::Pass_Window(QWidget *parent):QDialog(parent)
{
    QString number;
    number_of_answers=0;
    srand(time(NULL));
    programs_number=999+rand()%9000;
    qDebug()<<programs_number;

number.setNum(programs_number);


    mess_box=new QMessageBox;
    mess_box->resize(400,400);
    edit_pole=new QTextEdit;



    mess_box->setWindowTitle("НЕВЕРНО!!!");

    lab_input=new QLabel("Введите 4-х значное число и нажмите ОК:");
    lab_name_of_res=new QLabel("Кол-во попыток: ");
    lab_result=new QLabel("0");
    lab_temp=new QLabel("\t\t\t\t\t\t\t");
    pole_input=new QLineEdit;
    pole_input->resize(20,4);
    h_lay_1=new QHBoxLayout;
    h_lay_1->addWidget(lab_input);
    h_lay_1->addWidget(pole_input);
    h_lay_1->addWidget(lab_temp);
    h_box_result=new QHBoxLayout;
    h_box_result->addWidget(lab_name_of_res);
    h_box_result->addWidget(lab_result);
    h_box_result->addWidget(edit_pole);


    but_ok=new QPushButton("OK");
    but_close= new QPushButton("Выход");
    but_rules=new QPushButton("Праивла игры");
    v_lay_1=new QVBoxLayout;
    v_lay_1->addLayout(h_box_result);
    v_lay_1->addLayout(h_lay_1);

    v_lay_1->addWidget(but_ok);
    v_lay_1->addWidget(but_close);
    v_lay_1->addWidget(but_rules);
    setLayout(v_lay_1);




    resize(400,400);
    setWindowTitle("ИГРА 'БЫКИ и КОРОВЫ'");



QObject::connect(but_close,SIGNAL(clicked()),this,SLOT(close()));
QObject::connect(but_ok, &QPushButton::clicked,this, &Pass_Window::push_ok_btn);
QObject::connect(but_rules, &QPushButton::clicked,this, &Pass_Window::show_rules);



}



Pass_Window::~Pass_Window()
{
    delete [] mass_number;
    delete [] comp_number;



}


void Pass_Window::push_ok_btn()
{

    QString txt; int my_number;

    txt=pole_input->text();

    if((txt.isEmpty())||(txt.toInt()==0))
    {
        mess_box->setText("Введите 4-х значное число");
        mess_box->show();
    }
    else
    {

my_number=txt.toInt();
func_sravn(my_number, programs_number);

}

}

void Pass_Window:: func_sravn(int& numb ,int& my_numb)

{



if (numb==my_numb)
{
    mess_box_victory=new QMessageBox;
    QString text;


    mess_box_victory->setText("ВЫ УГАДАЛИ!!!");

    mess_box_victory->setWindowTitle("ПОБЕДА!!!");


    mess_box_victory->show();
    number_of_answers=0;
    lab_result->setNum(number_of_answers);





}
else
{

pole_input->selectAll();
pole_input->copy();
edit_pole->paste();
edit_pole->insertPlainText(" *** ");


    function(numb, my_numb);
    number_of_answers++;
    lab_result->setNum(number_of_answers);

}

pole_input->clear();



}

void function(int &numb, int& my_numb)
{


    int* mass_number=new int[4];
    int* comp_number=new int[4];
    int* bull=new int;
    int* cow=new int;
    int *temp=new int;
    *temp=0;
    *bull=0;
    *cow=0;

    mass_number[0] =my_numb/1000;
    mass_number[1]=(my_numb%1000)/100;
    mass_number[2]=(my_numb%100)/10;
    mass_number[3]=my_numb%10;
    comp_number[0] =numb/1000;
    comp_number[1]=(numb%1000)/100;
    comp_number[2]=(numb%100)/10;
    comp_number[3]=numb%10;


     for(int i=0;i<4;i++)
     {
         for(int j=0;j<4;j++)
         {
             if((mass_number[i]==comp_number[j])&&(i==j))
             {
                 (*bull)++;

             }
                else if((mass_number[i]==comp_number[j])&&(i!=j)&&(mass_number))
                 {
                     (*cow)++;

                 }
         }
     }


    QString text1, text2,text3; QMessageBox* messbox=new QMessageBox;

    text1.setNum(*bull);
    text2.setNum(*cow);
    messbox->resize(300,300);
    messbox->setText("В загаданном числе:\nБыков и Коров:\n"+text1+"\t"+text2);
    text3="В загаданном числе:\nБыков и Коров:\n"+text1+"\t"+text2;

    messbox->show();

    delete cow;
    delete bull;





}
