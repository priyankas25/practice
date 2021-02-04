#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<class t>
class Node{

    private:
        t data;
        Node *next;

    public:
        Node(){
            next = NULL;
        }

        Node(t data){
            this->data = data;
            next = NULL;
        }

        t getdata(){
            return this->data;
        }

        void setnext(Node * next){
            this->next = next;

        }

        Node* getnext(){
            return this->next;
        }
};

template<class T>
class linklist{
    private:
    Node<T> *head;
    public:
        linklist(){
            this->head = NULL;
        }

        Node<T>* gethead(){
            return this->head;
        }

        void InsertE(T data){
            Node<T> *node = new Node<T>(data);

            if(head ==NULL){
                head = node;
            }
            else{
                Node<T> *temp = head;
                while(temp->getnext()!= NULL){
                        temp = temp->getnext();
                }
                temp->setnext(node);
            }
        }

        void InsertB(T data){
            Node<T> *node = new Node<T>(data);
            if(head ==NULL){
                head = node;
            }
            else{

                node->setnext(head);
                head = node;
            }

        }

        void InsertBetween(T tobe, T after){
            Node<T> *node = new Node<T>(tobe);
            if(head == NULL){
                head = node;
            }
            else{
                Node<T> *temp = head;
                while(temp->getdata()!=after || temp->getnext() != NULL){
                    temp = temp->getnext();
                }
                if(temp->getnext() == NULL){
                    cout<<"data not found!!!";
                    return;
                }
                else{
                    node->setnext(temp->getnext());
                    temp->setnext(node);
                }
            }
        }

        T deleteE(){
            Node<T> *temp = head;
            while(temp->getnext()->getnext() !=NULL){
                temp = temp->getnext();
            }

            int a = temp->getnext()->getdata();
             temp->setnext(NULL);
            //delete [] temp;
            return a;

        }

        T deleteB(){
            Node<T> *temp = head;
            head = head->getnext();
            int a = temp->getdata();
            delete [] temp;
            return a;

        }

        T deleteBetweeen(T after){
            Node<T> *temp = head;
            if(temp->getdata()==after){
                int a = temp->getdata();
                if(temp->getnext()!=NULL){

                    head = head->getnext();
                }

                 delete [] temp;
                 return a;
            }
            else{

            while(temp->getnext()!=NULL || temp->getnext()->getdata() !=after){
                temp = temp->getnext();
            }

            if(temp->getnext()== NULL ){
                cout<<"data not found!!"<<endl;
                return 0;
                }
            else{
                int a = temp->getnext()->getdata();
                if(temp->getnext()->getnext()!=NULL){
                    temp->setnext(temp->getnext()->getnext());
                }
                else{
                    temp->setnext(NULL);
                }
                return a;
            }
            }

        }

        void printdata(){
            Node<T> *temp=head;
            while(temp!=NULL){
                cout<<temp->getdata()<<" ";
                temp = temp->getnext();
            }
            cout<<endl;
        }




        void removeduplicates(){
            Node<T>*temp = head;
            Node<T>*prev = head;
            unordered_set<int>s;
            do{

                if(s.find(temp->getdata())!=s.end()){
                    prev->setnext(temp->getnext());
                    temp = temp->getnext();
                }
                else{
                    s.insert(temp->getdata());
                    prev = temp;
                    temp = temp->getnext();
                }
            }while(temp!=NULL);
        }

};



        void printreverse(Node<int>*temp){
                if(temp==NULL)
                    return;
                printreverse(temp->getnext());
                cout<<temp->getdata()<<" ";
            }

      linklist<int> sumlist(linklist<int>li1, linklist<int>li2){
            linklist<int>li3;
            int sum=0,flag=0;
            Node<int> *temp1 = li1.gethead();
            Node<int> *temp2 = li2.gethead();
            while(temp1 != NULL && temp2 != NULL){
                sum = temp1->getdata()+ temp2->getdata();
                if(flag>0){
                    sum+=flag;
                    flag=0;
                }

                if(sum>=10){
                    flag=sum/10;
                    sum=sum%10;
                }
                li3.InsertE(sum);
                temp1 = temp1->getnext();
                temp2 = temp2->getnext();
            }
            return li3;
      }


int main(){

    linklist<int>li1;

    li1.InsertB(3);
    li1.InsertB(4);
    li1.InsertB(2);

    linklist<int>li2;
    li2.InsertB(4);
    li2.InsertB(6);
    li2.InsertB(5);

    linklist<int>li3;
    li3 = sumlist(li1,li2);

    cout<<"first question sum of 2 linklist"<<endl;
    li1.printdata();
    li2.printdata();
    li3.printdata();

    linklist<int>li4;
    li4.InsertB(1);
    li4.InsertB(1);
    li4.InsertB(2);
    li4.InsertB(3);
    li4.InsertB(3);

    cout<<"second question remove doubles"<<endl;
    li4.printdata();
    li4.removeduplicates();
    li4.printdata();
    return 0;
}

