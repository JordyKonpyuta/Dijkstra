#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node
{
private:
	string name;
	vector<pair<Node*,int>> neighbors;
	bool isVisited = false;
	Node* predecessor = nullptr;
	int minDistance = INT_MAX;

public:
	Node();
	Node(string);
	Node(string,const vector<pair<Node*,int>>&);
	Node(string,Node*,int);

	string getName()const;
	void setName(const string& n);
	
	vector<pair<Node*, int>> getNeighbors();
	
	void addNeighbor(Node*, int);
	void addNeighbor(vector<pair<Node*,int>>);
	
	void showNeighbors();

	void setIsVisited(bool v);
	bool getIsVisited();

	void setPredecessor(Node* p);
	Node* getPredecessor();

	void setMinDistance(int d);
	int getMinDistance();
};

