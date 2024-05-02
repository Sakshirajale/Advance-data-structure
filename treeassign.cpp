#include<iostream>
#include<string>
using namespace std;

struct Node{
   string name,relation;
   Node * right;
   Node * left;
};


Node * getnode(){
    Node *temp;
    temp=new Node;
    cout<<"Enter Name of Family Member ::";
    cin>>temp->name;
    cout<<"Enter Relation ::";
    cin>>temp->relation;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

Node * create(){
Node *temp,*ptr,*root=NULL;
char dir;
int ch;
do{
    temp=getnode();
    if(root==NULL){
        root=temp;
    }
    else{
        ptr=root;
        while(ptr!=NULL){
            cout<<"Enter direction (l/r)::";
            cin>>dir;
            if(dir=='l'){
                if(ptr->left==NULL){
                    ptr->left=temp;
                    break;
                }
                else
                    ptr=ptr->left;
            }
            else{
                if(ptr->right==NULL){
                    ptr->right=temp;
                    break;
                }
                else
                    ptr=ptr->right;
            }
        }
    }
    cout<<"\nDo you want to add more data(1/0)::";
    cin>>ch;
}while(ch==1);
    return root;
}
void dis_postorder(Node * h){
    if(h!=NULL){
        dis_postorder(h->left);
        dis_postorder(h->right);
        cout<<"\t"<<h->name<<" :: "<<h->relation<<"\n";
    }
}

void dis_preorder(Node * h){
       if(h!=NULL){
cout<<"\t"<<h->name<<" :: "<<h->relation<<"\n";
        dis_preorder(h->left);
        dis_preorder(h->right);
    }
}

void dis_inorder(Node * h){
       if(h!=NULL){

        dis_inorder(h->left);
  cout<<"\t"<<h->name<<" :: "<<h->relation<<"\n";
        dis_inorder(h->right);
    }
}

int main(){
Node *n;
int ch,c;
do{
         cout<<"\nMENU\n1.CREATE\n2.DISPLAY ";
	cout<<"\nEnter Your Choice ::";
	cin>>ch;
	switch(ch){
	case 1:
	n=create();
	break;
	
	case 2:
	cout<<"Post order display ::\n";
	dis_postorder(n);
	cout<<"\nPre order display ::\n";
	dis_preorder(n);
	cout<<"\nIN order display::\n";
	dis_inorder(n);
	break;

default:
cout<<"Wrong Choice";
 }

cout<<"\nContinue ::";
cin>>c;
}while(c==1);
return 0;
}
