const int MAX_NODES = 'z'-'a'+1;
struct node_t{
    node_t(bool t=false): terminal(t){
        memset(nodes, 0, sizeof(nodes));
    }
    void insert(const char* s){ 
        if(!*s) {
            terminal = true;
            return;
        }
        char c = *s - 'a';
        if (!nodes[c]) nodes[c] = new node_t;
        nodes[c]->insert(++s);
    }
    bool search(const char* s){
        if(!*s) return terminal;
        if ( *s == '.' ){
            for( auto n: nodes)
                if( n &&  n->search(s+1) ) 
                    return true;
        }
        else{
            char c = *s - 'a';
            if (!nodes[c]) return false;
            return nodes[c]->search(s+1);
        }
        return false;
    }
    node_t* nodes[MAX_NODES];
    bool terminal;
};

class WordDictionary {
public:
    WordDictionary(): root(true){
    }
    void addWord(string word) {
        root.insert(word.c_str());
    }
    bool search(string word) {
        return root.search(word.c_str());
    }
protected:
    node_t root;
};
