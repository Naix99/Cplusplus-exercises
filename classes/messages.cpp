#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// This code creates a system where messages are sent. Then they are scrambled, but you must print then in the original order.
// The idea is adding and id to each message and then print them according to the id order. I will comment the main steps that help
// to achieve this.

class Message {
private:
    string text;
    int current_id;
public:
    Message(string t, int nid){ current_id = nid; text=t; } //This creates a message with a id and a text.
    const string& get_text() {
        return text;
    }
    // overloaded < operator; this helps compare messages by comparing their id
    bool operator < (const Message& M2) {
        if(current_id < M2.current_id)
            return true;
        else
            return false;
    }
};

class MessageFactory { // This class creates the messages, assingning different (ordered) ids to different messages
public:
    int acid; 
    MessageFactory() {
        acid = 1;
    }
    Message create_message(const string& text) {
        Message m = Message(text, acid);
        acid +=1;
        return m;
    }
};

class Recipient { //This is the class that prints the messages
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end()); //This bit usses the "<" operator for messages to order them. Perfect for sending the messages in 
        //correct order.
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());     //This part suffle the messages :()     
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
