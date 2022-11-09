#include <QCoreApplication>
#include <QDebug>
#include "test.h"

Test* make_tree(){
    Test *root = new Test(nullptr,"Root");
    for(int p=0; p<3;p++){
        Test *pobj = new Test(root,"Parent-" + QString::number(p+1));
        for (int c = 0; c < 3; ++c) {
            Test *cobj = new Test(pobj,"Child-" + QString::number(p+1) +" " + QString::number(c+1));
            for (int s = 0; s < 3; ++s) {
                Test *sobj = new Test(cobj,"Sub-" + QString::number(p+1) +" " + QString::number(c+1)+" "+ QString::number(s+1));
                Q_UNUSED(sobj);
            }
        }
    }
    qInfo()<<"\n\n";

    return root;
}

void print_tree(Test *root, int level=0){
    if (root->children().length()==0) return;

    QString lead="-";
    lead.fill('-',level*10);

    foreach (QObject *obj, root->children()) {
        Test *child = qobject_cast<Test*>(obj);
        if(!child) return;

        qInfo()<<lead<<child;

        print_tree(child,level +1);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test *family_tree=make_tree();
    print_tree(family_tree,1);
    qInfo()<<"\n\n";
    delete family_tree;

    return a.exec();
}
