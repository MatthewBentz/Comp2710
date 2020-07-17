//============================================================================
// Name        : project4_Bentz_mlb0119.cpp
// Author      : Matthew Bentz mlb0119
// Description : Trivia Game with nodes as data structures
// Compile	   : Compiled with MinGW GCC C++ Compiler
// Resources   : https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/#:~:text=The%20first%20part%20is%20to,required%20for%20a%20linked%20list.
//               (Creating a singly linked list)
//			   : https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
// 				 (Counting the number of items in a node)
//			   : https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
// 				 (Adding node to the end of the list)
//			   : https://stackoverflow.com/questions/10553597/cin-and-getline-skipping-input
//				 (For checking how to skip '\n' input in cin)
//			   : Project 4 hints pdf
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// ----- GLOBAL VARIABLES ----- //

int num_of_questions = 0;

// ----- NODE STRUCTURE + POINTER ----- //

struct TriviaNode {
	string question;
	string answer;
	int points;
	TriviaNode *next;
};
typedef TriviaNode* pointer_node;

// ----- FUNCTION DECLARATION ----- //

void init_question_list(pointer_node& ques_list);
void add_question(pointer_node& ques_list);
int ask_question(pointer_node ques_list, int num_ask);
void Unit_Test();

// ----- DEBUG/RELEASE VERSION ----- //

//#define UNIT_TESTING
#define TRIVIA_QUIZ

int main() {

	// ----- RELEASE ----- //

#ifdef TRIVIA_QUIZ
	pointer_node node_list = new TriviaNode;
	init_question_list(node_list);

	// Add questions from user input
	cout << "*** Welcome to Matthew's trivia quiz game ***\n";
	string input;
	do {
		add_question(node_list);
		cout << "Continue? (Yes/No): ";
		getline(cin, input);
	} while (input.compare("Yes") == 0 || input.compare("yes") == 0);
	cout << endl;

	// Begin trivia quiz game
	ask_question(node_list, num_of_questions);
	cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***";
	return 0;
}
#endif

	// ----- DEBUG ----- //

#ifdef UNIT_TESTING
	Unit_Test();
	return 0;
}
#endif

// ----- FUNCTION DEFINITIONS ----- //

void init_question_list(pointer_node& ques_list) {
	pointer_node current_pointer = new TriviaNode;

	// Question 1
	current_pointer->question = "How long was the shortest war on record? (Hint: how many minutes)";
	current_pointer->answer = "38";
	current_pointer->points = 100;
	current_pointer->next = new TriviaNode;

	// Initialize ques_list to be first question
	ques_list = current_pointer;
	current_pointer = ques_list->next;

	// Question 2
	current_pointer->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	current_pointer->answer = "Bank of Italy";
	current_pointer->points = 50;
	current_pointer->next = new TriviaNode;
	current_pointer = current_pointer->next;

	// Question 3
	current_pointer->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
	current_pointer->answer = "Wii Sports";
	current_pointer->points = 20;
	current_pointer->next = NULL;

	num_of_questions += 3;
}

void add_question(pointer_node& ques_list) {
	// Initialize new pointer
	pointer_node new_pointer = new TriviaNode;

	// Get input
	cout << "Enter a question: ";
	getline(cin, new_pointer->question);
	cout << "Enter an answer: ";
	getline(cin, new_pointer->answer);
	cout << "Enter award points: ";
	cin >> new_pointer->points;
	cin.ignore(); // ignores '\n' character that gives tons of problems with input
	new_pointer->next = NULL; // this is needed to add at the end of the list

	// Add to the end of the list
	TriviaNode* last = ques_list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_pointer;

	// Add to the beginning of the list
	//new_pointer->next = ques_list;
	//ques_list = new_pointer;

	num_of_questions++;
}

int ask_question(pointer_node ques_list, int num_ask) {
	pointer_node current_pointer = ques_list;
	string user_answer;
	int total_points = 0;

	// Validate ques_list
	if (ques_list == NULL) {
		return 0;
	}

	// Validate num_ask
	if (num_ask <= 0) {
		cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
		return 1;
	} else if (num_of_questions < num_ask) {
		cout << "Warning - there is only " << num_of_questions << " trivia in the list." << endl;
		return 1;

	// Ask the amount of questions
	// Adds the question points to total_points if correct
	} else {
		for (int i = 0; i < num_ask; i++) {
			cout << "Question: " << current_pointer->question << endl;
			cout << "Answer: ";
			getline(cin, user_answer);
			if (user_answer.compare(current_pointer->answer) == 0) {
				cout << "Your answer is correct. You receive " << current_pointer->points << " points." << endl;
				total_points += current_pointer->points;
			} else {
				cout << "Your answer is wrong. The correct answer is: " << current_pointer->answer << endl;
			}
			cout << "Your total points: " << total_points << endl << endl;

			// Debugging '\n'
			//cout << user_answer << "    " << current_pointer->answer << endl;

			current_pointer = current_pointer->next;
		}
	}
	return 0;
}

void Unit_Test() {
	cout << "*** This is a debugging version ***\n";

	// Initialize trivia question list
	pointer_node node_list = new TriviaNode;
	init_question_list(node_list);

	cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
	ask_question(node_list, 0);
	cout << "Case 1 passed\n\n";

	cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
	ask_question(node_list,1);
	cout << "Case 2.1 passed\n\n";

	cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
	ask_question(node_list,1);
	cout << "Case 2.2 passed\n\n";

	cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
	ask_question(node_list,3);
	cout << "Case 3 passed\n\n";

	cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
	ask_question(node_list,5);
	cout << "Case 4 passed\n\n";

	cout << "*** End of the Debugging Version ***";
}








/*
// Contains functions and data members for the linked list
class Trivia {
	private: TriviaNode *head, *tail;

	public:
		Trivia()
		{
			head = NULL;
			tail = NULL;
		}

	void add_ques(string ques, string ans, int points) {
		// Create the new trivia node
		TriviaNode *tmp = new TriviaNode;
		tmp -> question = ques;
		tmp -> answer = ans;
		tmp -> quesPoints = points;
		tmp -> nextTriviaNode = NULL;

		// Add the node appropriately to the list
		if (head == NULL) {
			head = tmp;
			tail = tmp;
		} else {
			CP -> next = tmp;
			CP = CP -> next;
		}
	}
};
*/
