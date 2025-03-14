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
            cout << "A new node has been inserted at the end \n" <<endl;
            return head;
        }
        Node *temp = new Node;
        temp = head;
        
        while(temp->link != NULL){
            temp = temp->link;
        }
        Node *newNode = createNode(data);
        temp->link = newNode;
        
        cout << "A new node has been inserted at the end \n" <<endl;
        return head;
    }
    
    Node *insertAtbeginning(string data, Node*head){
        Node *newNode = createNode(data);
        newNode->link = head;
        
        head = newNode;
        cout<< "A new node has been inserted at the beginning \n" <<endl;
        return head;
    }
    
    string insertAfter(string after,string data,Node*head){
         Node *temp = new Node;
         temp = head;
         
         while(temp->songName.compare(after)!= 0){
             if(temp == NULL){
                 return "No such song exist, please try again later.";
         }
         temp = temp->link; 
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "A new code has been added after " + after + "\n" ;
    cout <<endl;
    }
    
    string deleteAtEnd(Node *head){
        if(head == NULL){
            return "The linked list is empty \n";
        }
        
        if(head->link ==NULL){
            delete head;
            return "The head has been deleted \n";
        }
        
        Node *temp = new Node;
        temp = head;
        
        while(temp->link->link != NULL){
            temp = temp->link;
        }
        
        temp->link = NULL;
        
        return "A node has been deleted at the end \n";
    }
    
    Node *deleteFromBeginning(Node *head){
        if(head == NULL){
            cout << "The link list is empty \n" <<endl;
            return NULL;
        }
        
        if(head->link == NULL){
            delete head;
        }
        
        head = head->link;
        
        cout <<"A code has been delete from the beginning \n"<<endl;
        
        return head;
    }
    
    Node *deleteFromGivenNode(string givenNode, Node *head){
        if(head == NULL){
            cout << "The link list is empty. \n"<<endl;
            return NULL;
        }
        
        if(head->songName.compare(givenNode) ==0){
            head = deleteFromBeginning(head);
            cout << "The Node" + givenNode + "has been deleted.\n"<<endl;
            return head;
        }
        
        Node *temp = new Node;
        Node *next = new Node;
        temp = head;
        next = temp->link;
        
        while(next->songName.compare(givenNode) !=0){
            if(temp == NULL){
                cout << "No such node exist. \n"<<endl;
                return head;
            }
            next = next->link;
            temp = temp->link;
        }
        
        temp->link = next->link;
        cout << "The Node " + givenNode + " has been deleted. \n"<<endl ;
        return head;
    }
    
    int main(){
    
    Node *head = createNode("Sanctuary by Joji");
    traverse(head);
    cout <<endl;
    
   
    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    traverse(head);
    cout <<endl;
    
    head = insertAtEnd("Blinding Lights by The Weeknd", head);
    traverse(head);
    cout <<endl;
    
    head = insertAtEnd("Shape Of You by Ed Sheeran", head);
    traverse(head);
    cout <<endl;
    
    head = insertAtEnd("Someone you loved by Lewis Capaldi", head);
    traverse(head);
    cout <<endl;
    
    
    head = insertAtbeginning("Die with a Smile by Lady Gaga and Bruno Mars", head);
    traverse(head);
    cout <<endl;
    
    head = insertAtbeginning("DTMF by Bad Bunny", head);
    traverse(head);
    cout <<endl;
    
    head = insertAtbeginning("Birds Of A Feather by Billie Eillish", head);
    traverse(head);
    cout <<endl;
    
    head = insertAtbeginning("Not like us by kendrick lamar", head);
    traverse(head);
    cout <<endl;
    
    
    cout << insertAfter ("Die with a Smile by Lady Gaga and Bruno Mars","APT by Rose", head)<<endl;
    traverse(head);
    cout <<endl;
    
    cout << insertAfter ("DTMF by Bad Bunny","Blue by Yung Kai", head)<<endl;
    traverse(head);
    cout <<endl;
    
    cout << insertAfter ("Birds Of A Feather by Billie Eillish","We Could Happen by AJ Rafael", head)<<endl;
    traverse(head);
    cout <<endl;
   	
	cout << deleteAtEnd(head);
	traverse(head);
	cout <<endl;
	
	head = deleteFromBeginning(head);
	traverse(head);
	cout <<endl;

	head = deleteFromGivenNode("Sanctuary by Joji", head);
	traverse(head);
	
	return 0;
    }
    
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
