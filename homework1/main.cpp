#include <QCoreApplication>
#include <iostream>
#include <QDebug>

#define number 0X12345678
#define pr(in) QString("0X%1").arg(in,0,16,QLatin1Char(' ')) //输出16进制

typedef quint32 doubleword;//定义32位的字
typedef quint8 byte;//定义8位的字

#define MAX(a,b) ((a) > (b) ? (a) : (b))//取出最大值
#define MIN(a,b) ((a) < (b) ? (a) : (b))//取出最小值

#define HHI(xxx) ( (byte) ((doubleword) (xxx) >> 24 )) //取出高16位中高8位
#define LHI(xxx) ( (byte) ((doubleword) (xxx) >> 16 ) & 255 ) //取出高16位中低8位
#define HLO(xxx) ( (byte) ((doubleword) (xxx) >> 8 ) & 255 ) //取出低16位中低8位
#define LLO(xxx) ( (byte) ((doubleword) (xxx) & 255 )) //取出低16位中低8位

int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);//qint32 number = 0X12345678;
QList <qint8> values;
qint32 i;

qDebug()<<"原始值:"<<pr(number)<<number<<endl; //输出16进制和10进制
qDebug()<<"最高8位:"<< pr(HHI(number)) <<dec<<HHI(number); //输出高16位中高8位，并转换为10进制
qDebug()<<"次高8位:"<< pr(LHI(number)) <<dec<<LHI(number); //输出高16位中高8位，并转换为10进制
qDebug()<<"次低8位:"<< pr(HLO(number)) <<dec<<HLO(number); //输出低16位中低8位，并转换为10进制
qDebug()<< "最低8位:"<<pr(LLO(number)) <<dec<<LLO(number)<<endl; //输出低16位中低8位，并转换为10进制

qDebug()<<"最高8位和次高8位的最大值为:"<<MAX(pr(HHI(number)) , pr(LHI(number)))<<MAX(HHI(number) , LHI(number));
qDebug()<<"次低8位和最低8位的最小值为:"<<MIN(pr(HLO(number)) , pr(LLO(number)))<<MIN(HLO(number) , LLO(number))<<endl;

values << HHI(number) << LHI(number) << HLO(number) << LLO(number);

i = (HHI(number) << 16) + LHI(number) + (HLO(number) << 24) + (LLO(number) << 8);

qDebug() <<"合成的新的32位无符号整型数为:"<<pr(i)<<i<<endl;

std::sort(values.begin() , values.end() , std::greater<qint8>()); //按照从大到小排序
qDebug()<<"排序前:"<<values;
qDebug() <<"排序后:"<<values;


return a.exec();

}

