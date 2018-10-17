#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include<QList>
namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};

}


// 定义学生数据类结构体
typedef struct{

     QStringList stu;
} studData;


//运算符重载函数，使其可直接输出studData结构
QDebug operator<< (QDebug d, const studData &data) {
    for(int i=0;i<data.stu.size();i++)

    {

        d<<data.stu.at(i);

    }

    qDebug()<<"";

    return d;

}



// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};


bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    default: result=(d1.stu.at(currentColumn+1)>=d2.stu.at(currentColumn+1));break;
    }
    return result;

}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    void readFile();
    void doSort();
    void display();
private:
    QString tempfile;
    QList<studData>   student;
    QStringList    title;

};

ScoreSorter::ScoreSorter(QString dataFile)
{
    tempfile=dataFile;
}

void ScoreSorter::doSort()

{

    for(int i=1;i<title.count();i++)

        {

            myCmp tempcmp(i-1);    //数字从左移0位开始

            std::sort(student.begin(),student.end(),tempcmp);

            qDebug()<<"排序后输出，当前排序第 "<<i <<" 列：";

            qDebug()<<title;

            display();

            qDebug()<<"------------------------------------------------\n";

    }

}



void ScoreSorter::readFile()
{
    QFile mfile(tempfile);
    if(!mfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug()<<"无法打开该文件!";

       }
    studData tempstu;
    QString titl=mfile.readLine();
        title= titl.split(" ", QString::SkipEmptyParts);
    while(!mfile.atEnd()) {
        QString str(mfile.readLine());
        tempstu.stu=str.split(" ", QString::SkipEmptyParts);
        if((tempstu.stu).last() == "\n") tempstu.stu.removeLast();
        if(tempstu.stu.size()==0) continue;
        student.append(tempstu);
    }
    mfile.close();
}
void ScoreSorter::display()

{

    for(int i=0;i<student.size();i++)

    {

        qDebug()<<student.at(i);

    }

}
int main()
{
    QString datafile = "C:/Users/acer/Desktop/homework02/data.txt";
    QFile f("sorted_"+datafile);    // 如果排序后文件已存在，则删除之
    if (f.exists()){

        f.remove();

    }



    ScoreSorter s(datafile);

    s.readFile();

    s.doSort();

    return 0;

}
