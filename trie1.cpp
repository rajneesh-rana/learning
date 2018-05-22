#include <stdio.h>
#include<time.h>
#include<string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class algorithm{

public:
void solution(FILE *in,FILE *out);
};


static int M, K;

enum {
	max_length=200,
	max_iters=250000,

};


struct Node {
	Node(){ }
	void clear(){
	for(int n=0;n<26;n++)
		chlidren[n]=-1;
	count=0;
	}
	bool is_end() const { return count>0; }
	int chlidren[26];
	int count, temp;
};


struct Tree{
	Node *nodes;
	int count, longest, iters;

	Tree(int size){
		nodes=new Node[size];
		clear();
	}
	void clear(){
		nodes[0].clear();
		longest=0;
		count=1;
		iters=0;
	}

	void insert(const char* string, int length){
	
	int node_id=0;
	
	for(int i=0;i<length;i++){
		int id=string[i]-'a';
		int next_id=nodes[node_id].chlidren[id];
		if(next_id==-1){
			next_id=count++;
			nodes[next_id].clear();
			nodes[node_id].chlidren[id]=next_id;
		}
		node_id=next_id;
		
	}
	nodes[node_id].count++;
	longest=max(longest,length);

		for(int a=0;a<count;a++)
		{	
			for(int b=0;b<26;b++)
				printf(" %d ",nodes[a].chlidren[b]);
			printf("\n");
		}
		printf("\n\n");	

	}

	int find_longest(int *ptrs, int ptr_count, int length)
	{

		if(length == max_length)
			return max_length;
		if(iters++> max_iters)
			return length;
		
		int longest=length>0?length:-1;
		
		for(int s=0;s<M;s++){
			bool ok=true;
			int nptrs[22], nptr_count=0;	
		
		for(int p=0;p<ptr_count;p++){
			int next=nodes[ptrs[p]].chlidren[s];
			if(next ==-1)
				continue;
			
			if(nodes[next].is_end()){
				ok=false;
				break;
			}
			nptrs[nptr_count++]=next;
		}

		if(ok){
			int next0=nodes[0].chlidren[s];
			printf(" [%d  %d %d]",s,nptr_count,next0);
			if(next0 != -1)
			 nptrs[nptr_count++]=next0;
			longest=max(longest, find_longest(nptrs,nptr_count,length+1));
		}
		}
		
		return longest;
	}
};

void algorithm::solution(FILE *in, FILE *out){
	int cases;
	scanf("%d",&cases);
	printf("%d\n",cases);	
	Tree tree(100*1024*20);
	
	for(int c=0;c<cases;c++){
		
		tree.clear();
		
			char block[32];
			scanf("%s",block);
		 	printf("%s\n",block);
			tree.insert(block,strlen(block));
	
		scanf("%d ", &M);
#if 0	
		int result=tree.find_longest(NULL, 0,0);
		if(result==max_length)
			result=-1;
		fprintf(out,"Case #%d\n",c+1);
		fprintf(out,result==-1? "No\n" : "%d\n",result);
#endif 
	}
}

int main(){
	freopen("trie.txt","r",stdin);
	algorithm alg;
	alg.solution(stdin,stdout);
	return 0;
}
		

