#include <iostream>
using namespace std;

struct tree{
	bool type;
	float number;
	char op;
	tree* left;
	tree* right;
};

tree* op(tree* tree1, tree* tree2){
	tree* t = new tree;
	t->type = false;
	t->number = 0;
	t->op = '+';
	t->left = tree1;
	t->right = tree2;
	return t;
}
tree* num(float n){
	tree* t = new tree;
	t->type = true;
	t->number = n;
	t->op = '\0';
	t->left = NULL;
	t->right = NULL;
	return t;
}
tree* DeleteLeft(tree* t){
	if(t->left == NULL) return NULL;
	tree* nt = t->left;
	t->left = NULL;
	return nt;
}
tree* DeleteRight(tree* t){
	if(t->right == NULL) return NULL;
	tree* nt = t->right;
	t->right = NULL;
	return nt;
}
float getResult(tree* t){
	if(t->type == true) return t->number;
	else{
		float leftValue = getResult(DeleteLeft(t));
		float rightValue = getResult(DeleteRight(t));
		switch (t->op){
			case '+': t->number = leftValue + rightValue; break; 
			case '-': t->number = leftValue - rightValue; break;
			case '*': t->number = leftValue * rightValue; break;
			case '/': t->number = leftValue / rightValue; break;
		}
		t->op = '\0';
		t->type = true;
		return t->number;
		}
}

int main(){
	tree* tree1 = num(1);
	tree* tree2 = num(2);
	tree* tree3 = num(3);
	tree* tree4 = num(4);
	tree* tree5 = op(tree1, tree2);
	tree* tree6 = op(tree3, tree4);
	tree* tree7 = op(tree5, tree6);
	cout << tree7->left->left->number << endl;
	cout << getResult(tree7) << endl;
	if (tree7->left == NULL){
		cout << "yeah" << endl;
	}
	


	


}
