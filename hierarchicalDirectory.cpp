#include <bits/stdc++.h>
using namespace std; 

class Tree_element
{
public:
    char name[20];
    int x, y, ftype, lx, rx, nc, level;
    Tree_element *link[5];
};
typedef Tree_element node;

create(node **root, int lev, char *dname, int lx, int rx, int x)
{
    int i, gap;
    if (*root == NULL)
    {
        (*root) = (node *)malloc(sizeof(node));
        cout << "Enter name of dir/file(under " << dname << ") : ";
        cin >> (*root)->name;
        cout << "enter 1 for Dir/2 for file :";
        cin >> (*root)->ftype;
        (*root)->level = lev;
        (*root)->y = 50 + lev * 50;
        (*root)->x = x;
        (*root)->lx = lx;
        (*root)->rx = rx;
        for (i = 0; i < 5; i++)
        {
            (*root)->link[i] = NULL;
        }
        if ((*root)->ftype == 1)
        {
            cout<<"No of sub directories/files(for "<<(*root)->name)<<"):";
            cin >> (*root)->nc;
            if ((*root)->nc == 0)
            {
                gap = rx - lx;
            }
            else
            {
                gap = (rx - lx) / (*root)->nc;
            }
            for (i = 0; i < (*root)->nc; i++)
            {
                create(&((*root) > link[i]), lev + 1, (*root) > name, lx + gap * i, lx + gap * i + gap, lx + gap * i + gap / 2);
            }
        }
        else
        {
            (*root)->nc = 0;
        }
    }
}
