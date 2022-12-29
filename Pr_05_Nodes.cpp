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

void create_Queueu(struct Queue *q,int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node *[q->size];
}

void enqueue(struct Queue *q,struct Node *x)
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

struct Node * dequeue(struct Queue *q)
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

int isEmpty_Queue(struct Queue q)
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
    create_Queueu(&q,100);
    cout<<"Enter the value of Root Node\n";
    cin>>x;
    root = new Node;
    root->data = x;
    root->leftchild = root->rightchild = NULL;
    enqueue(&q,root);
    while (!isEmpty_Queue(q))
    {
        p = dequeue(&q);
        cout<<"Enter the value of leftchild of "<<p->data<<"\n";
        cin>>x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->leftchild = t;
            enqueue(&q,t);
        }

        cout<<"Enter the value of rightchild of "<<p->data<<"\n";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->rightchild = t;
            enqueue(&q,t);
        }
        
    }
    
    
}

void recursive_preorder(struct Node *p)
{
    if (p == NULL)
    {
        return;
    }

    cout<<p->data<<" -> ";
    recursive_preorder(p->leftchild);
    recursive_preorder(p->rightchild);
    
}

void recursive_inorder(struct Node *p)
{
    if(p == NULL)
    {
        return;
    }

    recursive_inorder(p->leftchild);
    cout<<p->data<<" -> ";
    recursive_inorder(p->rightchild);
}

void recursive_postorder(struct Node *p)
{
    if(p == NULL)
    {
        return;
    }

    recursive_postorder(p->leftchild);
    recursive_postorder(p->rightchild);
    cout<<p->data<<" -> ";
}

void Level_order(struct Node *p)
{
    Queue q;
    create_Queueu(&q,100);
    cout<<p->data<<" -> ";
    enqueue(&q,p);

    while (!isEmpty_Queue(q))
    {
        p = dequeue(&q);

        if (p->leftchild)
        {
            cout<<p->leftchild->data<<" -> ";
            enqueue(&q,p->leftchild);
        }

        if (p->rightchild)
        {
            cout<<p->rightchild->data<<" -> ";
            enqueue(&q,p->rightchild);
        }
        
        
    }
    
}

int count(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }

    return count(p->leftchild)+count(p->rightchild)+1;
}

int sum(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }

    return sum(p->leftchild)+sum(p->rightchild)+p->data;
    
}

int leaf_nodes(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }

    if (p->leftchild == NULL && p->rightchild == NULL)
    {
        return leaf_nodes(p->leftchild)+leaf_nodes(p->rightchild)+1;
        
    }

    return leaf_nodes(p->leftchild)+leaf_nodes(p->rightchild);
    
}

int degree_two(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }

    if (p->leftchild != NULL && p->rightchild != NULL)
    {
        return degree_two(p->leftchild)+degree_two(p->rightchild)+1;
    }
    
    return degree_two(p->leftchild)+degree_two(p->rightchild);
}

int degree_one_two(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }

    if (p->leftchild != NULL || p->rightchild != NULL)
    {
        return degree_one_two(p->leftchild)+degree_one_two(p->rightchild)+1;
    }
    
    return degree_one_two(p->leftchild)+degree_one_two(p->rightchild);
    
}

int degree_one(struct Node  *p)
{
    if (p == NULL)
    {
        return 0;
    }

    if (p->leftchild != NULL ^ p->rightchild != NULL)
    {
        return degree_one(p->leftchild)+degree_one(p->rightchild)+1;
    }
    
    return degree_one(p->leftchild)+degree_one(p->rightchild);
    
}

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void create_stack(struct Stack *st,int size)
{
    st->size = size;
    st->top = -1;
    st->S = new Node *[st->size];
}

void push(struct Stack *st,struct Node *x)
{
    if(st->top == (st->size) - 1)
    {
        cout<<"Stack is full\n";
    }

    else
    {
        st->top++;
        st->S[st->top] = x;
    }

}

struct Node * pop(struct Stack *st)
{
    struct Node *x;
    if(st->top == -1)
    {
        cout<<"Stack is Empty\n";
    }

    else
    {
        x = st->S[st->top];
        st->top--; 
    }

    return x;
}

int isEmpty_stack(struct Stack st)
{
    if (st.top == -1)
    {
        return true;
    }

    else
    {
        return false;
    }
    
}

void Iterative_preorder(struct Node *t)
{
    struct Stack st;
    create_stack(&st,100);

    while(t != NULL || !isEmpty_stack(st))
    {
        if (t != NULL)
        {
            push(&st,t);
            cout<<t->data<<" -> ";
            t = t->leftchild;
        }

        else
        {
            t = pop(&st);
            t = t->rightchild;
        }
        
    }
}

void Iterative_inorder(struct Node *t)
{
    struct Stack st;
    create_stack(&st,100);

    while (t != NULL || !isEmpty_stack(st))
    {
        if(t != NULL)
        {
            push(&st,t);
            t = t->leftchild;
        }

        else
        {
            t = pop(&st);
            cout<<t->data<<" -> ";
            t = t->rightchild;
        }
    }
    
}

// void Iterative_postorder(struct Node *t)
// {
//     struct Stack st;
//     create_stack(&st,100);
//     long int temp;

//     while (t != NULL || !isEmpty_stack(st))
//     {
//         if(t != NULL)
//         {
//             push(&st,t);
//             t = t->lchild;
//         }

//         else
//         {
//             temp = (int )pop(&st);

//             if(temp > 0)
//             {
//                 push(&st,(Node *)(-temp));
//                 t = ((Node *)(temp)) -> rchild;
//             }

//             else
//             {
//                 cout<<((Node *)(temp)) -> data<<" -> ";
//                 t = NULL;
//             }
//         }
//     }
    
// }



int main()
{
    Treecreate();

    cout<<"\nIterative Preorder\n";
    Iterative_preorder(root);
    cout<<"\nIterative Inorder\n";
    Iterative_inorder(root);
    
    cout<<"\nRecursive Preorder\n";
    recursive_preorder(root);
    cout<<"\nRecursive Inorder\n";
    recursive_inorder(root);
    cout<<"\nRecursive Postorder\n";
    recursive_postorder(root);
    cout<<"\nLevel Order Treaversals\n";
    Level_order(root);
    cout<<"\nTotal Number of Nodes\n"<<count(root);
    cout<<"\nSum of Nodes\n"<<sum(root); 
    cout<<"\nLeaf Nodes\n"<<leaf_nodes(root);
    cout<<"\nDegree Two Nodes\n"<<degree_two(root);
    cout<<"\nDegree Two and one node\n"<<degree_one_two(root);
    cout<<"\nDegree one nodes\n"<<degree_one(root);
    return 0;
}