/* 创建结构体 */
struct node{
    int date;//存放数据
    struct node *next;//存放下一个节点的地址
};
/* 创建一个链表 */
struct node * Creat()
{
    struct node *phead,*pnew,*pend;
    pnew=pend=(struct node*)malloc(sizeof(struct node));
    int n=0;
    phead=NULL;//phead是头指针，先让其指向NULL
    scanf("%d",&pnew->date);
    pnew->next=NULL;
    while(pnew->date!=0)//只要输入的数据域不为0，循环条件
    {
        n++;
        if(n==1)//判定是否为首节点
        {
            pnew->next=NULL;
            pend=pnew;
            phead=pnew;
        }else{
            pnew->next=NULL;
            pend->next=pnew;
            pend=pnew;
        }
        pnew=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&pnew->date);
    }
    return phead;//返回头指针
}
/* 链表的输出 */
void Print(struct node * phead)
{
    struct node *t;
    t=phead;
    while(t != NULL)
    {
        printf("%d",t->date);
        t=t->next;
    }
}
/* 链表的插入,头插法 */
struct node * Insert(struct node* phead)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&p->date);
    p->next=phead;
    phead=p;
    return phead;
}
/* 链表的删除 */
struct node* Delete(struct node* phead,int n)
{
    struct node *p,*t;
    p=phead;
    if(phead->date == n)
    {
        phead=phead->next;
    }else{
        while(p->date != n && p->next != NULL)
        {
            t=p;
            p=p->next;
        }
        if(p->date == n)
        {
            t->next=p->next;
        }
    }
    return phead;
}
/* 链表的排序 */
struct node * Sort(struct node* phead)
{
    struct node *p,*q;
    int temp;
    for(p = phead;p->next != NULL;p=p->next)
    {
        for(q=p->next;q != NULL;q=q->next)
        {
            if(p->date < q->date)
            {
                temp=p->date;
                p->date=q->date;
                q->date=temp;
            }
        }
    }
    return phead;
}