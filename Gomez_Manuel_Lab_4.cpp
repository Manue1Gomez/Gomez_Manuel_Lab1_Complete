#include <iostream>

using namespace std;

struct Song {
    string name;
    int priority; 
};

Song karaoke_queue[100];
int front = 0;
int rear = -1;
int max_queue = 10;


bool isFull() {
    return rear == max_queue - 1;
}


bool isEmpty() {
    return rear == -1;
}


string enqueue(string song, int priority) {
    if (isFull()) {
        return "The queue is full. Try again later.";
    }

    Song newSong = {song, priority};
    int i;

    
    for (i = rear; i >= 0 && karaoke_queue[i].priority < priority; i--) {
        karaoke_queue[i + 1] = karaoke_queue[i];
    }

    karaoke_queue[i + 1] = newSong;
    rear++;

    return "A new song has been added to the queue with priority " + to_string(priority);
}


string dequeue() {
    if (isEmpty()) {
        return "There is no song in the queue. Try adding first.";
    }

    return "Now playing: " + karaoke_queue[front++].name;
}

int main() {
    
    cout << enqueue("Don't Stop Believin", 2) << endl;
    cout << enqueue("Dancing Queen", 5) << endl;
    cout << enqueue("Boom Tarat Tarat", 1) << endl << endl;

    cout << dequeue() << endl;
    cout << dequeue() << endl; 

    return 0;
}