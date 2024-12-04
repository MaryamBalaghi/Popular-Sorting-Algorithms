#include <iostream>
#include <string.h>
using namespace std;
class node
{
    friend class linkedlist;
    private:
    char name[30];
    int mark;
    node *next;
};
class linkedlist
{
    node *first;
    node *last;
    public:
    linkedlist();           // crete an empty list.
    ~linkedlist();          // destrode all of the list.
    void display();         // display all nodes, sum of the marks, count nodes.
    void enter();           // add new node to end of list.
    void delnode();         // find node and delete it.
    void enter_by_order();     //add new node to a sorted list.
    void bubble_sort();
    void selection_sort();
    void insertion_sort();
};
linkedlist::linkedlist()
{
    first=last=NULL;
}
linkedlist::~linkedlist()
{
    node *curptr=first , *temp;
    while(curptr)
    {
        temp=curptr;
        curptr=curptr->next;
        delete temp;
    }
}
void linkedlist::enter()                 
{
   node *newptr;
    newptr =new node;
    cout<<"Enter a character for name( ex: a,b,c,d,...,z): ";
    cin>>newptr->name;
    cout<<"Enter mark "<<endl;;
    cin>>newptr->mark;
    newptr->next=NULL;
    if (first==NULL)
    {
        first=newptr;
    }
    else
    {
        last->next=newptr;
    }
    last=newptr;
}
void linkedlist::display()
{
    float sum_of_marks=0.0;
    int counter_of_nodes=0;
    node *curptr=first;
    while(curptr)
    {
        sum_of_marks+=curptr->mark;
        counter_of_nodes++;
        cout<<curptr->name<<"***"<<curptr->mark<<"\n";
        curptr=curptr->next;
    }
}
void linkedlist::delnode()
{
    node *ptr, *preptr;
    char name[20];
    cin>>name;
    preptr=NULL;
    ptr=first;
    if(ptr==NULL)
    {
        cout<<"The list is empty.";
    }
    else
    {
        while(ptr!=NULL)
        {
            if(strcmp(name,ptr->name)!=0)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            else
            {
                if(first==ptr)
                {
                    first=ptr->next;
                }
                else
                {
                    preptr->next=ptr->next;
                    break;
                }
            }
        }
        if(last==ptr)
        {
            last=preptr;
        }
        delete ptr;
    }
}
void linkedlist::enter_by_order()
{
    node *preptr , *postptr ,*newptr ;
    newptr=new node;
    cin>>newptr->name;
    cin>>newptr->mark;
    preptr=NULL;
    postptr=first;
    while(postptr!=NULL)
    {
        if(strcmp(postptr->name,newptr->name)<0)
        {
            preptr=postptr;
            postptr=postptr->next;
        }
        else
        break;
    }
    newptr->next=postptr;
    if(first==postptr)
    {
        first=newptr;
    }
    else
    preptr->next=newptr;
    if(postptr==NULL)
    {
        last=newptr;
    }
}
void linkedlist::bubble_sort()
{
    if(!first )
    {
        cout<<"This list is empty.";
        return;
    }
    else if( !first->next)
    {
         cout<<"This list is already sorted.";
        return;
    }
    else
    {
        node *ptr, *preptr, *curlast, *ptrnext;
        curlast=nullptr;
        while(curlast!=first)
        {
            preptr=nullptr;
            ptr=first;
            while(ptr->next!=curlast)
            {
                if(ptr->mark > ptr->next->mark)
                {
                    ptrnext=ptr->next;
                    ptr->next=ptrnext->next;
                    ptrnext->next=ptr;
                    if(preptr)
                    {
                        preptr->next=ptrnext;
                    }
                    else
                    {
                        first=ptrnext;
                    }
                    
                    if(ptr->next==nullptr)
                    {
                        last=ptr;
                    }
                    preptr=ptrnext;       // Update pointers after swapping
                }
                else
                {
                    preptr=ptr;
                    ptr=ptr->next;
                }
            }
            curlast=ptr;        // Update curlast to the last sorted node
        }

    }
}
void linkedlist::selection_sort()
{
    if(!first )
    {
        cout<<"This list is empty.";
        return;
    }
    else if( !first->next)
    {
         cout<<"This list is already sorted.";
        return;
    }
    else
    {   
    node* sorted=nullptr;   // for saving the last sorted element;
    node* curptr=first;     // for saving the first unsorted element;
    while (curptr)
    {
        node* premin=nullptr;   // for saving the prepointer to min element
        node* minptr=curptr;    // for initialization of min element.
        node* temp=curptr->next;      // for finding the min element in unsorted section.
        node* pretemp=curptr;       //for saving the prepointer to temp element.
        while (temp)                   // this loop for find the min element in unsorted section.
        {
            if(temp->mark < minptr->mark)
            {
                minptr=temp;
                premin=pretemp;
            }
            pretemp=temp;
            temp=temp->next;
        }
        if(minptr->mark!=curptr->mark)
        {
            //for update the previous pointer.
            if(sorted) sorted->next=minptr;
            else first=minptr;
            if(premin)premin->next=curptr;
            else first=curptr;

            // swap the next pointer
            node* tempnext=minptr->next;
            minptr->next=curptr->next;
            curptr->next=tempnext;

            // update last .
            if(last==minptr)last=curptr;
            if(last==curptr)last=minptr;

            // update curlast to minimum element.
            curptr=minptr;
        }
        sorted=curptr;
        curptr=curptr->next;
        
    }
    }
}
void linkedlist::insertion_sort()
{
    if(first==NULL)
    {
        cout<<"This list is empty! ";
        return;
    }
    else if(first->next==NULL)
    {
        cout<<"This list is already sorted! ";
        return;
    }
    else
    {
        node *currptr=first;
        node*sorted =NULL;
        while (currptr)
        {
            node* next=currptr->next;
            
            if(sorted==NULL || sorted->mark >= currptr->mark)  // insert curptr to the first position.
            {
                currptr->next=sorted;
                sorted=currptr;              //update sorted pointer.
            }
            else
           {
                node*temp=sorted;
                 while (temp->next!=NULL && temp->next->mark < currptr->mark)
            {
                temp=temp->next;
            }
            currptr->next=temp->next;
            temp->next=currptr; 
            
        }
        currptr=next;
        }

        first=sorted;
        node* temp = sorted;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        last = temp;
    }

}
int main()
{
    linkedlist a;
    int n,m;
    bool Continue=true;
    cout<<"Enter number of element in your list: ";
    cin>>m;
    while(m!=0)
    {
        a.enter();
        m--;
    }
    cout<<"+++++++++++++Guide+++++++++++++"<<endl;
    cout<<"1 is Bubble Sort: "<<endl<<"2 is Selection Sort: "<<endl<<"3 is Insertion sort: "<<endl;
    cout<<"Your choise? ";
    cin>>n;
    while(Continue)
    {
    switch (n)
    {
    case 1:
        Continue=false;
        a.bubble_sort();
        cout<<"Result: "<<endl;
        a.display();
        break;
    case 2:
        Continue=false;
        a.selection_sort();
        cout<<"Result: "<<endl;
        a.display();
        break;
    case 3:
        Continue=false;
        a.insertion_sort();
        cout<<"Result: "<<endl;
        a.display();
        break;
    default:
        cout<<"Your choise was wrong, try again: ";
        cin>>n;
        Continue=true;
        break;
    } 
    }
}