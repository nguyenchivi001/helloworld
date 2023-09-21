
#include <iostream>
using namespace std;

struct node
{
    int info;
    node* left;
    node* right;
};
typedef node* Tree;

node* Getnode(int x)
{
    node *p=new node;
    if(p)
    {
        p->info=x;
        p->left=NULL;
        p->right=NULL;
    }
    return p;
}

void insertTree(Tree &T,int x)
{
    if(T)
    {
        if(x==T->info) return;
        else if(x<T->info) insertTree(T->left,x);
        else insertTree(T->right,x);
    }
    else T=Getnode(x);
}

void inputTree(Tree &T)
{
    int n,x;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        insertTree(T,x);
    }
}

void LNR(Tree T)
{
    if(T)
    {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}
void NLR(Tree T)
{
    if(T)
    {
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}
void LRN(Tree T)
{
    if(T)
    {
        LRN(T->left);
        LRN(T->right);
        cout << T->info << " ";
    }
}
int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	return 0;
}

