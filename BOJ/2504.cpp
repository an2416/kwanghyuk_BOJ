#include <iostream>
using namespace std;

char word[51];
int st[51];
int sp = 0;
int add = 0;
int result = 0;


void push(int input) {
	st[sp++] = input;
}

int pop() {
	return st[--sp];
}

bool isEmpty() {
	if (sp <= 0) {return true;}
	else {return false;}
}

void stack_debugging() {
	for (int i = 0; i <= sp; i++) {
		cout << st[i] << " ";
	}
	cout << endl;
}

void n_num() {
	int n_return = 0;
	while (1) {
		int tmp_n = pop();
		if (tmp_n == 40 || tmp_n == 91) {
			push(tmp_n);
			push(n_return);
			break;
		}
		else {
			n_return += tmp_n;
		}
	}
}

int main() {
	cin >> word;

	while (1) {
		if (word[add] == '\0' || word[add] == NULL) {
			break;
		}
		stack_debugging();
		if (word[add] == '(') {
			push('(');
		}
		else if (word[add] == '[') {
			push('[');
		}
		else if (word[add] == ')') {
			int tmp_char = pop();
			if (tmp_char == (int)'(') {
				result += 2;
				push(result*100);
			}
			else if (tmp_char != (int)'(' && tmp_char != (int)'[') {
				n_num();
				int nnnn = pop();
				int aa = pop();
				result = 2 * aa/100;
				push(result * 100);
			}
		}
		else if (word[add] == ']') {
			int tmp_char = pop();
			if (tmp_char == (int)'[') {
				result += 3;
				push(result * 100);
			}
			else if (tmp_char != (int)'(' && tmp_char != (int)'[') {
				n_num();
				int nnnn = pop();
				result = 3 * nnnn;
				push(result * 100);
			}
		}
		add++;
	}

	cout << result << endl;
	return 0;
}