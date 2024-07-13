#include "stutmp.h"

stutmp::stutmp() {}

stutmp::stutmp(QString id, QString name, QString c1, QString c2, QString c3, QString c4, QString c5, QString c6, QString c7, QString t)
{
    s_id=id;
    s_name=name;
    course1=c1;
    course2=c2;
    course3=c3;
    course4=c4;
    course5=c5;
    course6=c6;
    course7=c7;
    test0=t;

    s_course1=getcourse1();
    s_course2=getcourse2();
    s_course3=getcourse3();
    s_course4=getcourse4();
    s_course5=getcourse5();
    s_course6=getcourse6();
    s_course7=getcourse7();
    test=gettest();
    final=s_course1+s_course2+s_course3+s_course4+s_course5+s_course6+s_course7+0.5*test;
}

stutmp::stutmp(const stutmp &c)
{
    s_id=c.s_id;
    s_name=c.s_name;
    course1=c.course1;
    course2=c.course2;
    course3=c.course3;
    course4=c.course4;
    course5=c.course5;
    course6=c.course6;
    course7=c.course7;
    test0=c.test0;
    test=c.test;

    s_course1=c.s_course1;
    s_course2=c.s_course2;
    s_course3=c.s_course3;
    s_course4=c.s_course4;
    s_course5=c.s_course5;
    s_course6=c.s_course6;
    s_course7=c.s_course7;

    final=c.final;
}
double stutmp::getcourse1()
{
    if(course1=="A"||course1=="A+"||course1=="A-")s_course1=5;
    else if(course1=="B"||course1=="B+"||course1=="B-")s_course1=4;
    else if(course1=="C"||course1=="C+"||course1=="C-")s_course1=3;
    else if(course1=="D"||course1=="D+"||course1=="D-")s_course1=1;
    else s_course1=0;

    return s_course1;
}

double stutmp::getcourse2()
{
    if(course2=="A"||course2=="A+"||course2=="A-")s_course2=5;
    else if(course2=="B"||course2=="B+"||course2=="B-")s_course2=4;
    else if(course2=="C"||course2=="C+"||course2=="C-")s_course2=3;
    else if(course2=="D"||course2=="D+"||course2=="D-")s_course2=1;
    else s_course2=0;

    return s_course2;
}

double stutmp::getcourse3()
{
    if(course3=="A"||course3=="A+"||course3=="A-")s_course3=5;
    else if(course3=="B"||course3=="B+"||course3=="B-")s_course3=4;
    else if(course3=="C"||course3=="C+"||course3=="C-")s_course3=3;
    else if(course3=="D"||course3=="D+"||course3=="D-")s_course3=1;
    else s_course3=0;

    return s_course3;
}

double stutmp::getcourse4()
{
    if(course4=="A"||course4=="A+"||course4=="A-")s_course4=5;
    else if(course4=="B"||course4=="B+"||course4=="B-")s_course4=4;
    else if(course4=="C"||course4=="C+"||course4=="C-")s_course4=3;
    else if(course4=="D"||course4=="D+"||course4=="D-")s_course4=1;
    else s_course4=0;

    return s_course4;
}

double stutmp::getcourse5()
{
    if(course5=="A")s_course5=9.5;
    else if(course5=="A+")s_course5=10;
    else if(course5=="A-")s_course5=9;
    else if(course5=="B+")s_course5=8.5;
    else if(course5=="B")s_course5=8;
    else if(course5=="B-")s_course5=7.5;
    else if(course5=="C+")s_course5=6.5;
    else if(course5=="C")s_course5=6;
    else if(course5=="C-")s_course5=5.5;
    else if(course5=="D+")s_course5=3.5;
    else if(course5=="D")s_course5=3;
    else if(course5=="D-")s_course5=2.5;
    else s_course5=0;

    return s_course5;
}

double stutmp::getcourse6()
{
    if(course6=="A")s_course6=9.5;
    else if(course6=="A+")s_course6=10;
    else if(course6=="A-")s_course6=9;
    else if(course6=="B+")s_course6=8.5;
    else if(course6=="B")s_course6=8;
    else if(course6=="B-")s_course6=7.5;
    else if(course6=="C+")s_course6=6.5;
    else if(course6=="C")s_course6=6;
    else if(course6=="C-")s_course6=5.5;
    else if(course6=="D+")s_course6=3.5;
    else if(course6=="D")s_course6=3;
    else if(course6=="D-")s_course6=2.5;
    else s_course6=0;

    return s_course6;
}

double stutmp::getcourse7()
{
    if(course7=="A")s_course7=9.5;
    else if(course7=="A+")s_course7=10;
    else if(course7=="A-")s_course7=9;
    else if(course7=="B+")s_course7=8.5;
    else if(course7=="B")s_course7=8;
    else if(course7=="B-")s_course7=7.5;
    else if(course7=="C+")s_course7=6.5;
    else if(course7=="C")s_course7=6;
    else if(course7=="C-")s_course7=5.5;
    else if(course7=="D+")s_course7=3.5;
    else if(course7=="D")s_course7=3;
    else if(course7=="D-")s_course7=2.5;
    else s_course7=0;

    return s_course7;
}

double stutmp::gettest()
{
    if(test0.toDouble()>=0&&test0.toDouble()<=100)  test=  test0.toDouble();
    else test= 0;
    return test;
}

double stutmp::getfinal()
{
    final=getcourse1()+getcourse2()+getcourse3()+getcourse4()+getcourse5()
            +getcourse6()+getcourse7()
            +0.5*gettest();
    return final;

}
