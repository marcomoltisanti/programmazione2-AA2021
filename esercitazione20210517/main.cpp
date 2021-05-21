#include "player.h"
#include "PlayerList.h"
static void load(ListDL<Player>& list, string filename) {
	ifstream ifs(filename, ifstream::in);
	string s;
	int i = 1;
	while(ifs.good()) {
		Player p; // = new Player;
		ifs >> p;
		cout << "Player loaded #" << i++ << ": " << p << endl;
		list.insert(p);
	}
	ifs.close();

}

static void print(const ListDL<Player> & list, bool ascend) {
	if(ascend) {
		cout << "STAMPA IN ORDINE ASCENDENTE" << endl;
		cout << list << endl;
	}
	else {
		NodeDL<Player> * current = list.getTail();
		cout << "STAMPA IN ORDINE DISCENDENTE" << endl;
		cout << "Lista di lunghezza " << list.getLength() << ", head = " << list.getHead() << ", tail = " << list.getTail() << endl;
		while ( current != NULL) {
			cout << "\t" << *current << endl;
			current = current->getPrev();
		}
	}
}

int main() {

	//ListDL<Player>  list;
	PlayerList list;
        load(list, "Punteggi.txt");
	print(list, false);
	print(list, true);
	list.searchAndPrint("BATTISTA");
	list.deleteByScore(220.0);
	cout << list << endl;
}
