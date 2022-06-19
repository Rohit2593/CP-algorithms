
struct Node {
	Node* links[26];
	bool flag = false;

	bool containsKey(char c) {
		return links[c - 'a'] != NULL;
	}

	void put(char c, Node* n) {
		links[c-'a'] = n;
	}

	Node* get(char c) {
		return links[c - 'a'];
	}
};

class Trie {
private:
	Node* root;
public:
	Trie() {
		root = new Node();
	}

	void addWord(string &s) {
		Node* n = root;
		for(int i = 0; i<s.size(); i++) {
			if(!n->containsKey(s[i]))
				n->put(s[i] , new Node());
			n = n->get(s[i]);
		}
		n->flag = true;
	}

	bool searchWord(string &s , bool searchingPrefix) {
		Node* n = root;
		for(int i = 0; i<s.size(); i++) {
			if(!n->containsKey(s[i]))
				return false;
			n = n->get(s[i]);
		}

		if(searchingPrefix)
			return true;
		return n->flag;
	}

} ;
