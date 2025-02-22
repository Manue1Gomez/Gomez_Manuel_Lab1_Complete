#include <iostream>
using namespace std;


// Declare variables
int myArray[30];
int numElem = 0;
int maxElem = 20;

//searching operation
int binarySearch(int num, int lowest, int highest){
    while(lowest <= highest){
        int middle = lowest + ((highest -1) /2);
        
        if(myArray[middle] == num){
            return middle;
        }
        if(myArray[middle] < num){
            lowest = middle +1;
        }else{
            highest = middle -1;
    }
}
return -1;
}

// Traversing operation
void traverseArray() {
    cout << "Showing elements in my array \n";
    for (int i = 0; i < numElem; i++) {
        cout << myArray[i] << " | ";
    }
    cout << endl;
}


// Insert operations

// Insert at the end
string InsertAtTheEnd(int num) {
    if (numElem != maxElem) {
        myArray[numElem] = num;
        numElem++;
        return "An element is successfully inserted to the end! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

// Insert at the beginning
string InsertAtTheBeginning(int num) {
    if (numElem != maxElem) {
        for (int i = numElem; i >= 0; i--) {
            myArray[i + 1] = myArray[i];
        }
        myArray[0] = num;
        numElem++;
        return "An element is successfully inserted at the beginning! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

// Insert at the given position
string InsertAtTheGivenPosition(int num, int ElementAfter) {
    if (numElem != maxElem) {
        int position = binarySearch(ElementAfter, 0, numElem);
        /*for (int i = 0; i < numElem; i++) {
            if (myArray[i] == ElementAfter) {
                position = i;
                break; 
            }
        }*/


        if (position != -1) {
            for (int i = numElem; i > position; i--) {
                myArray[i + 1] = myArray[i];
            }
            myArray[position + 1] = num;
            numElem++;
            return "An element is successfully inserted at the specified location! \n";
        }
    }
    return "The array is full. Please remove elements before inserting a new one. \n";
}


	
	//Sorting operation
	void bubbleSort(){
	    int i, j;
	    bool swapped;
	    for(int i =0; i < numElem - 1; i++){
	        swapped = false;
	        for(j = 0; j < numElem - i -1; j++){
	            if(myArray[j] > myArray[j+1]){
	            swap(myArray[j], myArray[j+1]);
	            swapped = true;
	        }
	    }
	    
	    if(swapped == false){
	        break;
	    }
	}
}

//Insert at a sorted array
string InsertAtSortedArray(int num){
    if(numElem != maxElem){
        bubbleSort();
        int position;
        for(int i = 0; i < numElem; i++){
            if(num < myArray[i]){
                position = i;
                break;
                }
            }
    
    for(int i = numElem; i>=position; i--){
        myArray[i+1] = myArray[i];
         }
    myArray[position] = num;
    numElem++;
    return "An Element is successfully inserted at a sorted array!  \n";
    }

    return "The Array is Full. please remove elements before inserting new one.  \n";
}
 
//delete from the end
    string DeleteFromTheEnd(){
        if(numElem != 0){
            numElem--;
            return "An element has been deleted from the end!";
        }
        return "The array is underflow! Delete is not possible";
    }
    
    //delete from the beginning
    string DeleteFromBeginning(){
        if(numElem != 0){
            for(int i = 0; i<= numElem; i++){
                myArray[i] = myArray[i+1];
            }
            numElem--;
            return "An element has been deleted from the beginning!";
        }
        return "the array is underflow! Deleted is not possible";
    }

//delete from the given element
    string DeleteFromGivenElement(int element){
        if(numElem != 0){
            int index = binarySearch(element, 0, numElem);
            /*for(int i = 0; i <= numElem; i++){
                if(myArray[i] == element){
                    index = i;
                    break; 
                }
            }*/
        
        for(int i = index; i <= numElem; i++){
            myArray[i] = myArray[i+1];
            
        }
        numElem--;
        return to_string(element) + " has been deleted!";
    }
    return "The array is underflow! Deleted is not possible";
}



// Main function
int main() {
   

    // Corrected function calls
    cout << InsertAtTheBeginning(3);
    cout << InsertAtTheEnd(7);
    cout << InsertAtTheEnd(9);
    cout << InsertAtTheBeginning(20);
    cout << InsertAtTheGivenPosition(37, 7);
    cout << InsertAtTheBeginning(256);
    cout << InsertAtTheGivenPosition(128, 9);
    cout << InsertAtTheBeginning(9);
        traverseArray();
        
    cout << InsertAtSortedArray(3);
    cout << InsertAtSortedArray(30);
    cout << InsertAtSortedArray(38);
    cout << InsertAtSortedArray(19);
        bubbleSort();
        traverseArray();
        
    cout << DeleteFromTheEnd() << endl;
         traverseArray();
    cout << DeleteFromTheEnd() << endl;
         traverseArray();
    cout << DeleteFromBeginning() << endl;
         traverseArray();
    cout << DeleteFromBeginning() << endl;
         traverseArray();
    cout << DeleteFromGivenElement (30 ) <<endl;
         traverseArray();
    cout << DeleteFromGivenElement (37 ) <<endl;
        traverseArray();
        
    cout << binarySearch (38, 0, numElem) <<endl;
    cout << binarySearch (20, 0, numElem) <<endl;
   

	 return 0;
    
}
