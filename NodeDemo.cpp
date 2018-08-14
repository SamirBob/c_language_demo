/* 创建结构体，包含数据域和指针域 */
struct node {
    int value;
    node* next;
};
/* 链表尾加入新元素 */
node* addNode(node *head,int addValue)
{
    node* newNode = new node();
    newNode->next = NULL;
    newNode->value = addValue;
    node* p = new node();
    p=head;//list的头结点
    if(head == NULL)
    {
        head=newNode;//新节点为链表头节点
    }else{
        while(p->next != NULL)//找到尾节点
                p=p->next;
        p->next=newNode;//在尾节点后面加入新节点
    }
    return head;
}