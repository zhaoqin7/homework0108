#include <QCoreApplication>
#include <iostream>
#include <QString>
#include <algorithm>
#include <QVector>
#include <QDebug>

using namespace std;
class student{
public:
    QString name;
    int num;
    int class1;
    int class2;
};

// 按照姓名进行排序
bool sortname(const student &s1, const student &s2){
    return s1.name< s2.name;
}
// 按照class1进行排序
bool sortclass1(const student &s1, const student &s2){
    return s1.class1< s2.class1;
}
// 按照class2进行排序
bool sortclass2(const student &s1, const student &s2){
    return s1.class2< s2.class2;
}

int main(int argc, char *argv[])
{
    student s[4];
    s[0].num=1403140103;s[0].name="武松";s[0].class1=88;s[0].class2=80;
    s[1].num=1403140101;s[1].name="林冲";s[1].class1=82;s[1].class2=76;
    s[2].num=1403130209;s[2].name="鲁智深";s[2].class1=80;s[2].class2=72;
    s[3].num=1403140102;s[3].name="宋江";s[3].class1=76;s[3].class2=85;
    QList<student> vec;
    vec.append( s[0]);vec.append( s[1]);vec.append( s[2]);vec.append( s[3]);
    qDebug() << "排序前:";

   for (int it=0; it<4; it++)
             {
                qDebug()<< vec[it].num << vec[it].name << vec[it].class1 <<vec[it].class2 ;

    }
    sort(vec.begin(), vec.end(), sortname);
    qDebug() << "按名字排序:";
    for (int it=0; it<4; it++)
             {
                qDebug()<< vec[it].num << vec[it].name << vec[it].class1 <<vec[it].class2 ;


    }

    sort(vec.begin(), vec.end(), sortclass1);
    qDebug() << "按class1排序:";
   for (int it=0; it<4; it++)
             {
                 qDebug()<< vec[it].num << vec[it].name << vec[it].class1 <<vec[it].class2 ;
}

    sort(vec.begin(), vec.end(), sortclass2);
    qDebug() << "按class2排序:";
   for (int it=0; it<4; it++)
             {
                  qDebug()<< vec[it].num << vec[it].name << vec[it].class1 <<vec[it].class2 ;

    }
}
