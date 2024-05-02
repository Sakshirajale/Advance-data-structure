#include<iostream>
using namespace std;

//Structure for node
struct node
{
    int re_year;
    string artist,album,genre;
    string title;
    float duration;
    node *next,*prev;
};

//Create Node
node *create_node(string t,string art,string al,int ry,string g,float d)
{
    node *temp;
    temp=new node;
    temp->title=t;
    temp->artist=art;
    temp->album=al;
    temp->re_year=ry;
    temp->genre=g;
    temp->duration=d;
   // temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

//Create list
node *create_list()
{
    node *head,*new_node,*temp;
    int ry,ans;
    string t;
    string art,al,g;
    float d;
    int flag=true;

    //temp=NULL;
    do{
        cout<<"\nEnter Title of Song :: ";
        cin>>t;
        cout<<"Enter Artist of Song ::";
        cin>>art;
        cout<<"Enter Album Name of Song ::";
        cin>>al;
        cout<<"Enter Release Year of Song ::";
        cin>>ry;
        cout<<"Enter Genre of Song ::";
        cin>>g;
        cout<<"Enter Duration of Song ::";
        cin>>d;

        new_node=create_node(t,art,al,ry,g,d);

        if(flag==true)
        {
			head=new_node;
			new_node->next=head;
			temp=head;
			flag=false;
		}
        else
        {
            temp=head;
            while(temp->next!=head){
                    temp=temp->next;

            }
           // ptr=find_last(head);
            temp->next=new_node;
            new_node->next=head;
        }
        cout<<"\nDO YOU WANT TO INSERT ONE MORE DONAR(1/0) ";
        cin>>ans;
    }while(ans==1);
        return head;
    }

void insert_(node *head){

node *new_node,*temp;
  int ry1;
    string t1;
    string art1,al1,g1;
    float d1;
    int flag=true;

    //temp=NULL;
        cout<<"\nEnter Title of Song :: ";
        cin>>t1;
        cout<<"Enter Artist of Song ::";
        cin>>art1;
        cout<<"Enter Album Name of Song ::";
        cin>>al1;
        cout<<"Enter Release Year of Song ::";
        cin>>ry1;
        cout<<"Enter Genre of Song ::";
        cin>>g1;
        cout<<"Enter Duration of Song ::";
        cin>>d1;

        new_node=create_node(t1,art1,al1,ry1,g1,d1);
        if(head==NULL){
            head=new_node;
        }
        else{
        temp=head;
while(temp->next!=head){
    temp=temp->next;
}
    temp->next=new_node;
	new_node->next=head;
	cout<<"New Record Added Successfully ";
}
}

void search_display(node * head){
    node *temp;
    temp=head;
      cout<<"\t|\tTitle\t|\tArtist\t|\tAlbum\t|\tRelease Year\t|\tGenre\t|Duration\t\t|";
       cout<<"\n\t\t--------------------------------------------------------------------------------------------------------------------------\n";
       cout<<"\t|\t"<<temp->title<<"\t|\t"<<temp->artist<<"\t|\t"<<temp->album<<"\t|\t"<<temp->re_year<<"\t\t|\t"<<temp->genre<<"\t|\t"<<temp->duration<<"\t|\t\n";
       cout<<"\n\t\t--------------------------------------------------------------------------------------------------------------------------\n";
       }

node search_(node *head){
    string ts;
 cout<<"Enter Title to search :: ";
 cin>>ts;
  node *temp;
    temp=head;
    if(temp==NULL){
        cout<<" *No such song available* ";
    }

 do{
         if(temp->title==ts){
                cout<<"found ";
       search_display(temp);
 }
        temp=temp->next;
}while(temp!=head);
    return *head;
}
/*
void dele(node * head){
	node *prev1,*prev,*temp;
	string del;
	temp=head;
	cout<<" Enter Title of song to be deleted ::";
	cin>>del;
		if(temp==NULL){
		cout<<"\nNO SUCH SONG IN RECORD ";
		return;
		}
	while(temp->next!=head && temp->title!=del){
		prev1=temp;
		temp=temp->next;
	}
	if(temp->title==del){
	    if(temp==head){
                prev=temp->next;
        while(temp->next!=head){
            temp=temp->next;
        }
        prev->next=temp->next;
        temp->next=prev;
        head=temp->next;
	    }

	    else{
	    prev1->next=temp->next;
	    //(temp->next)->prev=prev1;
	    }
	    	                temp->next=NULL;

	    }
	    delete temp;
	    }
*/
void update(node * head){
    node * temp,*new_node;
    temp=head;
    string t;
      int ryry;
    string tt;
    string arar,alal,gg;
    float dd;
    cout<<"Enter the title of songs whose information is to be updated :: ";
    cin>>t;
    if(temp==NULL){
        cout<<"no songs vailable ";
        return;
    }
    do{
            if(temp->title==t){
        cout<<"\nEnter Title of Song :: ";
        cin>>tt;
        cout<<"Enter Artist of Song ::";
        cin>>arar;
        cout<<"Enter Album Name of Song ::";
        cin>>alal;
        cout<<"Enter Release Year of Song ::";
        cin>>ryry;
        cout<<"Enter Genre of Song ::";
        cin>>gg;
        cout<<"Enter Duration of Song ::";
        cin>>dd;

        new_node=create_node(tt,arar,alal,ryry,gg,dd);
            temp->title=tt;
    temp->artist=arar;
    temp->album=alal;
    temp->re_year=ryry;
    temp->genre=gg;
    temp->duration=dd;
            }
        temp=temp->next;
    }while(temp!=head);
}

//Display List
void display(node *head)
{
    node *temp;
    temp=head;
    if(temp==NULL){
        cout<<"no songs vailable ";
        return;
    }
      cout<<"\t|\tTitle\t|\tArtist\t|\tAlbum\t|\tRelease Year\t|\tGenre\t|Duration\t\t|\n";
       cout<<"\n\t\t--------------------------------------------------------------------------------------------------------------------------\n";
do{
       cout<<"\t|\t"<<temp->title<<"\t|\t"<<temp->artist<<"\t|\t"<<temp->album<<"\t|\t"<<temp->re_year<<"\t\t|\t"<<temp->genre<<"\t|\t"<<temp->duration<<"\t|\t\n";
    temp=temp->next;
}while(temp!=head);
       cout<<"\n\t\t--------------------------------------------------------------------------------------------------------------------------\n";
}

int main()
{
    node *p1=NULL,*p2=NULL,*p3=NULL;
       int ch,c;
   do{
    cout<<"\nMENU\n1.MAKE SONG ENTRY\n2.ADD A SONG \n3.DELETE A SONG \n4.SEARCH A SONG \n5.UPDATE A SONG \n6.DISPLAY \n7.EXIT";
    cout<<"\nEnter your choice ::";
    cin>>ch;
    switch(ch){
    case 1:
    p1=create_list();
    break;

    case 2:
    insert_(p1);
    break;

   /* case 3:
    dele(p1);
    break;*/

    case 4:
    search_(p1);
    break;

    case 5:
    update(p1);
    break;

    case 6:
    display(p1);
    break;

    case 7:
    exit(0);

    default:
    cout<<"wrong choice ";

    }
    cout<<"continue (1/0) ::";
    cin>>c;
    }while(c==1);
    return 0;

}
