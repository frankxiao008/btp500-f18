#include <iostream>
#include "arrqueue.h"
template <typename T>
class AVL{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data,Node* left=nullptr, Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
		}
	};
	Node* root_;
	void insert(const T& data,Node*& subtreeroot){
		if(subtreeroot==nullptr){
			subtreeroot=new Node(data);
		}
		else{
			if(data < subtreeroot->data_){
				insert(data,subtreeroot->left_);
			}
			else{
				insert(data,subtreeroot->right_);
			}
		}

	}
	void printPreOrder(const Node* subtreeroot,int depth) const{
		if(subtreeroot){

			for(int i=0;i<depth;i++){
				std::cout<<"---" ;
			}
			std::cout << subtreeroot->data_ << std::endl;
			printPreOrder(subtreeroot->left_,depth+1);
			printPreOrder(subtreeroot->right_,depth+1);
		}
	}
	/* this function is passed the root of a tree (subtree)
	   It will print the tree from small to big*/
	void printInOrder(const Node* subtree){
		if(subtree!=nullptr){
			printInOrder(subtree->left_);
			std::cout << subtree->data_ << " ";
			printInOrder(subtree->right_);
		}
	}


public:
	AVL(){
		root_=nullptr;
	}
	void insertRecursive(const T& data){
		insert(data, root_);
	}
	void printPreOrder() const{
		printPreOrder(root_,0);
	}
	void printInOrder() const{
		printInOrder(root_);
	}
	void printBreadthFirst() const{
		Queue<Node*> nodes;
		if(root_){
			nodes.enqueue(root_);
		}
		while(!nodes.isEmpty()){
			Node* curr=nodes.front();
			nodes.dequeue();
			std::cout << curr->data_ << " ";
			if(curr->left_){
				nodes.enqueue(curr->left_);
			}
			if(curr->right_){
				nodes.enqueue(curr->right_);
			}
		}
	}
};





