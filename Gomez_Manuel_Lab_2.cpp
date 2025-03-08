#include <iostream>
using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;



Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    
    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    
    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        temp = temp->link;
    }
}


    Node *insertAtEnd(string data, Node *head){
        if(head == NULL){
            Node *newNode = createNode(data);
            head = newNode;
            cout << " A new node has been inserted at the end \n" <<endl;
            return head;
        }
        Node *temp = new Node;
        temp = head;
        
        while(temp->link != NULL){
            temp = temp->link;
        }
        Node *newNode = createNode(data);
        temp->link = newNode;
        
        cout << "A new node has been iniserted at the end \n" <<endl;
        return head;
    }
    
    Node *insertAtbeginning(string data, Node*head){
        Node *newNode = createNode(data);
        newNode->link = head;
        
        head = newNode;
        cout<< " A new node has been inserted at the beginning \n" <<endl;
        
        return head;
    }
    
    string insertAfter(string after,string data,Node*head){
         Node *temp = new Node;
         
         while(temp->songName.compare(after)!= 0){
             if(temp == NULL){
                 return "No such song exist, please try again later.";
         }
         temp = temp->link; 
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "A new code has been added" + after + "\n";
    }
    
    int main(){
    
    Node *sample = new Node;
    sample->songName = "Heaven Knows by Orange and Lemon";
    
    Node *head = createNode("sanctuary by Joji");
    
    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    
    head = insertAtEnd("Blinding Lights by The Weeknd", head);
    head = insertAtEnd("Shape Of You by Ed Sheeran", head);
    head = insertAtEnd("Someone you loved by Lewis Capaldi", head);
    
    head = insertAtbeginning("Die with a Smile by Lady Gaga and Bruno Mars", head);
    head = insertAtbeginning("DtMF by Bad Bunny", head);
    head = insertAtbeginning("Birds Of A Feather by Billie Eillish", head);
    head = insertAtbeginning("Not like us by kendrick lamar", head);
    
    head = insertAfter  "Die with a Smile by Lady Gaga and Bruno Mars",("APT by Rose");
    
    
    cout << sample->songName <<endl;
    traverse(head);
    return 0;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
