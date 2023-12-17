class node{
public:
	int rat;
	string foo;
	node(int r, string fo) {
		this->rat = r;
        this->foo = fo;
	}
};

class Compare {
public:
    bool operator()(node* a, node* b) {
        if (a->rat < b->rat) {
            return true;
        }
        else if (a->rat == b->rat && a->foo > b->foo) {
            return true;
        }
        return false;
    }
};
