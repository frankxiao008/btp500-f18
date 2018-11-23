#include <iostream>
#include "arrqueue.h"
template <typename T>
class AVL{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		int height_;  //height of the subtree with
		              //this node as root
		Node(const T& data){
			data_=data;
			left_=nullptr;
			right_=nullptr;
			height_=1;
		}
		void updateHeight(){
			int heightRight=height(right_);
			int heightLeft=height(left_);
			height_=(heightRight>heightLeft)?heightRight+1:heightLeft+1;
		}
	};
	int height(const Node* subtreeroot)const{
		return (subtreeroot)?subtreeroot->height_:0;
	}
	int balance(const Node* subtreeroot)const{
		return height(subtreeroot->right_)-height(subtreeroot->left_);
	}

	void leftRotate(Node*& Aptr){
		Node* Bptr=Aptr->right_;
		Node* Yptr=Bptr->left_;
		Bptr->left_=Aptr;
		Aptr->right_=Yptr;
		Aptr=Bptr;
	}
	void rightRotate(Node*& Aptr){
		Node* Bptr=Aptr->left_;
		Node* Yptr=Bptr->right_;
		Bptr->right_=Aptr;
		Aptr->left_=Yptr;
		Aptr=Bptr;
	}
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
			int nodeBalance=balance(subtreeroot);
			if(nodeBalance >=2){
				//fix with rotations
				int childBalance=balance(subtreeroot->right_);
				if(childBalance > 0){
					leftRotate(subtreeroot);
					subtreeroot->left_->updateHeight();
				}
				else{
					rightRotate(subtreeroot->right_);
					leftRotate(subtreeroot);
					subtreeroot->left_->updateHeight();
					subtreeroot->right_->updateHeight();
					//double
				}
			}
			else if (nodeBalance <= -2){
				int childBalance=balance(subtreeroot->left_);
				if(childBalance < 0){
					//single
				}
				else{
					//double
				}

			}
			//update height
			int heightRight=height(subtreeroot->right_);
			int heightLeft=height(subtreeroot->left_);
			subtreeroot->updateHeight();
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





