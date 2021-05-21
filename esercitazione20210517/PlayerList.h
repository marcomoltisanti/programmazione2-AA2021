#ifndef PLAYER_LIST_H
#define PLAYER_LIST_H

#include "list_dl.h"
#include "player.h"

class PlayerList : public ListDL<Player> {

	public:
	PlayerList() : ListDL<Player>(true) {}
	PlayerList(bool ascend) : ListDL<Player>(ascend) {}

	void deleteByScore(double score) {
		Player dummy;
		dummy.setScore(score);
		NodeDL<Player> *cur = this->head;
		while(cur != NULL) {
			if(cur->getValue() == dummy) { 
				cout << "Deleting player: " << *cur << endl; 
				this->deleteNode(cur);
			}
			cur = cur->getNext();
			
		}
	}


	void searchAndPrint(string cognome) {
		NodeDL<Player> *cur = head; 
		while(cur != NULL && cur->getValue().getCognome() != cognome) { 
			cur = cur->getNext();
		}
		if(!cur) {
			cout << "Player not found!" << endl;
			return;
		}
		cout << "Player found!" << endl;
		cout << *cur << endl;
		cout << "Players with equal score: " << endl;
		NodeDL<Player> *temp = head;
		while(temp != NULL) {
			if(temp != cur && *temp == *cur)
				cout << "\t" << *temp << endl;
			temp = temp->getNext();
		}
	}

};

#endif
