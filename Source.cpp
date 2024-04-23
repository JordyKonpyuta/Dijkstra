#include "Node.h"
#include "Source.h"

/*vector<Node*> Dijkstra(vector<Node*> tab, Node* sDeb, Node* sFin)
{
	Node* s1 = tab[0];
	Node* s2 = tab[1];
	int dist1 = 0;
	int dist2 = 0;
	vector<Node*> path;
	while (sDeb != sFin)
	{
		vector<pair<Node*, int>> n = sDeb->getNeighbors();
		for (int i = 0; i < n.size(); i++) {
			// ON GARDE LE CHEMIN LE PLUS COURT DANS S1
			if (n[i + 1].second > n[i].second) {
				s1 = n[i].first;
				dist1 = n[i].second;
			}
			// ON GARDE LE DEUXIEME CHEMIN LE PLUS COURT DANS S2
			else if (n[i].second < dist2) {
				s2 = n[i].first;
				dist2 = n[i].second;
			}

			// COMPARE LES DISTANCES
			vector<pair<Node*, int>> n1 = s1->getNeighbors();
			for (int j = 0; j < n1.size(); j++) {
				// SI LA DISTANCE ENTRE LE DEBUT + S1 + SON VOISIN EST PLUS LONGUE QUE LA DISTANCE ENTRE LE DEBUT ET S2
				if (n[j + 1].second > n[j].second) {
					// ON GARDE LA DISTANCE ENTRE LE DEBUT ET S2
					if (n1[j].second + dist1 > dist2) {
						path.emplace_back(s2);
						sDeb = s2;
					}
					// SINON ON UTILISE L'AUTRE DISTANCE
					else {
						path.emplace_back(s1);
						sDeb = s1;
					}

				}
			}

		}
	}
	cout << "Le chemin le plus court est ";
	for (Node* n : path) {
		cout << n->getName() << ", ";
	}
	return path;
}

vector<Node*> Dijkstrav2(vector<Node*> tab, Node* sDeb, Node* sFin) {

	vector<Node*> distances;
	distances.emplace_back(sDeb);

	while (tab.size() > 0) {
		int dist = 0;
		Node* begin = distances.begin();
		tab.erase(begin);

		for (auto& it : begin->getNeighbors()) {
			int s1 = begin->getNeighbors()[0].second;
			int s2 = begin->getNeighbors()[1].second;

			if (dist + s2 <= dist + s1) {
				distances.emplace_back(begin->getNeighbors()[1].first, s2);
				begin = begin->getNeighbors()[1].first;
				dist += s2;
			}

			else {
				distances.emplace_back(begin->getNeighbors()[0].first, s1);
				begin = begin->getNeighbors()[0].first;
				dist += s1;
			}
		}

		if (distances.end()->getName() = sFin->getName()) {
			break;
		}
	}

	return distances;
	cout << "Le chemin le plus court est ";
	for (Node* n : distances) {
		cout << n->getName() << ", ";
	}
} */

// FONCTION POUR AVOIR LE NOEUD LE PLUS PROCHE
Node* getNearestNode(vector<Node*> tab) {
	int nearestDistance = INT32_MAX;
	Node* nearestNode = nullptr;

	for (Node* n : tab) {
		// SI ON N'EST PAS DEJA PASSE PAR CE NOEUD ET QU'IL EST PLUS PROCHE
		if (!n->getIsVisited() && n->getMinDistance() < nearestDistance) {
			nearestDistance = n->getMinDistance();
			nearestNode = n;
		}

	}

	return nearestNode;
}

void Dijkstrav3(vector<Node*> tab, Node* begin, Node* end) {
	begin->setMinDistance(0);
	vector<Node*> predecessors;
	while (true) {
		Node* currentNode = getNearestNode(tab);
		if (currentNode == nullptr || currentNode == end) break;
		currentNode->setIsVisited(true);

		// POUR CHAQUE VOISIN, ON RECUPERE SON NODE ET SON POIDS
		for (pair<Node*, int> n : currentNode->getNeighbors()) {
			Node* neighborsNode = n.first;
			int weight = n.second;
			int distance = currentNode->getMinDistance() + weight;

			// ON PREND LE NOEUD LE PLUS PROCHE
			if (distance < neighborsNode->getMinDistance()) {
				// ON MET A JOUR LA DISTANCE QU'IL FAUT BATTRE ET ON SAUVEGARDE LE NOEUD PAR LEQUEL ON EST PASSE
				neighborsNode->setMinDistance(distance);
				neighborsNode->setPredecessor(currentNode);
			}
		}
	}
	// AFFICHAGE DE LA DISTANCE LA PLUS COURTE
	cout << "Le chemin le plus court de " << begin->getName() << " jusqu'a " << end->getName() << " est de " << end->getMinDistance() << endl;

	// AFFICHAGE DU CHEMIN LE PLUS COURT
	Node* path = end->getPredecessor();
	predecessors.push_back(path);
	// ON RECUPERE LE PREDECESSEUR DE L'ARRIVEE ET ON REMONTE JUSQU'AU DEPART
	while (path != begin) {
		path = path->getPredecessor();
		predecessors.insert(predecessors.begin(), path);
	}
	cout << "Chemin : ";
	for (Node* n : predecessors) cout << n->getName() << " -> ";
	cout << end->getName();
}


int main() {
	vector<Node*> graphe;

	Node A("A");
	Node B("B");
	Node C("C");
	Node D("D");
	Node E("E");
	Node F("F");
	Node G("G");
	Node H("H");
	Node I("I");
	Node J("J");

	A.addNeighbor(&B,85);
	A.addNeighbor(&C,217);
	A.addNeighbor(&E,173);

	B.addNeighbor(&F,80);

	C.addNeighbor(&G,186);
	C.addNeighbor(&H,103);

	D.addNeighbor(&H,183);

	E.addNeighbor(&J,502);

	F.addNeighbor(&I,250);

	H.addNeighbor(&J,167);

	I.addNeighbor(&J,84);

	graphe.emplace_back(&A);
	graphe.emplace_back(&B);
	graphe.emplace_back(&C);
	graphe.emplace_back(&D);
	graphe.emplace_back(&E);
	graphe.emplace_back(&F);
	graphe.emplace_back(&G);
	graphe.emplace_back(&H);
	graphe.emplace_back(&I);
	graphe.emplace_back(&J);

	for(Node* n : graphe)
	{
		n->showNeighbors();
		cout<<endl;
	}

	string debut;
	string fin;
	Node* Ndebut = graphe[0];
	Node* Nfin = graphe[0];

	cout << "Choisissez la node de depart" << endl;
	cin >> debut;
	cout << "Choisissez la node d'arrivee" << endl;
	cin >> fin;

	for (Node* n : graphe)
	{
		if (n->getName() == debut) Ndebut = n;
		else if (n->getName() == fin) Nfin = n;
	}

	Dijkstrav3(graphe, Ndebut, Nfin);
	
	return 0;
}