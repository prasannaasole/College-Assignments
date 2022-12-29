#include <iostream>
using namespace std;

struct Node
{
    struct Node *leftchild;
    int data;
    struct Node *rightchild;
}*root = NULL;

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q,int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node *[q->size];
}

void enqueu(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size == q->front)
    {
        cout<<"Queue is full\n";
    }

    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
    
}

struct Node * dequeu(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
    {
        cout<<"Queue is empty\n";
    }

    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }

    return x;
    
}

int isEmpty(struct Queue q)
{
    if(q.front == q.rear)
    {return 1;}

    else
    {
        return 0;
    }
    
}

void Treecreate()
{
    struct Node *p,*t;
    int x;
    Queue q;
    create(&q,100);
    cout<<"Enter the value of Root Node\n";
    cin>>x;
    root = new Node;
    root->data = x;
    root->leftchild = root->rightchild = NULL;
    enqueu(&q,root);
    while (!isEmpty(q))
    {
        p = dequeu(&q);
        cout<<"Enter the value of leftchild of "<<p->data<<"\n";
        cin>>x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->leftchild = t;
            enqueu(&q,t);
        }

        cout<<"Enter the value of rightchild of "<<p->data<<"\n";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->rightchild = t;
            enqueu(&q,t);
        }
        
    }
    
    
}

int count(struct Node *p)
{
    int x,y;

    if (p != NULL)
    {
        x = count(p->leftchild);
        y = count(p->rightchild);

        return x+y+1;
    }
    

    return 0;
    
}

int sum(struct Node *p)
{
    int x,y;

    if (p != NULL)
    {
        x = sum(p->leftchild);
        y = sum(p->rightchild);

        return x+y+p->data;
    }
    

    return 0;
    
}

int height(struct Node *p)
{
    int x=0,y=0;

    if (p == NULL)
    {
        return 0;
    }

    x=height(p->leftchild);
    y=height(p->rightchild);

    if (x > y)
    {
        return x+1;
    }

    else
    {
        return y+1;
    }
    
    
}

void Level_order(struct Node *p)
{
    Queue q;
    create(&q,100);
    cout<<p->data<<" -> ";
    enqueu(&q,p);

    while (!isEmpty(q))
    {
        p = dequeu(&q);

        if (p->leftchild)
        {
            cout<<p->leftchild->data<<" -> ";
            enqueu(&q,p->leftchild);
        }

        if (p->rightchild)
        {
            cout<<p->rightchild->data<<" -> ";
            enqueu(&q,p->rightchild);
        }
        
        
    }
    
}


int main()
{
    Treecreate();
    Level_order(root);
    cout<<"\nCount of nodes is :"<<count(root);
    cout<<"\nSum of nodes is :"<<sum(root);
    cout<<"\nHeight of tree is :"<<height(root);
    return 0;
}